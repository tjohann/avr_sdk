# common defines for m32

# atmege32 defaults
LFUSE_DEF = 0xee
HFUSE_DEF = 0x99

# atmege32 project specific (jtag disabled)
LFUSE = 0xee
HFUSE = 0xD9

# default fuses
FUSE_DEFAULT = -U lfuse:w:$(LFUSE_DEF):m -U hfuse:w:$(HFUSE_DEF):m

#
# Note:
#       set also FUSE_STRING in project makefile
#
