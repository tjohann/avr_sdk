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

#ifndef _LIBCAN_H_
#define _LIBCAN_H_

#include <avr_compile_macros.h>


/*
 * can specific error codes
 */
typedef enum can_errors {
	CAN_UNKNOWN = 0x00
} can_errors_t;


/*
 * can errno stuff
 *
 * HOTWO: use can_errno
 * -> a global variable is defined and set to default by
 *    this lib -> unsigned char can_errno = MY_OK;
 * -> in YOUR header file add the folling declaration
 *    extern unsigned char can_errno;
 * -> if something goes wrong, then the functions set can_errno to
 *    an value of can_errors_t
 * -> if everthing works fine, then can_errno is set to MY_OK (see libavrhelper.h)
 * -> for an example see template.* in src/template
 *
 * Note: of course not reentrant
 *       CAN_ERROR is the general switch
 *       CAN_ERRNO for can_errno which holds can_error_t values
 *       unsigned char * can_error_string = "CAN_ERROR" for a common error string
 *
 */

#ifndef CAN_ERROR
#define CAN_ERROR OFF
#  warning "CAN_ERROR not defined, use OFF"
#endif


/*
 * ----------- functions for init/setup of the CAN -----------
 */

/*
 * -> setup can
 */
void
can_setup_can(void);


#endif