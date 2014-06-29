/*
  libavrserial - simple library as a handle for serial communication for small
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

#ifndef _LIBAVRSERIAL_H_
#define _LIBAVRSERIAL_H_

#include <libavrhelper.h>

#ifndef BAUD              
#define BAUD  9600   // my default value
#  warning "Baud rate not defined use 9600"
#endif

#ifndef F_CPU
#  error "Freq of CPU not defined!"
#endif


/*
 * HOWTO: configuration of the USART0 
 *
 * -> function serial_setup_asyn_normal_mode for normal mode ...
 * -> function serial_setup_asyn_double_speed for async mode with double speed ...
 *    enabled via U2xn=1
 * -> serial_setup_sync_master for sync master mode
 *
 * Note: baudrate via #define BAUD 9600 if not via -DBAUD=115200
 *       frame mode (example: 8 databit, 1 stop bit, no parity) via serial_frame_type_t
 */
typedef enum serial_frame_type {
        DATA_8_STOP_1_NO_PARITY = 0x01
} serial_frame_type_t;


/*
 * ****** functions for init/setup of USART ******
 */

/*
 * -> setup USART0 for async mode at normal speed ... U2Xn=0
 *
 * contraints: enable rx and tx
 */
void 
serial_setup_async_normal_mode(serial_frame_type_t frame_type);

/*
 * -> setup USART0 for async mode at double speed ... U2Xn=1
 *
 * contraints: enable rx and tx
 */
void 
serial_setup_async_double_speed(serial_frame_type_t frame_type);

/*
 * -> setup USART0 for sync master mode
 */
void 
serial_setup_sync_master(serial_frame_type_t frame_type);


/*
 * ****** functions for reading from USART *******
 */


/*
 * ****** functions for writing from USART *******
 */


#endif
