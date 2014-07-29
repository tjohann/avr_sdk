/*
  libavrlcd/libarmlcd - simple library as a handle of lcd stuff for small
                        microcontroller(avr) and cortex-m3(arm) devices
 
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

#include "libavrlcd.h"
#include "libavrlcd_priv.h"


/*
 * if you want to use LCD ... otherwise no code to to link
 */
#if USE_LCD == __YES__


/*
 * -> setup lcd
 */
void 
lcd_setup_display(void) 
{

/*
 * LCD SETUP FOR AVR
 */
#if CONTROLLER_FAMILY == __AVR__

	LCD_DDR |= 0xFF;	
	LCD_PORT &= ~0xFF;
	
	_delay_ms(LCD_BOOTUP_TIME);  // TODO: check that
	


#if LCD_ERROR == __ON__
	lcd_errno = LCD_INIT_DEFAULT;
#endif
	
#endif  // AVR


/*
 * ADC SETUP FOR ARM-CORTEX-M3
 */
#if CONTROLLER_FAMILY == __ARM__
	// fill me
#endif  // ARM

}

#else
# warning "USE_LCD == __NO__ -> dont try to use the functions "
#endif
