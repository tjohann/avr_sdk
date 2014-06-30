avr_sdk ... a simple sdk with libs and tools for using with 8 bit controller
==========================

Setup AVR dev environment
--------------------------

This is a short introduction for using my avr_sdk.

* Files: *
- AUTHORS ...
- bin ... some usefull bin (x86_64)
- Changelog ...
- COPYING ...
- docs ... some usefull docs
- env_avr_dev_latest -> env_avr_dev_v1
- env_avr_dev_v1 ... env script which set needed variables 
  usage: ~/avr_sdk$. ./env_avr_dev_latest
- etc ... some usefull config
- include ... the avr specific headers
  usage: see ~/avr_sdk/src/template for usage
- LATEST_IS ...
- lib ... the avr specific libs 
   usage: see ~/avr_sdk/src/template for usage
- makefile ...
- man ... some manpages for the avr specific libs
- my_m168p_env ... the controller specific config 
   usage: ~/avr_sdk$. ./my_m168p_env
- NEWS ...
- README ... this file 
- src ... sources for avr specific libs and tools
- TODO ...

* General usage: *
- Create an controller specific file like my_m168p_env ... source it and try to build content
of ~/avr_sdk/src$ ... 

...~/avr_sdk$ . ./my_m168p_env 
Setup env for target atmega168p with 1000000Hz and 9600baud
...:~/avr_sdk$ cd src
~/avr_sdk/src$ ls
libavrcyclon  libavrhelper  libavrserial  makefile  template
~/avr_sdk/src$ make
.... A lot of output ...
Check for errors ... there shouldn't be any 

*HOTWO use it: *
Check the template for a general overview and/or check the lib*s 


Pls report errors to thorsten.johannvorderbrueggen@t-online.de with subject [AVR_SDK_ERRORS] ...

 Cheers
  Thorsten


Note: There will be another project based on cortex-m3 (arm_noeabi_sdk) ... i try to share some ideas
      and code ... so you will find in $(AVR_HOME)/include 2 files -> "avr_compile_macros.h" and
      "defines_compile_macros.mk" ... they will handle it 

