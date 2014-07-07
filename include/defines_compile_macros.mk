# common compiler switches to active/deactivate code fragments
#
# Note: also edit avr_compile_macros.h if needed

# which controller do i use?
# -> AVR
# -> ARM (cortex-m3)
CONTROLLER_FAMILY = AVR

# use serial_errno to indicate serial specific erros
# -> ON  (use it)
# -> OFF (no i can do it better)
SERIAL_ERROR = ON

# led port for cylcon
# -> PORTA
# -> ...
CYCLON_PORT = PORTB
