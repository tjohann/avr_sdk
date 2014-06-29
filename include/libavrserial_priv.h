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

#ifndef _LIBAVRSERIAL_PRIV_H_
#define _LIBAVRSERIAL_PRIV_H_

#include <libavrhelper.h>
#include <libavrserial.h>
#include <avr/io.h>
#include <util/setbaud.h>

typedef enum serial_op_mode {
	ASYNC_NORMAL = 0x01,
	ASYNC_DOUBLE,
	SYNC_MASTER  // no double in sync
} serial_op_mode_t;


typedef enum serial_enable_rxtx {
	ENA_RX = 0x01,
	ENA_TX,
	ENA_ALL
} serial_enable_rxtx_t;


/*
 * -> init USART
 */
void 
serial_setup_usart(serial_op_mode_t op_mode,
		   serial_frame_type_t frame_type,
		   serial_enable_rxtx_t ena_rxtx);


#endif
