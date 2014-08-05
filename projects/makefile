MODULES = my_ext_ctrl_modul my_fan_ctrl_modul my_usb_i2c_shifter
FLASH = my_ext_ctrl_modul

all::
	@echo " "
	@echo "--> Building $(MODULES) "
	@echo " "
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

clean::
	rm -f *~ *.o .*~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

install:: 
	@echo " "
	@echo "--> Nothing to install "
	@echo " "

flash::
	@echo " "
	@echo "--> Flashing $(FLASH) "
	@echo " "
	for dir in $(FLASH); do (cd $$dir && $(MAKE) $@); done
