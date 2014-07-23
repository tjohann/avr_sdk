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

#ifndef _LIBAVRLCD_PRIV_H_
#define _LIBAVRLCD_PRIV_H_

#include <libavrhelper.h>
#include "libavrlcd.h"
#include <avr/io.h>
#include <stdlib.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>


/*
 * LCD pining 
 * Note: see datasheet and/or
 *       http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung
 */
//  LCD DB4-DB7 <-->  PORTD Bit PD0-PD3
//#define LCD_PORT      PORTD
//#define LCD_DDR       DDRD
#define LCD_DB        PD0
//  LCD RS      <-->  PORTD Bit PD4     (RS: 1=Data, 0=Command)
#define LCD_RS        PD4
//  LCD EN      <-->  PORTD Bit PD5     (EN: 1-Impuls für Daten)
#define LCD_EN        PD5


#if USE_LCD == __YES__
#if LCD_COMMON_PORT == __PORT_A__
#define LCD_PORT PORTA
#ifdef DDRA
#define LCD_DDR DDRA
#else
# warning "DDRA not available"
#endif
#elif LCD_COMMON_PORT == __PORT_B__
#define LCD_PORT PORTB
#define LCD_DDR DDRB
#elif LCD_COMMON_PORT == __PORT_C__
#define LCD_PORT PORTC
#define LCD_DDR DDRC
#elif LCD_COMMON_PORT == __PORT_D__
#define LCD_PORT PORTD
#define LCD_DDR DDRD
#else
# error "LCD_COMMON_PORT not valid"
#endif
#else
# warning "USE_LCD == __NO__ -> use default values to satisfy build"
#define LCD_PORT PORTC
#define LCD_DDR DDRC
#endif

/*
 * LCD timing 
 *
 * Note: see datasheet and/or
 *       http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung
 */
#define LCD_BOOTUP_TIME 15


/*
 * lcd errno stuff
 *
 * Note: of course not reentrant 
 *       LCD_ERROR is the general switch
 *       LCD_ERRNO for adc_errno which holds lcd_error_t values 
 */
#ifdef LCD_ERROR 
#ifndef LCD_ERRNO
#define LCD_ERRNO
unsigned char lcd_errno = MY_OK;
#endif
#else
# warning "No special lcd error indication!"
#endif

/*
 * error string 
 */
unsigned char *lcd_error_string = (unsigned char *) "LCD_ERROR";

/*
 * -> macros for setting ....
 */




#endif
