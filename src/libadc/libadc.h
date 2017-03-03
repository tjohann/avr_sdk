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

#ifndef _LIBADC_H_
#define _LIBADC_H_

#include <avr_compile_macros.h>
#include <libhelper.h>


#ifndef F_CPU
#  error "Freq of CPU not defined!"
#endif


/*
 * adc specific error codes
 */
typedef enum {
	ADC_INIT_DEFAULT = 0x00,
	ADC_UNKNOWN
} adc_errors_t;

/*
 * enum for adc channel
 */
typedef enum {
	ADC_CH0 = 0x00,
	ADC_CH1
} adc_channels_t;


/*
 * adc errno stuff
 *
 * HOTWO: use adc_errno
 * -> a global variable is defined and set to default by
 *    this lib -> unsigned char adc_errno = MY_OK;
 * -> in YOUR header file add the folling declaration
 *    extern unsigned char adc_errno;
 * -> if something goes wrong, then the functions set adc_errno to
 *    an value of adc_errors_t
 * -> if everthing works fine, then adc_errno is set to MY_OK (see libavrhelper.h)
 * -> for an example see template.* in src/template
 *
 * Note: of course not reentrant
 *       ADC_ERROR is the general switch
 *       ADC_ERRNO for adc_errno which holds adc_error_t values
 *       unsigned char * adc_error_string = "ADC_ERROR" for a common error string
 *
 */

#ifndef ADC_ERROR
#define ADC_ERROR OFF
#  warning "ADC_ERROR not defined, use OFF"
#endif

/*
 * ----------- functions for init of ADC -----------
 */

/*
 * -> init adc
 */
void
adc_init_adc(unsigned char adc_channel);

#endif
