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

#include <avr/io.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

/*
 * -> my avr_sdk libs 
 */
#include <avr_compile_macros.h>
#include <libavrhelper.h>
#include <libavrserial.h>
#include <libavrcyclon.h>


/*
 * -> use serial_errno
 */
extern unsigned char serial_errno;


/*
 * special pins for blinking ...
 *
 * Note: you could also use __PORT_B__ ... see libcyclon
 */
#define LED_PIN PB0
#define LED_DDR DDRB
#define LED_PORT PORTB


