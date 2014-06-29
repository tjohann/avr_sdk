/*
  template - simple template for using my avr_sdk and libs for small 
             microcontroller (8 bit) 
 
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

#include "template.h"

/*
 * common defines
 */
#define DELAYTIME 200


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
 * set LED on PB0 and clears it after DELAYTIME
 */
int 
__attribute__((OS_main)) main(void) 
{

	init_template();
	
	serial_setup_async_normal_mode(DATA_8_STOP_1_NO_PARITY);


	/*
	 * -> usage of dummy functions
	 */
	helper_dummy();
	cyclon_dummy();

	while (1) {
		
		// send string led on
		SET_BIT(LED_PORT, LED_PIN);
		_delay_ms(DELAYTIME);
		
		// send string led off
		CLEAR_BIT(LED_PORT, LED_PIN);
		_delay_ms(DELAYTIME);
		
	}
}
