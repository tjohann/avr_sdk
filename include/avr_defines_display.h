/*
  GPL
  (c) 2014-2016, thorsten.johannvorderbrueggen@t-online.de

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

#ifndef _AVR_DEFINES_DISPLAY_H_
#define _AVR_DEFINES_DISPLAY_H_


/*
 * LCD pinning
 */
#if USE_LCD == __YES__
#if LCD_COMMON_PORT == __PORT_A__
#define LCD_PORT PORTA
#ifdef DDRA
#define LCD_DDR DDRA
#else
# error "DDRA not available"
#endif
#elif LCD_COMMON_PORT == __PORT_B__
#define LCD_PORT PORTB
#define LCD_DDR DDRB
#elif LCD_COMMON_PORT == __PORT_C__
# error "PORT_C not valid -> RS=PC2 ... EN=PC3"
#elif LCD_COMMON_PORT == __PORT_D__
#define LCD_PORT PORTD
#define LCD_DDR DDRD
#else
# warning "LCD_COMMON_PORT not defined"
#endif
#endif

// ctrl pins
#define LCD_RS_PIN PC2
#define LCD_EN_PIN PC3
#define LCD_CTRL_PORT PORTC
#define LCD_CTRL_DDR DDRC


/*
 * LCD specific data
 */
// lcd_size
#define LCD_NUMBER_OF_LINES 4
#define LCD_NUMBER_OF_ROWS 20

// address of lines -> see datasheet
#define LCD_ADDR_LINE1         0x00
#define LCD_ADDR_LINE2         0x40
#define LCD_ADDR_LINE3         0x14
#define LCD_ADDR_LINE4         0x54


#else // USE_LCD == __YES__
# warning "USE_DISPLAY == __NO__ -> do nothing"
#endif



