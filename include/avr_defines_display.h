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
 * common defines for using a lcd display
 */
#if USE_LCD == __YES__


/*
 * LCD pining 
 *
 * Note: see datasheet and/or
 *       http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung
 *
 *       the pinning below is only a proposal for ATMega32
 */
#if LCD_COMMON_PORT == __PORT_A__
#define LCD_PORT PORTA
// only adc0 and adc 1 available
#ifdef DDRA
#define LCD_DDR DDRA
#else
# error "DDRA not available"
#endif
#define LCD_DB_FIRST_PIN PA4
#define LCD_RS_PIN PA2
#define LCD_EN_PIN PA3

#elif LCD_COMMON_PORT == __PORT_B__
// no sck -> use bs170 to disconnect if you program
#define LCD_PORT PORTB
#define LCD_DDR DDRB
#define LCD_DB_FIRST_PIN PB0
#define LCD_RS_PIN PB4
#define LCD_EN_PIN PB7

#elif LCD_COMMON_PORT == __PORT_C__
// my prefered port
#define LCD_PORT PORTC
#define LCD_DDR DDRC
#define LCD_DB_FIRST_PIN PC4
#define LCD_RS_PIN PC2
#define LCD_EN_PIN PC3

#elif LCD_COMMON_PORT == __PORT_D__
// no rx/tx 
#define LCD_PORT PORTD
#define LCD_DDR DDRD
#define LCD_DB_FIRST_PIN PD4
#define LCD_RS_PIN PD0
#define LCD_EN_PIN PD1

#else
# error "LCD_COMMON_PORT not valid"
#endif


#else // USE_LCD == __YES__
# warning "USE_DISPLAY == __NO__ -> do nothing"
#endif


/*
 * LCD timing 
 */
#define LCD_BOOTUP_TIME 15




#endif
