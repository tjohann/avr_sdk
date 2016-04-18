/*
  libavri2c/libarmi2c - simple library as a handle of i2c stuff for small
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

#ifndef _LIBAVRI2C_PRIV_H_
#define _LIBAVRI2C_PRIV_H_

#include <libavrhelper.h>
#include "libavri2c.h"
#include <avr/io.h>
#include <stdlib.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#include <avr_defines_display.h>

/*
 * i2c errno stuff
 *
 * Note: of course not reentrant 
 *       I2C_ERROR is the general switch
 *       I2C_ERRNO for i2c_errno which holds i2c_error_t values 
 */
#ifdef I2C_ERROR 
#ifndef I2C_ERRNO
#define I2C_ERRNO
unsigned char i2c_errno = MY_OK;
#endif
#else
# warning "No special i2c error indication!"
#endif


/*
 * some defines for TWBR calculation
 */
#define TWBR_DENOMINATOR_100KHZ 200000UL 
#define TWBR_DENOMINATOR_400KHZ 800000UL


/*
 * error string 
 */
unsigned char *i2c_error_string = (unsigned char *) "I2C_ERROR";


/*
 * operation mode
 */
typedef enum i2c_op_mode {
	MASTER = 0x00,
	MULTI_MASTER,
	SLAVE
} i2c_op_mode_t;


/*
 * -> setup i2c 
 */
void 
i2c_setup_i2c(i2c_op_mode_t mode,
	      i2c_bit_rate_t bit_rate);


#endif
