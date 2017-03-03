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

#include "libi2c.h"
#include "libi2c_priv.h"


/*
 * if you want to use I2C ... otherwise no code to to link
 */
#if USE_I2C == __YES__


/*
 * -> setup i2c for master mode
 */
void
i2c_setup_master_mode(i2c_bit_rate_t bit_rate)
{
	i2c_setup_i2c(MASTER, bit_rate);
}


/*
 * -> setup i2c for slave mode
 */
void
i2c_setup_slave_mode(void)
{
	i2c_setup_i2c(SLAVE, NONE);
}


/*
 * -> setup i2c for multi master mode
 */
void
i2c_setup_multi_master_mode(i2c_bit_rate_t bit_rate)
{
	i2c_setup_i2c(MULTI_MASTER, bit_rate);
}


/*
 * -> enable i2c
 */
void
i2c_enable_i2c(void)
{
	TWCR |= (1 << TWEN);
}


/*
 * -> enable i2c
 *
 *  i2c_errno: I2C_INIT_DEFAULT
 *             I2C_TWBR_UNSTABLE
 */
void
i2c_setup_i2c(i2c_op_mode_t mode,
    	     i2c_bit_rate_t bit_rate)
{
	if (mode == MASTER) {

		/*
		 * TODO: -> prescaler handling ...
		 */
		TWSR = 0;

		switch (bit_rate)
		{
		case I2C_100KHz:
			TWBR = (F_CPU / TWBR_DENOMINATOR_100KHZ) - 8;
			if (TWBR < 10)
				i2c_errno = I2C_TWBR_UNSTABLE;
			break;
		case I2C_400KHz:
			TWBR = (F_CPU / TWBR_DENOMINATOR_400KHZ) - 8;
			if (TWBR < 10)
				i2c_errno = I2C_TWBR_UNSTABLE;
			break;
		default:
			// 100 kHz
			TWBR = (F_CPU / TWBR_DENOMINATOR_100KHZ) - 8;
#if I2C_ERROR == __ON__
			i2c_errno = I2C_INIT_DEFAULT;
#endif
		}

		i2c_enable_i2c();
	}


	if (mode == SLAVE) {
		// SLAVE mode
	}

	if (mode == MULTI_MASTER) {
		// MULTIMASTER
	}
}


#else
# warning "USE_I2C == __NO__ -> dont try to use the functions "
#endif
