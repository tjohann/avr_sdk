/*
  GPL
  (c) 2014-2021, thorsten.johannvorderbrueggen@t-online.de

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

#ifndef _AVR_COMPILE_MACROS_H_
#define _AVR_COMPILE_MACROS_H_

/*
 * first check the essential macros/defines
 */
#ifndef F_CPU
#  error "Freq of CPU not defined!"
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
 * define NONE
 */
#ifndef __NONE__
#define __NONE__ 0
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
