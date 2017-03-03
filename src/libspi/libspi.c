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

#include "libspi.h"
#include "libspi_priv.h"


/*
 * if you want to use SPI ... otherwise no code to to link
 */
#if USE_SPI == __YES__


/*
 * -> enable spi
 *
 *  spi_errno: SPI_INIT_DEFAULT
 */
void
spi_setup_spi()
{

/*
 * SPI SETUP FOR AVR
 */

}

#else
# warning "USE_SPI == __NO__ -> dont try to use the functions "
#endif
