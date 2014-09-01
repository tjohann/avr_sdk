/*
  my_ext_ctrl_modul - simple project with atmega32 

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

#include <avr/io.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#include <string.h>

/*
 * -> my avr_sdk libs 
 */
#include <avr_compile_macros.h>
#include <libavrhelper.h>
#include <libavradc.h>
#include <libavrlcd.h>
#include <libavri2c.h>


// make shure that COMMUNICATION_PATH is available
#ifndef COMMUNICATION_PATH
#error "COMMUNICATION_PATH not defined"
#endif

/*
 * -> use adc_errno
 */
extern unsigned char adc_errno;


/*
 * -> use lcd_errno
 */
extern unsigned char lcd_errno;


/*
 * -> use i2c_errno
 */
extern unsigned char i2c_errno;


/*
 * pin for control led
 */
#define LED_PIN PB0
#define LED_DDR DDRB
#define LED_PORT PORTB


/*
 * pin for mode switch
 */
#define MODE_PIN PA7
#define MODE_DDR DDRA
#define MODE_PORT PORTA
#define MODE_INPUT_PORT PINA


/*
 * common defines
 * 
 * -> DELAYTIME ... the normal blink time
 * -> DELAYTIME_ON_ERROR ... the blinking time to indicate an error
 *
 * -> DELAYTIME_HEART_ON ... for heartbeat
 * -> DELAYTIME_HEART_OFF ... for heartbeat
 *
 * -> STATE_UNKNOWN ... state of template is unknown 
 * -> STATE_OK ... everthing is up and running
 * -> STATE_ERROR ... an error occured
 * -> ...
 *
 */
#define DELAYTIME 1000
#define DELAYTIME_ON_ERROR DELAYTIME/100

#define DELAYTIME_HEART_ON 100
#define DELAYTIME_HEART_OFF 50

// Note: incrising values ... do not change
#define STATE_UNKNOWN 0x00
#define STATE_OK 0x01
#define STATE_ERROR 0x02
#define STATE_LCD_INIT_DONE 0x04
#define STATE_ADC_INIT_DONE 0x08
#define STATE_MYMODUL_INIT_DONE 0x10


