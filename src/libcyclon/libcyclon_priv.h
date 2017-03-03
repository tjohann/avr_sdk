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

#ifndef _LIBCYCLON_PRIV_H_
#define _LIBCYCLON_PRIV_H_

#include <libhelper.h>
#include "libcyclon.h"
#include <avr/io.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>


#if USE_CYCLON == __YES__
#if CYCLON_PORT == __PORT_A__
#define LEDS_PORT PORTA
#ifdef DDRA
#define LEDS_DDR DDRA
#else
# warning "DDRA not available"
#endif
#elif CYCLON_PORT == __PORT_B__
#define LEDS_PORT PORTB
#define LEDS_DDR DDRB
#elif CYCLON_PORT == __PORT_C__
#define LEDS_PORT PORTC
#define LEDS_DDR DDRC
#elif CYCLON_PORT == __PORT_D__
#define LEDS_PORT PORTD
#define LEDS_DDR DDRD
#else
# error "CYCLON_PORT not valid"
#endif
#endif


#endif
