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

#ifndef _LIBAVRCYCLON_PRIV_H_
#define _LIBAVRCYCLON_PRIV_H_

#include <libavrhelper.h>
#include "libavrcyclon.h"
#include <avr/io.h>


#ifndef CYCLON_PORT
#  error "CYCLON_PORT not defined!"
#endif


//#if CYCLON_PORT==PORTB
//#define CYCLON_DDR=DDRA 
//#elif  CYCLON_PORT==PORTB
//#define CYCLON_DDR=DDRB
//#elif  CYCLON_PORT==PORTC
//#define CYCLON_DDR=DDRC
//#elif  CYCLON_PORT==PORTD
//#define CYCLON_DDR=DDRD
//#else
//#  error "CYCLON_PORT not valid!"
//#endif



#endif
