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

#ifndef _LIBSPI_H_
#define _LIBSPI_H_

#include <avr_compile_macros.h>


#ifndef F_CPU
#  error "Freq of CPU not defined!"
#endif


/*
 * spi specific error codes
 */
typedef enum spi_errors {
	SPI_INIT_DEFAULT = 0x00,
	SPI_UNKNOWN
} spi_errors_t;


/*
 * spi errno stuff
 *
 * HOTWO: use spi_errno
 * -> a global variable is defined and set to default by
 *    this lib -> unsigned char spi_errno = MY_OK;
 * -> in YOUR header file add the folling declaration
 *    extern unsigned char spi_errno;
 * -> if something goes wrong, then the functions set spi_errno to
 *    an value of spi_errors_t
 * -> if everthing works fine, then spi_errno is set to MY_OK (see libavrhelper.h)
 * -> for an example see template.* in src/template
 *
 * Note: of course not reentrant
 *       SPI_ERROR is the general switch
 *       SPI_ERRNO for spi_errno which holds spi_error_t values
 *       unsigned char *spi_error_string = "SPI_ERROR" for a common error string
 *
 */

#ifndef SPI_ERROR
#define SPI_ERROR OFF
#  warning "SPI_ERROR not defined, use OFF"
#endif


/*
 * ----------- functions for init/setup of the SPI -----------
 */



#endif
