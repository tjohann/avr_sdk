/*
  libavrspi/libarmspi - simple library as a handle of spi stuff for small
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

#include "libavrspi.h"
#include "libavrspi_priv.h"


/*
 * if you want to use SPI ... otherwise no code to to link
 */
#if USE_SPI == __YES__


/*
 * -> enable spi 
 *
 *  spi_errno: SPI_INIT_DEFAULT
 */
void 
spi_setup_spi() 
{

/*
 * SPI SETUP FOR AVR
 */
#if CONTROLLER_FAMILY == __AVR__
	// fill me
#endif  // AVR


/*
 * I2C SETUP FOR ARM-CORTEX-M3
 */
#if CONTROLLER_FAMILY == __ARM__
	// fill me
#endif  // ARM

}


#else
# warning "USE_SPI == __NO__ -> dont try to use the functions "
#endif
