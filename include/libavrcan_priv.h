/*
  libavrcan/libarmcan - simple library as a handle of can stuff for small
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

#ifndef _LIBAVRCAN_PRIV_H_
#define _LIBAVRCAN_PRIV_H_

#include <libavrhelper.h>
#include "libavrcan.h"
#include <avr/io.h>
#include <stdlib.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#include <avr_defines_display.h>

/*
 * can errno stuff
 *
 * Note: of course not reentrant 
 *       CAN_ERROR is the general switch
 *       CAN_ERRNO for can_errno which holds can_error_t values 
 */
#ifdef CAN_ERROR 
#ifndef CAN_ERRNO
#define CAN_ERRNO
unsigned char can_errno = MY_OK;
#endif
#else
# warning "No special can error indication!"
#endif

/*
 * error string 
 */
unsigned char *can_error_string = (unsigned char *) "CAN_ERROR";


#endif
