HOWTO
=====

This is a small howto for my avr_sdk. Make shure that you already read the README.

For this sdk I use 3 different controller, first an atmega168(pa), second an atmega32 and third a Arduino Nano v3 as bare-metal. So the 3 env files (my_m168p_env, my_m32_env and nano_v3_env) reflect my basic configuration for them. Within those files I configure the features of my target through simple macros (see FEATURE_OVERVIEW) like USE_LCD=__YES__. These macros are used in the source files to configure the needed variables and co.

So the first step you have to do is to decide which controller you want to use:

	atmega168(pa) -> ~/avr_sdk$ . ./my_m168pa_env

or

	atmega32 -> ~/avr_sdk$ . ./my_m32_env

or

	atmega328 -> ~/avr_sdk$ . ./nano_v3_env

After that you have set all possible switches to __YES__ for that controller. Next step is to build all libs under src/libavr*. To do so type

      	  ~/avr_sdk$ make

That generates/install the libs in ~/avr_sdk/lib (Note: this also build the template project). Depending on your sourced env file you have lcd or not and serial, and so one.


Some more notes
----------------

- in schematics you can/will find the corresponding schematics of the projects and the test hw (src/template)
