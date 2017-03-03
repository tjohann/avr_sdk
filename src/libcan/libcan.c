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

#include "libcan.h"
#include "libcan_priv.h"


/*
 * if you want to use CAN ... otherwise no code to to link
 */
#if USE_CAN == __YES__


/*
 * -> setup can
 */
void
can_setup_can(void)
{

/*
 * CAN SETUP FOR AVR
 */
}


#else
# warning "USE_CAN == __NO__ -> dont try to use the functions "
#endif
