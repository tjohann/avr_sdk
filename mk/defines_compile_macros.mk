# common compiler switches to active/deactivate code fragments
#
# Note: also edit avr/arm_compile_macros.h if needed

ifeq "${AVR_HOME}" ""
    $(error error: please source a *_env file first!)
endif

# ----------- ERRNO parts -------------

# use adc_errno to indicate adc specific erros
# -> ON  (use it)
# -> OFF (no i can do it better)
ADC_ERROR = __ON__


# use serial_errno to indicate serial specific erros
# -> ON  (use it)
# -> OFF (no i can do it better)
SERIAL_ERROR = __ON__


# use lcd_errno to indicate lcd specific erros
# -> ON  (use it)
# -> OFF (no i can do it better)
LCD_ERROR = __ON__


# use i2c_errno to indicate i2c specific erros
# -> ON  (use it)
# -> OFF (no i can do it better)
I2C_ERROR = __ON__


# use spi_errno to indicate spi specific erros
# -> ON  (use it)
# -> OFF (no i can do it better)
SPI_ERROR = __ON__


