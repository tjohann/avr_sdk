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
		UCSR0A &= ~(1 << U2X0); // disable U2Xn

		break;
	case ASYNC_DOUBLE:
		UCSR0A &= ~(1 << U2X0); // disable U2Xn
		break;
	case SYNC_MASTER:

		/*
		 * -> TODO: fill me ...
		 */

		break;
	case SYNC_SLAVE:

		/*
		 * -> TODO: fill me ...
		 */

		break;
	default:
		// ASYNC_NORMAL
		UCSR0A &= ~(1 << U2X0); // disable U2Xn
	}

	// enable or disable RX/TX 
	switch (ena_rxtx) {
	case ENA_ALL:
		UCSR0B = (1 << TXEN0) | (1 << RXEN0);
		break;
	case ENA_RX:
		UCSR0B = (1 << RXEN0);
		UCSR0B &= ~(1 << TXEN0);
		break;
	case ENA_TX:
		UCSR0B = (1 << TXEN0);
		UCSR0B &= ~(1 << RXEN0);
		break;
	default:
		// enable TX and RX
		UCSR0B = (1 << TXEN0) | (1 << RXEN0);
	}
#endif

/*
 * SERIAL SETUP FOR ARM-CORTEX-M3
 */
#if CONTROLLER_FAMILY == ARM
	// ARM stuff
#endif

}


