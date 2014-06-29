	.file	"template.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text.init_template,"ax",@progbits
.global	init_template
	.type	init_template, @function
init_template:
.LFB6:
	.file 1 "template.c"
	.loc 1 35 0
	.cfi_startproc
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	.loc 1 37 0
	sbi 0x4,0
	ret
	.cfi_endproc
.LFE6:
	.size	init_template, .-init_template
	.section	.text.startup.main,"ax",@progbits
.global	main
	.type	main, @function
main:
.LFB7:
	.loc 1 46 0
	.cfi_startproc
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	.loc 1 48 0
	call init_template
.LVL0:
	.loc 1 50 0
	ldi r24,lo8(1)
	ldi r25,0
	call serial_setup_async_normal_mode
.LVL1:
	.loc 1 56 0
	call helper_dummy
.LVL2:
	.loc 1 57 0
	call cyclon_dummy
.LVL3:
.L3:
	.loc 1 62 0 discriminator 1
	sbi 0x5,0
.LVL4:
.LBB6:
.LBB7:
	.file 2 "/usr/avr/include/util/delay.h"
	.loc 2 164 0 discriminator 1
	ldi r24,lo8(-15537)
	ldi r25,hi8(-15537)
	1: sbiw r24,1
	brne 1b
	rjmp .
	nop
.LBE7:
.LBE6:
	.loc 1 66 0 discriminator 1
	cbi 0x5,0
.LVL5:
.LBB8:
.LBB9:
	.loc 2 164 0 discriminator 1
	ldi r24,lo8(-15537)
	ldi r25,hi8(-15537)
	1: sbiw r24,1
	brne 1b
	rjmp .
	nop
	rjmp .L3
.LBE9:
.LBE8:
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.text
.Letext0:
	.file 3 "/usr/avr/include/stdint.h"
	.file 4 "/home/tjohann/avr_sdk/include/libavrserial.h"
	.file 5 "/home/tjohann/avr_sdk/include/libavrhelper.h"
	.file 6 "/home/tjohann/avr_sdk/include/libavrcyclon.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x1de
	.word	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF18
	.byte	0x1
	.long	.LASF19
	.long	.LASF20
	.long	.Ldebug_ranges0+0
	.long	0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF0
	.uleb128 0x3
	.long	.LASF2
	.byte	0x3
	.byte	0x7a
	.long	0x37
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x4
	.byte	0x2
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.long	.LASF3
	.byte	0x3
	.byte	0x7c
	.long	0x50
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF4
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.long	.LASF5
	.uleb128 0x3
	.long	.LASF6
	.byte	0x3
	.byte	0x7e
	.long	0x69
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF7
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF8
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF9
	.uleb128 0x5
	.long	.LASF21
	.byte	0x2
	.byte	0x4
	.byte	0x30
	.long	0x91
	.uleb128 0x6
	.long	.LASF22
	.sleb128 1
	.byte	0
	.uleb128 0x3
	.long	.LASF10
	.byte	0x4
	.byte	0x32
	.long	0x7e
	.uleb128 0x7
	.long	.LASF23
	.byte	0x2
	.byte	0x8e
	.byte	0x3
	.long	0xdd
	.uleb128 0x8
	.long	.LASF24
	.byte	0x2
	.byte	0x8e
	.long	0xdd
	.uleb128 0x9
	.long	.LASF11
	.byte	0x2
	.byte	0x90
	.long	0x45
	.uleb128 0x9
	.long	.LASF12
	.byte	0x2
	.byte	0x91
	.long	0xdd
	.uleb128 0x9
	.long	.LASF13
	.byte	0x2
	.byte	0x95
	.long	0x5e
	.uleb128 0xa
	.long	.LASF15
	.byte	0x2
	.byte	0x96
	.byte	0
	.byte	0
	.uleb128 0x2
	.byte	0x4
	.byte	0x4
	.long	.LASF14
	.uleb128 0xb
	.long	.LASF25
	.byte	0x1
	.byte	0x22
	.long	.LFB6
	.long	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xc
	.long	.LASF26
	.byte	0x1
	.byte	0x2d
	.long	0x3e
	.long	.LFB7
	.long	.LFE7-.LFB7
	.uleb128 0x1
	.byte	0x9c
	.long	0x1c2
	.uleb128 0xd
	.long	0x9c
	.long	.LBB6
	.long	.LBE6-.LBB6
	.byte	0x1
	.byte	0x3f
	.long	0x14e
	.uleb128 0xe
	.long	0xa8
	.byte	0x4
	.long	0x43480000
	.uleb128 0xf
	.long	.LBB7
	.long	.LBE7-.LBB7
	.uleb128 0x10
	.long	0xb3
	.uleb128 0x11
	.long	0xbe
	.byte	0x4
	.long	0x48435000
	.uleb128 0x12
	.long	0xc9
	.long	0x30d40
	.byte	0
	.byte	0
	.uleb128 0xd
	.long	0x9c
	.long	.LBB8
	.long	.LBE8-.LBB8
	.byte	0x1
	.byte	0x43
	.long	0x18e
	.uleb128 0xe
	.long	0xa8
	.byte	0x4
	.long	0x43480000
	.uleb128 0xf
	.long	.LBB9
	.long	.LBE9-.LBB9
	.uleb128 0x10
	.long	0xb3
	.uleb128 0x11
	.long	0xbe
	.byte	0x4
	.long	0x48435000
	.uleb128 0x12
	.long	0xc9
	.long	0x30d40
	.byte	0
	.byte	0
	.uleb128 0x13
	.long	.LVL0
	.long	0xe4
	.uleb128 0x14
	.long	.LVL1
	.long	0x1c2
	.long	0x1af
	.uleb128 0x15
	.uleb128 0x6
	.byte	0x68
	.byte	0x93
	.uleb128 0x1
	.byte	0x69
	.byte	0x93
	.uleb128 0x1
	.uleb128 0x1
	.byte	0x31
	.byte	0
	.uleb128 0x13
	.long	.LVL2
	.long	0x1d3
	.uleb128 0x13
	.long	.LVL3
	.long	0x1da
	.byte	0
	.uleb128 0x16
	.long	.LASF27
	.byte	0x4
	.byte	0x3f
	.long	0x1d3
	.uleb128 0x17
	.long	0x91
	.byte	0
	.uleb128 0x18
	.long	.LASF16
	.byte	0x5
	.byte	0x3f
	.uleb128 0x18
	.long	.LASF17
	.byte	0x6
	.byte	0x25
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x20
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1c
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1c
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1c
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x4109
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x24
	.word	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.word	0
	.word	0
	.long	.LFB6
	.long	.LFE6-.LFB6
	.long	.LFB7
	.long	.LFE7-.LFB7
	.long	0
	.long	0
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.long	.LFB6
	.long	.LFE6
	.long	.LFB7
	.long	.LFE7
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF10:
	.string	"serial_frame_type_t"
.LASF22:
	.string	"DATA_8_STOP_1_NO_PARITY"
.LASF17:
	.string	"cyclon_dummy"
.LASF25:
	.string	"init_template"
.LASF15:
	.string	"__builtin_avr_delay_cycles"
.LASF19:
	.string	"template.c"
.LASF1:
	.string	"unsigned char"
.LASF7:
	.string	"long unsigned int"
.LASF23:
	.string	"_delay_ms"
.LASF27:
	.string	"serial_setup_async_normal_mode"
.LASF14:
	.string	"double"
.LASF12:
	.string	"__tmp"
.LASF26:
	.string	"main"
.LASF4:
	.string	"unsigned int"
.LASF9:
	.string	"long long unsigned int"
.LASF2:
	.string	"uint8_t"
.LASF20:
	.string	"/home/tjohann/avr_sdk/src/template"
.LASF18:
	.string	"GNU C 4.8.3 -fpreprocessed -mmcu=atmega168p -g -ggdb -Os -std=gnu99 -ffunction-sections -fdata-sections"
.LASF8:
	.string	"long long int"
.LASF13:
	.string	"__ticks_dc"
.LASF3:
	.string	"uint16_t"
.LASF11:
	.string	"__ticks"
.LASF6:
	.string	"uint32_t"
.LASF5:
	.string	"long int"
.LASF0:
	.string	"signed char"
.LASF21:
	.string	"serial_frame_type"
.LASF24:
	.string	"__ms"
.LASF16:
	.string	"helper_dummy"
	.ident	"GCC: (GNU) 4.8.3"
