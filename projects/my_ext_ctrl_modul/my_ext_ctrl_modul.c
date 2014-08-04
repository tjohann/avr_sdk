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
 * -> STATE_INIT_DONE ... init finished
 * -> STATE_SERIAL_INIT_DONE ... init of serial finished -> used serial 
 *                               in error_indication 
 */
#define DELAYTIME 1000
#define DELAYTIME_ON_ERROR 100

// Note: incrising values ... do not change
#define STATE_UNKNOWN 0x00
#define STATE_OK 0x01
#define STATE_ERROR 0x02
#define STATE_SERIAL_INIT_DONE 0x04
#define STATE_LCD_INIT_DONE 0x08
#define STATE_INIT_DONE 0x10

// my common state info
unsigned char state_of_modul = STATE_UNKNOWN;


/*
 * -> init hw
 */
void 
init_modul(void) 
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
 * set LED on PB0 and clears it after DELAYTIME
 */
int 
__attribute__((OS_main)) main(void) 
{
	
	const unsigned char greeting_string[] = "hey: my_ext_ctrl_modul";
	const unsigned char error_string[] = "an error occured";
	unsigned char data_string[5];

	memset(data_string, 0, sizeof(data_string));


	/*
	 * ---------- lcd stuff ----------
	 *
	 */
	lcd_setup_display();
	if (lcd_errno != MY_OK)
		error_indication(error_string);

	// init lcd done ... send greetings to peer
	state_of_modul |= STATE_LCD_INIT_DONE;
	lcd_send_string(greeting_string);

	/*
	 * ---------- adc stuff ----------
	 */
	adc_setup_adc(ADC_CH0);
	// only temporary for learning
	ADCSRA |= (1 << ADSC);
	loop_until_bit_is_clear(ADCSRA, ADSC);
	uint16_t adcValue;
	adcValue = ADC;

	lcd_set_cursor(0, LCD_LINE_4);

	lcd_send_string("adcValue -> ");
	helper_convert_ushort_to_string(data_string, adcValue);
	lcd_send_string(data_string);

	if (lcd_errno == LCD_LINE_OVERFLOW) {
		lcd_set_cursor(5, LCD_LINE_3);
		lcd_send_character('!');
	}

	/*
	 * ---------- init modul stuff ----------
	 */
	// infrastructure is ready to use ... so my init is the next step 
	init_modul();


        /*
	 * ---------- main stuff below ----------
	 */
	_delay_ms(5 * DELAYTIME);
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

	while (1) {
		
		// led on
		SET_BIT(LED_PORT, LED_PIN);
		_delay_ms(DELAYTIME);
		
		// led off
		CLEAR_BIT(LED_PORT, LED_PIN);
		_delay_ms(DELAYTIME);
		
	}
}
