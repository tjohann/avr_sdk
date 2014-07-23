/*
  avr/arm_compile_macros - some common compile macros for avr/arm usage
 
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

#ifndef _AVR_COMPILE_MACROS_H_
#define _AVR_COMPILE_MACROS_H_   


/*
 * first check the essential macros/defines
 */
#ifndef F_CPU
#  error "Freq of CPU not defined!"
#endif


/*
 * check macros and define reasonable defaults 
 */
#ifndef CONTROLLER_FAMILY
#define CONTROLLER_FAMILY  __AVR__
#  warning "Controller family not defined, use __AVR__"
#endif

/*
 * define YES and NO 
 */
#ifndef __YES__
#define __YES__ 1
#endif

#ifndef __NO__
#define __NO__ 0
#endif

/*
 * defines for port definitions -> see libavrcyclon 
 */
#ifndef __PORT_A__
#define __PORT_A__ 1
#endif

#ifndef __PORT_B__
#define __PORT_B__ 2
#endif

#ifndef __PORT_C__
#define __PORT_C__ 3
#endif

#ifndef __PORT_D__
#define __PORT_D__ 4
#endif


/*
 * defines for COMMUNICATION_PATH -> see template and my_m168p_env ...
 */
#ifndef __SERIAL__
#define __SERIAL__ 1
#endif

#ifndef __LCD__
#define __LCD__ 2
#endif

#endif
