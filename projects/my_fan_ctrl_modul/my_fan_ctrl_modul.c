/*
  my_fan_ctrl_modul - simple project with atmega168(pa)

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

#include "my_fan_ctrl_modul.h"

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
#define STATE_SERIAL_INIT_DONE 0x04
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
	if (state_of_modul & STATE_SERIAL_INIT_DONE) {
		if (error_string != NULL)
			serial_send_string(error_string);
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
 * my_fan_ctrl_modul
 *
 This is a small module based on an atmega168(pa) with serial, 2 fan outputs,
 2 lm75 for temperature measurment and 3 adc channels for measuring the fan speed.
 The third fan is only switched on/off if needed.
 |
 | usecase:
 |
 |                   +--------------------------------+           +-------------------+
 |                   |                                |           |                   |
 |                   |       my_fan_ctrl_modul        |<-- I2C -->| my_ext_ctrl_modul |
 |                   |                                |           |                   |
 |                   +--------------------------------+           +-------------------+
 |                     ||     ||    ||    ||       ||
 |                     ||     ||    \/    ||       \/
 |                     \/     ||  serial  ||    adc1/2-fan
 |                 PWM-Fan2/3 ||          \/
 |                            \/       swt Fan1
 |                         lm75-1/2
 |
 *
 */
int
__attribute__((OS_main)) main(void)
{
	const unsigned char adc_error_string[] = "ADC error occured";

	/*
	 * ---------- serial stuff ----------
	 */
	serial_setup_async_normal_mode(DATA_8_STOP_1_NO_PARITY);
	if (serial_errno != MY_OK)
		error_indication(NULL);

	// init serial done ... send greetings to peer
	state_of_modul |= STATE_SERIAL_INIT_DONE;
	serial_send_string((unsigned char *) "SERIAL init done");


	// ---------- adc stuff ----------
	adc_setup_adc(ADC_CH0);
	if (adc_errno != MY_OK)
		error_indication(adc_error_string);

	// init adc done
	state_of_modul |= STATE_ADC_INIT_DONE;
	serial_send_string((unsigned char *) "ADC init done");

	/*
	 * TODO: i2c init
	 *       lm75 init
	 *       adc for channel 2
	 *       pwm fan1/2
	 *       mode switch
	 *       on/off switch fan3
	 */

	// ---------- init modul stuff ----------
	init_modul();
	serial_send_string((unsigned char *) "Modul init done");


	// init done and everthing okay?
	if (state_of_modul == (STATE_ADC_INIT_DONE |
			       STATE_SERIAL_INIT_DONE |
			       STATE_MYMODUL_INIT_DONE)) {
		state_of_modul = STATE_OK;
		serial_send_string((unsigned char *) "Init done");
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
