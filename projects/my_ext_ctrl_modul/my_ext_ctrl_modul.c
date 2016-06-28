/*
  my_ext_ctrl_modul - simple project with atmega32

  Copyright (C) 2014 Thorsten Johannvorderbrueggen <thorsten.johannvorderbrueggen@t-online.de>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "my_ext_ctrl_modul.h"


// my common state info
unsigned char state_of_modul = STATE_UNKNOWN;


/*
 * -> init my_ext_ctrl_modul hw
 */
void
init_modul(void)
{
	// init control led port
	SET_BIT(LED_DDR, LED_PIN);

	// init mode switch
	CLEAR_BIT(MODE_DDR, MODE_PIN);
	CLEAR_BIT(MODE_PORT, MODE_PIN);

	// init my_ext_ctrl_modul done
	state_of_modul |= STATE_MYMODUL_INIT_DONE;
}


/*
 * -> let the led blink on errors or send error_string to lcd
 *
 *    Note: DELAYTIME_ON_ERROR is 10. part of DELAYTIME
 */
void
error_indication(const unsigned char *error_string)
{
	if (state_of_modul & STATE_LCD_INIT_DONE) {
		if (error_string != NULL)
			lcd_send_string(error_string);
		else
			SET_BIT(LED_PORT, LED_PIN);
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
 * -> heartbeat led
 */
void
heartbeat_led(void)
{
	// led on
	SET_BIT(LED_PORT, LED_PIN);
	_delay_ms(DELAYTIME_HEART_ON);

	// led off
	CLEAR_BIT(LED_PORT, LED_PIN);
	_delay_ms(DELAYTIME_HEART_OFF);

	// led on
	SET_BIT(LED_PORT, LED_PIN);
	_delay_ms(DELAYTIME_HEART_ON);

	// led off
	CLEAR_BIT(LED_PORT, LED_PIN);
	_delay_ms(DELAYTIME);
}


/*
 * my_ext_ctrl_modul
 *
 This is a small module based on an atmega32 with lcd, 4 adc-read buttons and
 a i2c conntection. It should display informations from different moduls and
 let it access my_ext_ctrl_modul. To select wich modul is the source of info
 my_ext_ctrl_modul has a mode switch.

 usecase:
 |
 |  +--------------------------------+               +---------------------------+
 |  |                                |<---- I2C ---->|                           |
 |  | Temp-controller within pc case |               |     my_ext_ctrl_modul     |
 |  |                                |           +-->|                           |
 |  +--------------------------------+           |   +---------------------------+
 |                                               |       ||   ||     ||     ||
 |                                              I2C      ||   \/     ||     \/
 |                                               |       || (lm75-1) ||  Mode-swt
 |                                               |       ||          \/
 |                                               |       \/       LCD/8-bit
 |                                               |    adc-buttons
 |  +----------------+         +-------------+  I2C
 |  |                |         |             |   |
 |  | Linux-board/pc |<- USB ->|  usb<->i2c  |<--+
 |  |                |         |             |
 |  +----------------+         +-------------+
 |
 The temp-controller is a pid controller with 3 different fans for 2 climate zones.
 My_ext_ctrl_modul is the modul to display temps and fan speed and let
 me also set paramater for the pid controller.
 The Linux-board/pc is a normal pc or an embbedded devices which shows info of it
 on my_ext_ctrl_modul and also theres a access path available (e.g. halt/reboot)
 *
 */
int
__attribute__((OS_main)) main(void)
{
	const unsigned char adc_error_string[] = "ADC error occured";


	// ---------- lcd stuff ----------
	lcd_setup_display();
	if (lcd_errno != MY_OK)
		error_indication(NULL);


	// init lcd done ... send greetings to peer
	state_of_modul |= STATE_LCD_INIT_DONE;
	lcd_set_cursor_off();
	lcd_set_cursor(0, LCD_LINE_1);
	lcd_send_string((unsigned char *) "LCD init done");


	// ---------- adc stuff ----------
	adc_setup_adc(ADC_CH0);
	if (adc_errno != MY_OK)
		error_indication(adc_error_string);

	// init adc done
	state_of_modul |= STATE_ADC_INIT_DONE;
	lcd_set_cursor(0, LCD_LINE_2);
	lcd_send_string((unsigned char *) "ADC init done");

	/*
	 * TODO: i2c init
	 *       lm75 init
	 *       mode switch
	 */

	// ---------- init modul stuff ----------
	init_modul();
        lcd_set_cursor(0, LCD_LINE_3);
	lcd_send_string((unsigned char *) "Modul init done");

	// init done and everthing okay?
	if (state_of_modul == (STATE_ADC_INIT_DONE |
			       STATE_LCD_INIT_DONE |
			       STATE_MYMODUL_INIT_DONE)) {
		state_of_modul = STATE_OK;

		lcd_set_cursor(0, LCD_LINE_4);
		lcd_send_string((unsigned char *) "Init done");

		// clear display and co
		_delay_ms(2 * DELAYTIME);
		lcd_clear_display();
		lcd_set_cursor_on();
	} else
		state_of_modul = STATE_ERROR;

        /*
	 * ---------- main stuff below ----------
	 */
	while (1) {
		if (state_of_modul == STATE_ERROR) {
			// led on
			SET_BIT(LED_PORT, LED_PIN);
			_delay_ms(DELAYTIME_ON_ERROR);

			// led off
			CLEAR_BIT(LED_PORT, LED_PIN);
			_delay_ms(DELAYTIME_ON_ERROR);
		} else {

			/*
			 * my main loop
			 */
			lcd_set_cursor(0, LCD_LINE_1);
			lcd_send_string((unsigned char *) "Ready");

			// i am alive
			//heartbeat_led();

			if (MODE_INPUT_PORT & (1 << MODE_PIN)) {
				lcd_set_cursor(0, LCD_LINE_2);
				lcd_send_string((unsigned char *) "Mode not pressed");
				lcd_set_cursor(0, LCD_LINE_3);
				lcd_send_string((unsigned char *) "------------");
			} else {
				lcd_set_cursor(0, LCD_LINE_3);
				lcd_send_string((unsigned char *) "Mode pressed");
				heartbeat_led();
			}
		}
	}
}



