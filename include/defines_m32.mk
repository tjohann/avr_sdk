# common defines for m32

# atmege32 defaults 
LFUSE = 0xee
HFUSE = 0x99
# preserve eeprom across flashing 
EFUSE = 0x00

# default fuses 
FUSE_DEFAULT = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m

