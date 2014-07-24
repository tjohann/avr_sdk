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
 * -> setup lcd
 */
void 
lcd_setup_display(void) 
{
	unsigned char pins = 0x00;

/*
 * LCD SETUP FOR AVR
 *
 * Note: heavily inspired by 
 *       http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung
 */
#if CONTROLLER_FAMILY == __AVR__
        // which pins are used?
	pins = (0x0F << LCD_DB_FIRST_PIN) | (1<<LCD_RS_PIN) | (1<<LCD_EN_PIN);
	LCD_DDR |= pins;
	
	// clear all pins 
	LCD_PORT &= ~pins;
	
	_delay_ms(LCD_BOOTUP_TIME);  // TODO: check that
	
	// Soft-Reset muss 3mal hintereinander gesendet werden zur Initialisierung
	//lcd_out( LCD_SOFT_RESET );
	//_delay_ms( LCD_SOFT_RESET_MS1 );
	
	//lcd_enable();
	//_delay_ms( LCD_SOFT_RESET_MS2 );
	
	//lcd_enable();
	//_delay_ms( LCD_SOFT_RESET_MS3 );
	
	// 4-bit Modus aktivieren 
	//lcd_out( LCD_SET_FUNCTION |
	//	 LCD_FUNCTION_4BIT );
	//_delay_ms( LCD_SET_4BITMODE_MS );
	
	// 4-bit Modus / 2 Zeilen / 5x7
	//lcd_command( LCD_SET_FUNCTION |
	//	     LCD_FUNCTION_4BIT |
	//	     LCD_FUNCTION_2LINE |
	//	     LCD_FUNCTION_5X7 );
	
	// Display ein / Cursor aus / Blinken aus
	//lcd_command( LCD_SET_DISPLAY |
	//	     LCD_DISPLAY_ON |
	//	     LCD_CURSOR_OFF |
	//	     LCD_BLINKING_OFF); 
	
	// Cursor inkrement / kein Scrollen
	//lcd_command( LCD_SET_ENTRY |
	//	     LCD_ENTRY_INCREASE |
	//	     LCD_ENTRY_NOSHIFT );
	
	//lcd_clear();
	





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

