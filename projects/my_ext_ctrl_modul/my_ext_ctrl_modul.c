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

/*
 * common defines
 * 
 * -> DELAYTIME ... the normal blink time
 * -> DELAYTIME_ON_ERROR ... the blinking time to indicate an error
 *
 * -> STATE_UNKNOWN ... state of template is unknown 
 * -> STATE_OK ... everthing is up and running
 * -> STATE_ERROR ... an error occured
 * -> ...
 *
 */
#define DELAYTIME 1000
#define DELAYTIME_ON_ERROR DELAYTIME/100

// Note: incrising values ... do not change
#define STATE_UNKNOWN 0x00
#define STATE_OK 0x01
#define STATE_ERROR 0x02
#define STATE_LCD_INIT_DONE 0x04
#define STATE_ADC_INIT_DONE 0x08
#define STATE_MYMODUL_INIT_DONE 0x10

// my common state info
unsigned char state_of_modul = STATE_UNKNOWN;


/*
 * -> init my_ext_ctrl_modul hw
 */
void 
init_modul(void) 
{
	// init controll led port
	SET_BIT(LED_DDR, LED_PIN);  

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
		lcd_send_string(error_string); 
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
 * my_ext_ctrl_modul
 *
 This is a small module based on an atmega32 with lcd, 4 adc-read buttons and
 a i2c conntection. It should display informations from a master modul and 
 let it controll within my_ext_ctrl_modul.
 
 usecase:
 
 +--------------------------------+           +-------------------+
 |                                |           |                   | 
 | Temp-controller within pc case |<-- I2C -->| my_ext_ctrl_modul |  
 |                                |           |                   |
 +--------------------------------+           +-------------------+
 
 The temp-controller is a pid controller with 3 different fans for 2 climate zones.
 My_ext_ctrl_modul is the modul to display temps and fan speed and let
 me also set paramater for the pid controller.
 * 
 */
int 
__attribute__((OS_main)) main(void) 
{
	const unsigned char lcd_error_string[] = "LCD error occured";
	const unsigned char adc_error_string[] = "ADC error occured";


	// ---------- lcd stuff ----------
	lcd_setup_display();
	if (lcd_errno != MY_OK)
		error_indication(lcd_error_string);


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


	// ---------- init modul stuff ----------
	init_modul();
        lcd_set_cursor(0, LCD_LINE_3);
	lcd_send_string((unsigned char *) "my_ext_ctrl_modul init done");


        // clear display and co
	_delay_ms(5 * DELAYTIME);
	lcd_clear_display();
	lcd_set_cursor_on();

	// init done and everthing okay?
	if (state_of_modul == (STATE_ADC_INIT_DONE | 
			       STATE_LCD_INIT_DONE | 
			       STATE_MYMODUL_INIT_DONE)) {
		state_of_modul = STATE_OK;

		// clear display and co
		_delay_ms(5 * DELAYTIME);
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

			// led on
			SET_BIT(LED_PORT, LED_PIN);
			_delay_ms(DELAYTIME);
			
			// led off
			CLEAR_BIT(LED_PORT, LED_PIN);
			_delay_ms(DELAYTIME);
		}
	}
}
