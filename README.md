AVR_SDK
=======

A simple sdk with libs and tools for using with 8 bit controller.

WARNING: This is work in progress! So it's possible that something is not working or possibly not implemented yet. If you face a bug then pls use create an issue (https://github.com/tjohann/avr_sdk/issues).


Setup AVR dev environment
--------------------------

This is a short introduction for using my avr_sdk.


Files
-----

	- Documentation ... some useful documentation
	- include ... the avr specific headers
	  usage: see ~/avr_sdk/src/template for usage
	- lib ... the avr specific libs
      	  usage: see ~/avr_sdk/src/template for usage
	- my_m168p_env/my_m32_env ... the controller specific config
      	  usage: ~/avr_sdk$. ./my_m168p_env
	- src ... sources for avr specific libs and tools
	- projects ... here are my real projects
	  Note: to build a project, you have to source the corresponding env file
   	- FEATURE_OVERVIEW ... a short decription of the feartures and the configuration


General usage
-------------

Create an controller specific file like my_m168p_env ... source it and try to build content
of ~/avr_sdk/src$ ...

	~/avr_sdk$ . ./my_m168p_env

Setup env for target atmega168p with 1000000Hz and 9600baud

	~/avr_sdk$ cd src
	~/avr_sdk/src$ ls
	libavrcyclon  libavrhelper  libavrserial  makefile  template ...
	~/avr_sdk/src$ make
	.... A lot of output ...

Check for errors ... there shouldn't be any


HOTWO use it
------------

Check Notes file and also
Check the template for a general overview and/or check the lib*s ...
Check FEATURE_OVERVIEW and
Check HOWTO





