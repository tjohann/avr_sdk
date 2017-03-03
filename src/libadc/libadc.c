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

#include "libadc.h"
#include "libadc_priv.h"


/*
 * if you want to use ADC ... otherwise no code to to link
 */
#if USE_ADC == __YES__

/*
 * -> init adc
 */
void
adc_init_adc(unsigned char adc_channel)
{

/*
 * TODO: macros for all bit settings
 */

	switch (adc_channel){
	case ADC_CH0:
		ADMUX |= (1 << REFS0);
		ADCSRA |= (1 << ADPS2);
		ADCSRA |= (1 << ADEN);
			break;
	case ADC_CH1:

		/*
		 * fill me
		 */

		break;
	default:
		// ADC_CH0
		ADMUX |= (1 << REFS0);
		ADCSRA |= (1 << ADPS2);
		ADCSRA |= (1 << ADEN);
#if ADC_ERROR == __ON__
	adc_errno = ADC_INIT_DEFAULT;
#endif
	};
}

#else
# warning "USE_ADC == __NO__ -> dont try to use the functions "
#endif
