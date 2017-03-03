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

#ifndef _LIBADC_PRIV_H_
#define _LIBADC_PRIV_H_

#include <libhelper.h>
#include "libadc.h"
#include <avr/io.h>
#include <stdlib.h>


/*
 * adc errno stuff
 *
 * Note: of course not reentrant
 *       ADC_ERROR is the general switch
 *       ADC_ERRNO for adc_errno which holds adc_error_t values
 */
#ifdef ADC_ERROR
#ifndef ADC_ERRNO
#define ADC_ERRNO
unsigned char adc_errno = MY_OK;
#endif
#else
# warning "No special adc error indication!"
#endif

/*
 * error string
 */
unsigned char *adc_error_string = (unsigned char *) "ADC_ERROR";

/*
 * -> macros for setting ....
 */




#endif
