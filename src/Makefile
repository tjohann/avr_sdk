#
# my simple makefile act as something like a user interface
#

ifeq "${AVR_HOME}" ""
    $(error error: please source a *_env file first!)
endif

MODULES = template
AVR_LIBS = libhelper libserial libadc liblcd libi2c libspi libcan libcyclon

all::
	@echo " "
	@echo "--> Building $(AVR_LIBS) "
	@echo " "
	for dir in $(AVR_LIBS); do (cd $$dir && $(MAKE) $@ && $(MAKE) install); done
	@echo " "
	@echo "--> Building $(MODULES) "
	@echo " "
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

clean::
	rm -f *~ *.o .*~
	for dir in $(AVR_LIBS); do (cd $$dir && $(MAKE) $@); done
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

install::
	@echo " "
	@echo "--> Install $(AVR_LIBS) "
	@echo " "
	for dir in $(AVR_LIBS); do (cd $$dir && $(MAKE) $@); done
