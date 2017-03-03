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

#ifndef _LIBCYCLON_H_
#define _LIBCYCLON_H_

#include <avr_compile_macros.h>
#include <libhelper.h>


#ifndef F_CPU
#  error "Freq of CPU not defined!"
#endif

/*
 * -> do some init stuff
 */
void
cyclon_setup_port(void);


/*
 * -> cyclon eye function like knight rider or whatever you like
 *
 * Note: if count == 0 -> endless mode
 *       delay_time in ms -> example: 100 -> 100ms
 */
void
cyclon_run(const unsigned short count,
	   unsigned char starting_led,
	   double delay_time);


/*
 * -> cyclon double eye function like knight rider
 *
 * Note: led 0 + 7
 *       led 1 + 6
 *       ...
 */
void
cyclon_double_run(const unsigned short count,
		  double delay_time);


#endif
