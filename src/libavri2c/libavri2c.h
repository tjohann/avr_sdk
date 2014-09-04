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

#ifndef _LIBAVRI2C_H_
#define _LIBAVRI2C_H_

#include <avr_compile_macros.h>


/*
 * i2c specific error codes
 */
typedef enum i2c_errors {
	I2C_UNKNOWN = 0x00
} i2c_errors_t;


/*
 * Baudrate
 */
typedef enum i2c_bit_rate {
        I2C_100KHz = 0x00,
	I2C_400KHz,
} i2c_bit_rate_t;


/*
 * i2c errno stuff
 *
 * HOTWO: use i2c_errno
 * -> a global variable is defined and set to default by 
 *    this lib -> unsigned char i2c_errno = MY_OK;
 * -> in YOUR header file add the folling declaration
 *    extern unsigned char i2c_errno; 
 * -> if something goes wrong, then the functions set i2c_errno to 
 *    an value of i2c_errors_t 
 * -> if everthing works fine, then i2c_errno is set to MY_OK (see libavrhelper.h)
 * -> for an example see template.* in src/template
 *
 * Note: of course not reentrant 
 *       I2C_ERROR is the general switch
 *       I2C_ERRNO for i2c_errno which holds i2c_error_t values 
 *       unsigned char * i2c_error_string = "I2C_ERROR" for a common error string
 * 
 */

#ifndef I2C_ERROR  
#define I2C_ERROR OFF  
#  warning "I2C_ERROR not defined, use OFF"
#endif


/*
 * ----------- functions for init/setup of the I2C -----------
 */

/*
 * -> setup i2c for master mode
 */
void 
i2c_setup_master_mode(i2c_bit_rate_t bit_rate);


/*
 * -> setup i2c for slave mode
 */
void 
i2c_setup_slave_mode(void);



#endif
