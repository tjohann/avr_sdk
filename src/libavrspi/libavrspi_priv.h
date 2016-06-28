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

#ifndef _LIBAVRSPI_PRIV_H_
#define _LIBAVRSPI_PRIV_H_

#include <libavrhelper.h>
#include "libavrspi.h"
#include <avr/io.h>
#include <stdlib.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#include <avr_defines_display.h>

/*
 * spi errno stuff
 *
 * Note: of course not reentrant
 *       SPI_ERROR is the general switch
 *       SPI_ERRNO for spi_errno which holds spi_error_t values
 */
#ifdef SPI_ERROR
#ifndef SPI_ERRNO
#define SPI_ERRNO
unsigned char spi_errno = MY_OK;
#endif
#else
# warning "No special spi error indication!"
#endif


/*
 * error string
 */
unsigned char *spi_error_string = (unsigned char *) "SPI_ERROR";


/*
 * -> setup spi
 */
void
spi_setup_spi(void);


#endif
