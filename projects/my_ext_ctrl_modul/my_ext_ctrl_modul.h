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

#include <avr/io.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#include <string.h>

/*
 * -> my avr_sdk libs 
 */
#include <avr_compile_macros.h>
#include <libavrhelper.h>
#include <libavradc.h>
#include <libavrlcd.h>


// make shure that COMMUNICATION_PATH is available
#ifndef COMMUNICATION_PATH
#error "COMMUNICATION_PATH not defined"
#endif

/*
 * -> use adc_errno
 */
extern unsigned char adc_errno;


/*
 * -> use lcd_errno
 */
extern unsigned char lcd_errno;


/*
 * pins for control led 
 *
 */
#define LED_PIN PB0
#define LED_DDR DDRB
#define LED_PORT PORTB


