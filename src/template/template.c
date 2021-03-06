/*
  GPL
  (c) 2014-2021, thorsten.johannvorderbrueggen@t-online.de

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
*/

#include "template.h"

/*
 * common defines
 *
 * -> DELAYTIME ... the normal blink time
 * -> DELAYTIME_ON_ERROR ... the blinking time to indicate an error
 *
 * -> STATE_UNKNOWN ... state of template is unknown
 * -> STATE_OK ... everthing is up and running
 * -> STATE_ERROR ... an error occured
 * -> STATE_INIT_DONE ... init finished
 * -> STATE_SERIAL_INIT_DONE ... init of serial finished -> used serial
 *                               in error_indication
 * -> ...
 */
#define DELAYTIME 1000
#define DELAYTIME_ON_ERROR 100

// Note: incrising values ... do not change
#define STATE_UNKNOWN 0x00
#define STATE_OK 0x01
#define STATE_ERROR 0x02
#define STATE_SERIAL_INIT_DONE 0x04
#define STATE_LCD_INIT_DONE 0x08
#define STATE_ADC_INIT_DONE 0x10
#define STATE_I2C_INIT_DONE 0x20
#define STATE_INIT_DONE 0x40

// my common state info
unsigned char state_of_template = STATE_UNKNOWN;


/*
 * -> init hw
 */
void
__attribute__((noinline)) init_template(void)
{
	// set ddr for led pin
	SET_BIT(LED_DDR, LED_PIN);
}


/*
 * -> let the led blink on errors or send error_string via serial
 */
void
error_indication(const unsigned char *error_string)
{
#if COMMUNICATION_PATH == __SERIAL__
	if (state_of_template & STATE_SERIAL_INIT_DONE) {
		if (error_string != NULL)
			serial_send_string(error_string);
		else
			SET_BIT(LED_PORT, LED_PIN);
#elif COMMUNICATION_PATH == __LCD__
	if (state_of_template & STATE_LCD_INIT_DONE) {
		if (error_string != NULL)
			lcd_send_string(error_string);
		else
			SET_BIT(LED_PORT, LED_PIN);
#endif
	} else {
		while (1) {
			SET_BIT(LED_PORT, LED_PIN);
			_delay_ms(DELAYTIME_ON_ERROR);

			CLEAR_BIT(LED_PORT, LED_PIN);
			_delay_ms(DELAYTIME_ON_ERROR);
		}
	}
}

/*
 * set LED on PB0 and clears it after DELAYTIME
 */
int
__attribute__((OS_main)) main(void)
{

#if COMMUNICATION_PATH == __SERIAL__
	const unsigned char greeting_string[] = "hello ... i'm an atmega168(pa)\n\r";
	const unsigned char error_string[] = "an error occured ... pls check\n\r";
	unsigned char byte = 0x31;
#elif COMMUNICATION_PATH == __LCD__
	const unsigned char greeting_string[] = "hello ... i'm an atmega32";
	const unsigned char error_string[] = "an error occured ... pls check";
	unsigned char data_string[5];

	memset(data_string, 0, sizeof(data_string));
#endif


	/*
	 * ---------- serial stuff ----------
	 *
	 * Note: dont use serial & lcd -> PIN conflict
	 */
#if USE_SERIAL == __YES__

#if COMMUNICATION_PATH == __SERIAL__
	// init serial and let the led blink with DELAYTIME_ON_ERROR ms
	serial_setup_async_normal_mode(DATA_8_STOP_1_NO_PARITY);
	if (serial_errno != MY_OK)
		error_indication(error_string);

	// init serial done ... send greetings to peer
	state_of_template |= STATE_SERIAL_INIT_DONE;
	serial_send_string(greeting_string);

	// get an char from peer and send it as ascii
	byte = serial_receive_byte();
	serial_send_byte(byte, SERIAL_SEND_ASCII);
#endif // COMMUNICATION_PATH

#endif

	/*
	 * ---------- lcd stuff ----------
	 *
	 * Note: dont use serial & lcd -> PIN conflict
	 */
#if USE_LCD == __YES__

#if COMMUNICATION_PATH == __LCD__
	lcd_setup_display();
	if (lcd_errno != MY_OK)
		error_indication(error_string);

	// init lcd done ... send greetings to peer
	state_of_template |= STATE_LCD_INIT_DONE;
	lcd_send_string(greeting_string);
#endif // COMMUNICATION_PATH

#endif

	/*
	 * ---------- adc stuff ----------
	 */
#if USE_ADC == __YES__
	adc_init_adc(ADC_CH0);
	if (adc_errno != MY_OK)
		error_indication(error_string);

	// only temporary for learning
	ADCSRA |= (1 << ADSC);
	loop_until_bit_is_clear(ADCSRA, ADSC);
	uint16_t adcValue;
	adcValue = ADC;

#if USE_SERIAL == __YES__
	serial_send_byte((adcValue >> 3), SERIAL_SEND_NORMAL);
#elif USE_LCD == __YES__
	lcd_set_cursor(0, LCD_LINE_4);

	lcd_send_string((unsigned char *) "adcValue -> ");
	helper_convert_ushort_to_string(data_string, adcValue);
	lcd_send_string(data_string);

	if (lcd_errno == LCD_LINE_OVERFLOW) {
		lcd_set_cursor(5, LCD_LINE_3);
		lcd_send_character('!');
	}
#endif

#endif

	/*
	 * ---------- i2c stuff ----------
	 */
#if USE_I2C == __YES__
	i2c_setup_master_mode(I2C_100KHz);
	if (i2c_errno != MY_OK)
		error_indication(error_string);
#endif

	/*
	 * ---------- init template stuff ----------
	 */
	// infrastructure is ready to use ... so my init is the next step
	init_template();

        /*
	 * ---------- main stuff below ----------
	 */
	_delay_ms(5 * DELAYTIME);
#if USE_LCD == __YES__
	lcd_set_cursor_to_home_pos();
	_delay_ms(5 * DELAYTIME);

	lcd_set_display_off();
	_delay_ms(5 * DELAYTIME);
	lcd_set_display_on();
	_delay_ms(5 * DELAYTIME);
	lcd_set_cursor_off();

	_delay_ms(5 * DELAYTIME);
	lcd_clear_display();
	_delay_ms(5 * DELAYTIME);
	lcd_set_cursor_on();
#endif

	while (1) {
		// led on
		SET_BIT(LED_PORT, LED_PIN);
		_delay_ms(DELAYTIME);

		// led off
		CLEAR_BIT(LED_PORT, LED_PIN);
		_delay_ms(DELAYTIME);
	}
}
