#
# makefile for libavrspi
#

ifeq "${AVR_HOME}" ""
    $(error error: please source a *_env file first!)
endif

include $(AVR_HOME)/mk/defines.mk
include $(AVR_HOME)/mk/defines_compile_macros.mk
include $(PROJECT_CONTROLLER)

TARGET = libspi
SRC = libspi.c
HEADER = libspi.h

#
# common CFLAGS in $(AVR_HOME)/include/defines.mk
#
CONTROLLER = -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL
OPT_FLAGS = -Os
COMPILER_SWITCHES = -DUSE_SPI=$(USE_SPI) -DSPI_ERROR=$(SPI_ERROR)

#
# ---------  BUILD all in a single step ----------
#
all: $(TARGET).a $(TARGET).lst

$(TARGET).a: $(TARGET).c $(TARGET).h $(TARGET)_priv.h
	@echo "|| "
	@echo "|| -->   building $(TARGET).a of $(SRC) for target $(MCU)"
	@echo "|| "
	$(AVR-GCC) $(WARN) $(DEBUG) -std=$(CSTD) $(CONTROLLER) $(CFLAGS) $(OPT_FLAGS) $(COMPILER_SWITCHES) -save-temps -c $(SRC) -I$(INCLUDEDIR)
	$(AVR-AR) rcv $(TARGET).a $(TARGET).o

%.lst: %.a
	@echo " "
	@echo "|| "
	@echo "|| -->  Create $(TARGET).lst "
	@echo "|| "
	$(AVR-OBJDUMP) -h -S $< > $@

install: $(TARGET).a
	cp -d $(TARGET).a $(AVR_HOME)/lib
	cp -d $(TARGET).h $(AVR_HOME)/include

clean:
	rm -rf *~ *.a *.i *.s *.elf *.hex *.bin *.srec *.obj *.o *.eeprom *.lst *.map core.d






