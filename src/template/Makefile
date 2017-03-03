#
# template makefile
#

ifeq "${AVR_HOME}" ""
    $(error error: please source a *_env file first!)
endif

include $(AVR_HOME)/include/defines.mk
include $(AVR_HOME)/include/defines_compile_macros.mk
include $(PROJECT_CONTROLLER)


TARGET = template
USED_LIBS = helper -lserial -ladc -llcd -li2c -lcan -lcyclon
SRC = template.c
HEADER = template.h


#
# common CFLAGS in $(AVR_HOME)/include/defines.mk
#
CONTROLLER = -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL
OPT_FLAGS = -Os
COMPILER_SWITCHES = -DUSE_SERIAL=$(USE_SERIAL) -DUSE_CYCLON=$(USE_CYCLON) -DUSE_LCD=$(USE_LCD)
COMPILER_SWITCHES += -DUSE_ADC=$(USE_ADC) -DUSE_I2C=$(USE_I2C) -DUSE_CAN=$(USE_CAN)
COMPILER_SWITCHES += -DSERIAL_ERROR=$(SERIAL_ERROR) -DADC_ERROR=$(ADC_ERROR) -DLCD_ERROR=$(LCD_ERROR)
COMPILER_SWITCHES += -DI2C_ERROR=$(I2C_ERROR) -DCAN_ERROR=$(CAN_ERROR)
COMPILER_SWITCHES += -DCOMMUNICATION_PATH=$(COMMUNICATION_PATH)


#
# common fuses in $(AVR_HOME)/include/defines_m*.mk
#
export FUSE_STRING = -U lfuse:w:${LFUSE}:m -U hfuse:w:${HFUSE}:m -U efuse:w:${EFUSE}:m

#
# ---------  BUILD all in a single step ----------
#
all: $(TARGET).elf $(TARGET).hex $(TARGET).srec $(TARGET).bin $(TARGET)_eeprom.hex $(TARGET)_eeprom.srec $(TARGET)_eeprom.bin $(TARGET).lst size
	@echo "|| "
	@echo "|| -->   Finished building $(TARGET).* of $(SRC) "
	@echo "|| "

#
# -> compile to object file and link them all to elf
#
%.elf: $(SRC) $(HEADER)
	@echo " "
	@echo "|| "
	@echo "|| -->  Start building $(TARGET).elf "
	@echo "|| "
	$(AVR-GCC) $(WARN) $(DEBUG) -std=$(CSTD) $(CONTROLLER) $(CFLAGS) $(OPT_FLAGS) $(COMPILER_SWITCHES) -save-temps -c $(SRC) -I$(INCLUDEDIR)
	$(AVR-GCC) $(WARN) $(DEBUG) -std=$(CSTD) $(CONTROLLER) $(LDFLAGS) $(TARGET).o --output $@ -L$(LIBDIR) -l$(USED_LIBS)


%.hex: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Start building $(TARGET).hex "
	@echo "|| "
	$(AVR-OBJCOPY) -R .eeprom -O ihex $< $@

%.srec: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Start building $(TARGET).srec "
	@echo "|| "
	$(AVR-OBJCOPY) -R .eeprom -O srec $< $@

%.bin: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Start building $(TARGET).bin "
	@echo "|| "
	$(AVR-OBJCOPY) -R .eeprom -O binary $< $@


%_eeprom.hex: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Start building $(TARGET).eeprom "
	@echo "|| "
	$(AVR-OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@

%_eeprom.srec: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Start building $(TARGET).srec "
	@echo "|| "
	$(AVR-OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O srec $< $@

%_eeprom.bin: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Start building $(TARGET).bin "
	@echo "|| "
	$(AVR-OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O binary $< $@


%.lst: %.elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Create $(TARGET).lst "
	@echo "|| "
	$(AVR-OBJDUMP) -h -S $< > $@

clean:
	rm -rf *~ *.i *.s *.elf *.hex *.bin *.srec *.obj *.o *.eeprom *.lst *.map core.d

install:
	@echo "Nothing to install"

eeprom: $(TARGET).elf
	@echo " "
	@echo "|| "
	@echo "|| -->  Start building $(TARGET).* "
	@echo "|| "
	$(AVR-OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $(TARGET)_eeprom.hex
	$(AVR-OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O srec $< $(TARGET)_eeprom.srec
	$(AVR-OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O binary $< $(TARGET)_eeprom.bin


size: $(TARGET).elf
	@echo " "
	@echo "|| "
	@echo "|| --> Mem usage "
	@echo "|| "
	$(AVRSIZE) $(TARGET).elf
#	$(AVRSIZE) -C --mcu=$(MCU) $(TARGET).elf


readelf: $(TARGET).elf
	@echo " "
	@echo "|| "
	@echo "|| --> detailed elf infos "
	@echo "|| "
	readelf --all $(TARGET).elf


fuses_prog:
	$(PROGRAMMER) -c $(PROGRAMMER_HW) -p $(MCU) $(PROGRAMMER_ARGS) $(FUSE_STRING)

fuses_read:
	$(PROGRAMMER) -c $(PROGRAMMER_HW) -p $(MCU) $(PROGRAMMER_ARGS) -nv

fuses_prog_defaults:
	$(PROGRAMMER) -c $(PROGRAMMER_HW) -p $(MCU) $(PROGRAMMER_ARGS) $(FUSE_DEFAULT)


flash_all: flash flash_eeprom

flash: $(TARGET).hex
	$(PROGRAMMER) -c $(PROGRAMMER_HW) -p $(MCU) $(PROGRAMMER_ARGS) -U flash:w:$<

flash_eeprom: $(TARGET).eeprom
	$(PROGRAMMER) -c $(PROGRAMMER_HW) -p $(MCU) $(PROGRAMMER_ARGS) -U eeprom:w:$<


