/*
  avr_defines_display.h - some common defines for lcd usage 
 
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

#ifndef _AVR_DEFINES_DISPLAY_H_
#define _AVR_DEFINES_DISPLAY_H_   


/*
 * LCD pinning 
 *
 */
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
# error "LCD_COMMON_PORT not valid"
#endif

// ctrl pins
#define LCD_RS_PIN PC2
#define LCD_EN_PIN PC3
#define LCD_CTRL_PORT PORTC
#define LCD_CTRL_DDR DDRC


#else // USE_LCD == __YES__
# warning "USE_DISPLAY == __NO__ -> do nothing"
#endif



