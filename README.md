AVR_SDK
=======

A simple sdk with libs and tools for using with 8 bit controller.

WARNING: This is work in progress! So it's possible that something is not working or possibly not implemented yet. If you face a bug then pls use create an issue (https://github.com/tjohann/avr_sdk/issues).


Setup AVR dev environment
-------------------------

This is a short introduction for using my avr_sdk. The main idea is to have a library which includes basic functionallities used in the projects.

The activate/deactivate or configure a specific feature will be done via env file.


Files/folders
-------------

	- Documentation ... some documentation
	- include ... the avr specific headers
	  **usage**: see ~/avr_sdk/src/template for usage
	- lib ... the avr specific libs
      **usage**: see ~/avr_sdk/src/template for usage
	- my_m168p_env/my_m32_env ... the controller specific config
      **usage**: ~/avr_sdk$. ./my_m168p_env
	- src ... sources for avr specific libs and tools
	- projects ... here are some projects
	  **Note**: to build a project, you have to source the corresponding env file
	- bin ... some helper scripts
	- mk ... Makefile relevant defines
   	- FEATURE_OVERVIEW ... a short decription of the feartures and the configuration


Build library for specific device
---------------------------------

Create an **controller** specific file like my_m168p_env ... source it and try to build content
of ~/avr_sdk/src$

	~/avr_sdk$ . ./my_m32_env

Example above: Setup env for target atmega168p with 1000000Hz and 9600baud

Now build the library:

	~/avr_sdk$ cd src
	~/avr_sdk/src$ ls
	libavrcyclon  libavrhelper  libavrserial  makefile  template ...
	~/avr_sdk/src$ make
	.... A lot of output ...

Check for errors ... there shouldn't be any ... also be aware of the warnings.


Build a project
---------------

The projects are bound to a specific controller. There'fore the source the corresponding env files above. To build a project source the project file and build it in the folder:

	~/avr_sdk/projects$ . ./usb_i2c_gateway_env
	Setup env for target atmega328p with 16000000Hz and 9600baud
	Setup env for target atmega328p with 16000000Hz and 9600baud


	~/avr_sdk/projects/usb_i2c_gateway$ make

	||
	|| -->  Start building usb_i2c_gateway.elf
	||
	avr-gcc -Wall -Wextra -g -ggdb -std=gnu11 -mmcu=atmega328p -DF_CPU=16000000UL -ffunction-sections -fdata-sections -Os -DUSE_SERIAL=__YES__ -DUSE_I2C=__YES__ -DUSE_ADC=__NO__ -DSERIAL_ERROR=__ON__ -DI2C_ERROR=__ON__ -DADC_ERROR=__ON__ -DCOMMUNICATION_PATH=__SERIAL__ -save-temps -c usb_i2c_gateway.c -I./include -I/home/tjohann/avr_sdk/include
	...


Complete workflow
-----------------

Note: the projects use the library, so you first have to build the library with the corresponding env file:

Build the library:

	cd ~/avr_sdk
	~/avr_sdk$ . ./my_m32_env
	make
	... a lot of output ...

Build the project:

	cd ~/avr_sdk/projects$
	~/avr_sdk/projects$ . ./my_ext_ctrl_modul_env

	cd my_ext_ctrl_modul
	make
	... a lot of output ...

