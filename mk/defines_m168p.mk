# common defines for m168(pa)

# atmege168 defaults
LFUSE_DEF = 0x62
# full-speed-mode -> CLDIV8 = 1
# -> LFUSE = 0xE2
HFUSE_DEF = 0xdf
# preserve eeprom across flashing
# -> HFUSE = 0xD7
EFUSE_DEF = 0x00

# atmega168 project specific
LFUSE = 0x62
HFUSE = 0xdf
EFUSE = 0x00

# default fuses
FUSE_DEFAULT = -U lfuse:w:$(LFUSE_DEF):m -U hfuse:w:$(HFUSE_DEF):m -U efuse:w:$(EFUSE_DEF):m

#
# Note:
#       set also FUSE_STRING in project makefile
#
# to add some useful changes set the below values
# full-speed-mode -> CLDIV8 = 1 -> LFUSE = 0xE2
# preserve eeprom across flashing -> HFUSE = 0xD7
