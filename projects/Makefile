#
# my simple makefile act as something like a user interface
#

ifeq "${AVR_HOME}" ""
    $(error error: please source a *_env file first!)
endif

MODULES = $(shell ls -d */ | cut -f1 -d'/')

all::
	@echo " "
	@echo "--> Nothing to do"
	@echo " "

clean::
	rm -f *~ *.o .*~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

install::
	@echo " "
	@echo "--> Nothing to do"
	@echo " "

