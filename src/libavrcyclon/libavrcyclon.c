/*
  libavrcyclon -simple knight rider lib for small microcontroller (8 bit) 
 
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

#include "libavrcyclon.h"
#include "libavrcyclon_priv.h"


/*
 * -> do some init stuff 
 */
void
cyclon_setup_port(void)
{
	LEDS_DDR = 0xFF;
}

/*
 * -> cyclon eye function like knight rider or whatever you like
 */
void
cyclon_run(const unsigned short count, 
	   double delay_time)
{
	unsigned char i = 0x00;
	unsigned short act_count = 0x00;

	do {
		while (i < 7) {
			LEDS_PORT = (1 << i);                
			_delay_ms(delay_time);                              
			i++;                              
		}
		
		while (i > 0) {
			LEDS_PORT = (1 << i);                
			_delay_ms(delay_time);                                  
			i--;        
		}
		
		if (count != 0)
			act_count++;
		
	} while (act_count != count);
}
