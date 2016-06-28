README
======

Common note: all modules have a state led -> check the moduls itself for the pin


Projects
--------

Common note: all modules have a state led -> check the moduls itself for the pin


my_ext_ctrl_modul -> This is a small module based on an atmega32 with lcd, 4 adc-read buttons and a i2c conntection. It should display informations from different moduls and let it access my_ext_ctrl_modul. To select wich modul is the source of info my_ext_ctrl_modul has a mode switch.

		     usecase:

                     +--------------------------------+               +---------------------------+
                     |                                |<---- CAN ---->|                           |
                     | Temp-controller within pc case |               |     my_ext_ctrl_modul     |
                     |                                |           +-->|                           |
                     +--------------------------------+           |   +---------------------------+
								  |       ||   ||     ||     ||
								 I2C      ||   \/     ||     \/
								  |       || (lm75-1) ||  Mode-swt
								  |       ||          \/
						          |       \/       LCD/8-bit
              					  |    adc-buttons
		     +----------------+         +-------------+  I2C
		     |                |         |             |   |
		     | Linux-board/pc |<- USB ->|  usb<->i2c  |<--+
		     |                |         |             |
 		     +----------------+         +-------------+

		     The temp-controller is a pid controller with 3 different fans for 2 climate zones.
		     My_ext_ctrl_modul is the modul to display temps and fan speed and let
		     me also set paramater for the pid controller.
		     The Linux-board/pc is a normal pc or an embbedded devices which shows info of it
		     on my_ext_ctrl_modul and also theres a access path available (e.g. halt/reboot)


my_fan_ctrl_modul -> This is a small module based on an atmega168(pa) with serial, 2 fan outputs, 2 lm75 for temperature measurment and 3 adc channels for measuring the fan speed. The third fan is only switched on/off if needed.

		     usecase:

		     +--------------------------------+           +-------------------+
             |                                |           |                   |
             |       my_fan_ctrl_modul        |<-- CAN -->| my_ext_ctrl_modul |
             |                                |           |                   |
             +--------------------------------+           +-------------------+
		      ||     ||    ||    ||       ||
		      ||     ||    \/    ||       \/
		      \/     ||  serial  ||    adc1/2-fan
		  PWM-Fan2/3 ||          \/
		             \/	      swt Fan1
		          lm75-1/2


my_usb_i2c_shifter -> This is a small module based on an atmega169(pa) with serial and i2c. Its a gateway between an usb devices like a linux-board and the i2c modul my_ext_ctrl_modul. For usb it uses a standart usb/serial converter.

		     usecase:

		     +----------------+           +-------------+           +-------------------+
		     |                |           |             |           |                   |
		     | Linux-board/pc |<-- USB -->|  usb<->i2c  |<-- I2C -->| my_ext_ctrl_modul |
		     |                |           |             |           |                   |
 		     +----------------+           +-------------+           +-------------------+

F
