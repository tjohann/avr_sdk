/*
 * libavrserial -> handle serial communication
 *
 * file: libavrserial.c & libavrserial.h & libavrserial_priv.h
 *
 */

#include "libavrserial.h"
#include "libavrserial_priv.h"



/*
 * -> setup USART0 for async mode at normal speed ... U2Xn=0
 */
void 
serial_setup_async_normal_mode(serial_frame_type_t frame_type)
{
	serial_setup_usart(ASYNC_NORMAL,
			   frame_type,
			   ENA_ALL);
}

/*
 * -> setup USART0 for async mode at double speed ... U2Xn=1
 *
 * contraints: enable rx and tx
 */
void 
serial_setup_async_double_speed(serial_frame_type_t frame_type)
{
	serial_setup_usart(ASYNC_DOUBLE,
			   frame_type,
			   ENA_ALL);
}

/*
 * -> setup USART0 for sync master mode
 *
 * contraints: enable rx and tx
 */
void 
serial_setup_sync_master(serial_frame_type_t frame_type)
{
       	serial_setup_usart(SYNC_MASTER,
			   frame_type,
			   ENA_ALL);
}


/*
 * -> setup USART0 for sync slave mode
 *
 * contraints: enable rx and tx
 */
void 
serial_setup_sync_slave(serial_frame_type_t frame_type)
{
       	serial_setup_usart(SYNC_SLAVE,
			   frame_type,
			   ENA_ALL);
}



/*
 * ************** private functions **************
 */

/*
 * -> init USART
 */
void 
serial_setup_usart(serial_op_mode_t op_mode,
		   serial_frame_type_t frame_type,
		   serial_enable_rxtx_t ena_rxtx) 
{

/*
 * SERIAL SETUP FOR AVR
 */
#if CONTROLLER_FAMILY == AVR
	/*
	 * For baudmode see:
	 *
	 * util_setbaud <util/setbaud.h>: Helper macros for baud rate calculations
	 * #define F_CPU=1000000
	 * #define BAUD 9600
	 * -> include <util/setbaud.h>
	 * UBRR0H = UBRRH_VALUE;                      
	 * UBRR0L = UBRRL_VALUE; 
	 */
	UBRR0H = UBRRH_VALUE;                       
	UBRR0L = UBRRL_VALUE;

	// set needed values in 
	switch (op_mode) {
	case ASYNC_NORMAL:
		SERIAL_SET_ASYNC_MODE();	
		SERIAL_DIS_DOUBLE_SPEED();
		break;
	case ASYNC_DOUBLE:
		SERIAL_SET_ASYNC_MODE();	
		SERIAL_ENA_DOUBLE_SPEED();
		break;
	case SYNC_MASTER:
		SERIAL_SET_SYNC_MODE();	
		/*
		 * -> TODO: fill me ...
		 */
		break;
	case SYNC_SLAVE:
		SERIAL_SET_SYNC_MODE();	
		/*
		 * -> TODO: fill me ...
		 */
		break;
	case MASTER_SPI:
		/*
		 * -> TODO: fill me ...
		 */
		break;
	default:
		// ASYNC_NORMAL
		SERIAL_DIS_DOUBLE_SPEED();
	}

	switch (frame_type) {
	case DATA_8_STOP_1_NO_PARITY:
		SERIAL_SET_8_DATA_BITS();
		SERIAL_SET_1_STOP_BIT();
		SERIAL_SET_NO_PARITY();
		break;
	default:
		// DATA_8_STOP_1_NO_PARITY
		SERIAL_SET_8_DATA_BITS();
		SERIAL_SET_1_STOP_BIT();
		SERIAL_SET_NO_PARITY();
	}


	// enable or disable RX/TX 
	switch (ena_rxtx) {
	case ENA_ALL:
		SERIAL_ENA_ALL();
		break;
	case ENA_RX:
		SERIAL_DIS_TX();
		SERIAL_ENA_RX();
		break;
	case ENA_TX:
		SERIAL_DIS_RX();
		SERIAL_ENA_TX();	
		break;
	default:
		// enable TX and RX
		SERIAL_ENA_ALL();
	}
#endif  // AVR

/*
 * SERIAL SETUP FOR ARM-CORTEX-M3
 */
#if CONTROLLER_FAMILY == ARM
	// fill me
#endif  // ARM

}


/*
 * -> send data (polling)
 */
void 
serial_send_data(unsigned short data) 
{
	unsigned char send_data = 0x00;

/*
 * SEND_DATA FOR AVR
 */
#if CONTROLLER_FAMILY == AVR
	/*
	 * Check if UDRE0 (Data Register Empty) is set, 
	 * otherwise wait ... and wait ... 
	 *
	 * Note: 9 bit mode uses TXB8n for the 9. bit
	 */
	while (!(UCSR0A & (1 << UDRE0)))
		;

	if ((UCSR0B >> UCSZ02) & 1) { // 9 bit mode
		if (data & 0x0100)
			UCSR0B |= (1 << TXB80);
		else 
			UCSR0B &= ~(1 << TXB80);
        } 
		
	send_data = (0xFF) & data;
	UDR0 = send_data;   // will change state of send fifo       
	
#endif  // AVR

/*
 * SEND_DATA FOR ARM-CORTEX-M3
 */
#if CONTROLLER_FAMILY == ARM
	// fill me
#endif  // ARM

}


/*
 * -> receive data (polling)
 */
unsigned short 
serial_receive_data(void) 
{
	unsigned short received_data = 0x0000;
	unsigned char data = 0x00, ninth_bit = 0x00; 
	unsigned char state_bits = 0x00, state = 0x00;

/*
 * RECEIVE_DATA FOR AVR
 */
#if CONTROLLER_FAMILY == AVR
	/*
	 * Check if RXC0 (Receive Complete Flag) is set, 
	 * otherwise wait ... and wait ... 
	 *
	 * Note: 9 bit mode uses RXB8n for the 9. bit
	 */
	while (!(UCSR0A & (1 << RXC0)))
		;

	/*
	 * addtional state bits 
	 *
	 * -> FEn Frame Error
	 * -> DORn Data OverRun
	 * -> UPEn USART Paraty Error
	 */
	state_bits = (1 << FE0) | (1 << DOR0) | (1 << UPE0);

	/*
	 * Note: the order is important 
	 */
	state = UCSR0A;
	ninth_bit = (UCSR0B >> RXB80) & 1;
	data = UDR0; // will change state of receive fifo

	if (state & state_bits) {
#if SERIAL_ERROR == ON	 
		// error HANDLING

		// set error to SERIAL_RCV_ERROR
#endif		
		received_data = 0x00;
	} else {
		
		// set error to MY_OK
		received_data = (ninth_bit << 8) | data;
	}
       


#endif  // AVR




/*
 * RECEIVE_DATA FOR ARM-CORTEX-M3
 */
#if CONTROLLER_FAMILY == ARM
	// fill me
#endif  // ARM

	return received_data;
}

