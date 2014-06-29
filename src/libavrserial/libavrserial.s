	.file	"libavrserial.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text.serial_setup_usart,"ax",@progbits
.global	serial_setup_usart
	.type	serial_setup_usart, @function
serial_setup_usart:
.LFB3:
	.file 1 "libavrserial.c"
	.loc 1 64 0
	.cfi_startproc
.LVL0:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	.loc 1 75 0
	sts 197,__zero_reg__
	.loc 1 76 0
	ldi r18,lo8(12)
	sts 196,r18
	.loc 1 79 0
	cpi r24,2
	cpc r25,__zero_reg__
	breq .L14
	sbiw r24,3
	breq .L4
.L14:
	.loc 1 97 0
	lds r24,192
.LVL1:
	andi r24,lo8(-3)
	sts 192,r24
.L4:
	.loc 1 102 0
	cpi r20,2
	cpc r21,__zero_reg__
	breq .L7
	cpi r20,3
	cpc r21,__zero_reg__
	breq .L15
	cpi r20,1
	cpc r21,__zero_reg__
	brne .L15
.LVL2:
.LBB4:
.LBB5:
	.loc 1 107 0
	ldi r24,lo8(16)
	sts 193,r24
	.loc 1 108 0
	lds r24,193
	andi r24,lo8(-9)
	rjmp .L16
.LVL3:
.L7:
.LBE5:
.LBE4:
	.loc 1 111 0
	ldi r24,lo8(8)
	sts 193,r24
	.loc 1 112 0
	lds r24,193
	andi r24,lo8(-17)
	rjmp .L16
.L15:
	.loc 1 116 0
	ldi r24,lo8(24)
.L16:
	sts 193,r24
	ret
	.cfi_endproc
.LFE3:
	.size	serial_setup_usart, .-serial_setup_usart
	.section	.text.serial_setup_async_normal_mode,"ax",@progbits
.global	serial_setup_async_normal_mode
	.type	serial_setup_async_normal_mode, @function
serial_setup_async_normal_mode:
.LFB0:
	.loc 1 18 0
	.cfi_startproc
.LVL4:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	.loc 1 19 0
	ldi r20,lo8(3)
	ldi r21,0
	movw r22,r24
	ldi r24,lo8(1)
	ldi r25,0
.LVL5:
	jmp serial_setup_usart
.LVL6:
	.cfi_endproc
.LFE0:
	.size	serial_setup_async_normal_mode, .-serial_setup_async_normal_mode
	.section	.text.serial_setup_async_double_speed,"ax",@progbits
.global	serial_setup_async_double_speed
	.type	serial_setup_async_double_speed, @function
serial_setup_async_double_speed:
.LFB1:
	.loc 1 31 0
	.cfi_startproc
.LVL7:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	.loc 1 32 0
	ldi r20,lo8(3)
	ldi r21,0
	movw r22,r24
	ldi r24,lo8(2)
	ldi r25,0
.LVL8:
	jmp serial_setup_usart
.LVL9:
	.cfi_endproc
.LFE1:
	.size	serial_setup_async_double_speed, .-serial_setup_async_double_speed
	.section	.text.serial_setup_sync_master,"ax",@progbits
.global	serial_setup_sync_master
	.type	serial_setup_sync_master, @function
serial_setup_sync_master:
.LFB2:
	.loc 1 44 0
	.cfi_startproc
.LVL10:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	.loc 1 45 0
	ldi r20,lo8(3)
	ldi r21,0
	movw r22,r24
	ldi r24,lo8(3)
	ldi r25,0
.LVL11:
	jmp serial_setup_usart
.LVL12:
	.cfi_endproc
.LFE2:
	.size	serial_setup_sync_master, .-serial_setup_sync_master
	.text
.Letext0:
	.file 2 "libavrserial.h"
	.file 3 "/usr/avr/include/stdint.h"
	.file 4 "libavrserial_priv.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x248
	.word	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF26
	.byte	0x1
	.long	.LASF27
	.long	.LASF28
	.long	.Ldebug_ranges0+0
	.long	0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF9
	.byte	0x2
	.byte	0x2
	.byte	0x30
	.long	0x38
	.uleb128 0x3
	.long	.LASF11
	.sleb128 1
	.byte	0
	.uleb128 0x4
	.long	.LASF0
	.byte	0x2
	.byte	0x32
	.long	0x25
	.uleb128 0x5
	.byte	0x1
	.byte	0x6
	.long	.LASF2
	.uleb128 0x4
	.long	.LASF1
	.byte	0x3
	.byte	0x7a
	.long	0x55
	.uleb128 0x5
	.byte	0x1
	.byte	0x8
	.long	.LASF3
	.uleb128 0x6
	.byte	0x2
	.byte	0x5
	.string	"int"
	.uleb128 0x5
	.byte	0x2
	.byte	0x7
	.long	.LASF4
	.uleb128 0x5
	.byte	0x4
	.byte	0x5
	.long	.LASF5
	.uleb128 0x5
	.byte	0x4
	.byte	0x7
	.long	.LASF6
	.uleb128 0x5
	.byte	0x8
	.byte	0x5
	.long	.LASF7
	.uleb128 0x5
	.byte	0x8
	.byte	0x7
	.long	.LASF8
	.uleb128 0x2
	.long	.LASF10
	.byte	0x2
	.byte	0x4
	.byte	0x1e
	.long	0xa5
	.uleb128 0x3
	.long	.LASF12
	.sleb128 1
	.uleb128 0x3
	.long	.LASF13
	.sleb128 2
	.uleb128 0x3
	.long	.LASF14
	.sleb128 3
	.byte	0
	.uleb128 0x4
	.long	.LASF15
	.byte	0x4
	.byte	0x22
	.long	0x86
	.uleb128 0x2
	.long	.LASF16
	.byte	0x2
	.byte	0x4
	.byte	0x25
	.long	0xcf
	.uleb128 0x3
	.long	.LASF17
	.sleb128 1
	.uleb128 0x3
	.long	.LASF18
	.sleb128 2
	.uleb128 0x3
	.long	.LASF19
	.sleb128 3
	.byte	0
	.uleb128 0x4
	.long	.LASF20
	.byte	0x4
	.byte	0x29
	.long	0xb0
	.uleb128 0x7
	.long	.LASF29
	.byte	0x1
	.byte	0x3d
	.byte	0x1
	.long	0x108
	.uleb128 0x8
	.long	.LASF21
	.byte	0x1
	.byte	0x3d
	.long	0xa5
	.uleb128 0x8
	.long	.LASF22
	.byte	0x1
	.byte	0x3e
	.long	0x38
	.uleb128 0x8
	.long	.LASF23
	.byte	0x1
	.byte	0x3f
	.long	0xcf
	.byte	0
	.uleb128 0x9
	.long	0xda
	.long	.LFB3
	.long	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x162
	.uleb128 0xa
	.long	0xe6
	.long	.LLST0
	.uleb128 0xb
	.long	0xf1
	.uleb128 0x6
	.byte	0x66
	.byte	0x93
	.uleb128 0x1
	.byte	0x67
	.byte	0x93
	.uleb128 0x1
	.uleb128 0xb
	.long	0xfc
	.uleb128 0x6
	.byte	0x64
	.byte	0x93
	.uleb128 0x1
	.byte	0x65
	.byte	0x93
	.uleb128 0x1
	.uleb128 0xc
	.long	.LBB4
	.long	.LBE4-.LBB4
	.uleb128 0xa
	.long	0xe6
	.long	.LLST1
	.uleb128 0xa
	.long	0xf1
	.long	.LLST2
	.uleb128 0xa
	.long	0xfc
	.long	.LLST3
	.byte	0
	.byte	0
	.uleb128 0xd
	.long	.LASF24
	.byte	0x1
	.byte	0x11
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.long	0x1b1
	.uleb128 0xe
	.long	.LASF22
	.byte	0x1
	.byte	0x11
	.long	0x38
	.long	.LLST4
	.uleb128 0xf
	.long	.LVL6
	.long	0xda
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x68
	.byte	0x93
	.uleb128 0x1
	.byte	0x69
	.byte	0x93
	.uleb128 0x1
	.uleb128 0x1
	.byte	0x31
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x66
	.byte	0x93
	.uleb128 0x1
	.byte	0x67
	.byte	0x93
	.uleb128 0x1
	.uleb128 0x3
	.byte	0xf3
	.uleb128 0x1
	.byte	0x68
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x64
	.byte	0x93
	.uleb128 0x1
	.byte	0x65
	.byte	0x93
	.uleb128 0x1
	.uleb128 0x1
	.byte	0x33
	.byte	0
	.byte	0
	.uleb128 0xd
	.long	.LASF25
	.byte	0x1
	.byte	0x1e
	.long	.LFB1
	.long	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x200
	.uleb128 0xe
	.long	.LASF22
	.byte	0x1
	.byte	0x1e
	.long	0x38
	.long	.LLST5
	.uleb128 0xf
	.long	.LVL9
	.long	0xda
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x68
	.byte	0x93
	.uleb128 0x1
	.byte	0x69
	.byte	0x93
	.uleb128 0x1
	.uleb128 0x1
	.byte	0x32
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x66
	.byte	0x93
	.uleb128 0x1
	.byte	0x67
	.byte	0x93
	.uleb128 0x1
	.uleb128 0x3
	.byte	0xf3
	.uleb128 0x1
	.byte	0x68
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x64
	.byte	0x93
	.uleb128 0x1
	.byte	0x65
	.byte	0x93
	.uleb128 0x1
	.uleb128 0x1
	.byte	0x33
	.byte	0
	.byte	0
	.uleb128 0x11
	.long	.LASF30
	.byte	0x1
	.byte	0x2b
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xe
	.long	.LASF22
	.byte	0x1
	.byte	0x2b
	.long	0x38
	.long	.LLST6
	.uleb128 0xf
	.long	.LVL12
	.long	0xda
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x68
	.byte	0x93
	.uleb128 0x1
	.byte	0x69
	.byte	0x93
	.uleb128 0x1
	.uleb128 0x1
	.byte	0x33
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x66
	.byte	0x93
	.uleb128 0x1
	.byte	0x67
	.byte	0x93
	.uleb128 0x1
	.uleb128 0x3
	.byte	0xf3
	.uleb128 0x1
	.byte	0x68
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x64
	.byte	0x93
	.uleb128 0x1
	.byte	0x65
	.byte	0x93
	.uleb128 0x1
	.uleb128 0x1
	.byte	0x33
	.byte	0
	.byte	0
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
	.uleb128 0x3
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0x4
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
	.uleb128 0x5
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
	.uleb128 0x6
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
	.uleb128 0x7
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
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
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
	.uleb128 0xa
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0xd
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
	.uleb128 0xe
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
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x2115
	.uleb128 0x19
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x11
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
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
	.long	.LVL0
	.long	.LVL1
	.word	0x6
	.byte	0x68
	.byte	0x93
	.uleb128 0x1
	.byte	0x69
	.byte	0x93
	.uleb128 0x1
	.long	.LVL1
	.long	.LFE3
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x68
	.byte	0x9f
	.long	0
	.long	0
.LLST1:
	.long	.LVL2
	.long	.LVL3
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x68
	.byte	0x9f
	.long	0
	.long	0
.LLST2:
	.long	.LVL2
	.long	.LVL3
	.word	0x6
	.byte	0x66
	.byte	0x93
	.uleb128 0x1
	.byte	0x67
	.byte	0x93
	.uleb128 0x1
	.long	0
	.long	0
.LLST3:
	.long	.LVL2
	.long	.LVL3
	.word	0x2
	.byte	0x31
	.byte	0x9f
	.long	0
	.long	0
.LLST4:
	.long	.LVL4
	.long	.LVL5
	.word	0x6
	.byte	0x68
	.byte	0x93
	.uleb128 0x1
	.byte	0x69
	.byte	0x93
	.uleb128 0x1
	.long	.LVL5
	.long	.LVL6-1
	.word	0x6
	.byte	0x66
	.byte	0x93
	.uleb128 0x1
	.byte	0x67
	.byte	0x93
	.uleb128 0x1
	.long	.LVL6-1
	.long	.LFE0
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x68
	.byte	0x9f
	.long	0
	.long	0
.LLST5:
	.long	.LVL7
	.long	.LVL8
	.word	0x6
	.byte	0x68
	.byte	0x93
	.uleb128 0x1
	.byte	0x69
	.byte	0x93
	.uleb128 0x1
	.long	.LVL8
	.long	.LVL9-1
	.word	0x6
	.byte	0x66
	.byte	0x93
	.uleb128 0x1
	.byte	0x67
	.byte	0x93
	.uleb128 0x1
	.long	.LVL9-1
	.long	.LFE1
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x68
	.byte	0x9f
	.long	0
	.long	0
.LLST6:
	.long	.LVL10
	.long	.LVL11
	.word	0x6
	.byte	0x68
	.byte	0x93
	.uleb128 0x1
	.byte	0x69
	.byte	0x93
	.uleb128 0x1
	.long	.LVL11
	.long	.LVL12-1
	.word	0x6
	.byte	0x66
	.byte	0x93
	.uleb128 0x1
	.byte	0x67
	.byte	0x93
	.uleb128 0x1
	.long	.LVL12-1
	.long	.LFE2
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x68
	.byte	0x9f
	.long	0
	.long	0
	.section	.debug_aranges,"",@progbits
	.long	0x34
	.word	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.word	0
	.word	0
	.long	.LFB3
	.long	.LFE3-.LFB3
	.long	.LFB0
	.long	.LFE0-.LFB0
	.long	.LFB1
	.long	.LFE1-.LFB1
	.long	.LFB2
	.long	.LFE2-.LFB2
	.long	0
	.long	0
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.long	.LFB3
	.long	.LFE3
	.long	.LFB0
	.long	.LFE0
	.long	.LFB1
	.long	.LFE1
	.long	.LFB2
	.long	.LFE2
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF0:
	.string	"serial_frame_type_t"
.LASF11:
	.string	"DATA_8_STOP_1_NO_PARITY"
.LASF28:
	.string	"/home/tjohann/avr_sdk/src/libavrserial"
.LASF29:
	.string	"serial_setup_usart"
.LASF10:
	.string	"serial_op_mode"
.LASF19:
	.string	"ENA_ALL"
.LASF21:
	.string	"op_mode"
.LASF27:
	.string	"libavrserial.c"
.LASF15:
	.string	"serial_op_mode_t"
.LASF20:
	.string	"serial_enable_rxtx_t"
.LASF3:
	.string	"unsigned char"
.LASF22:
	.string	"frame_type"
.LASF6:
	.string	"long unsigned int"
.LASF24:
	.string	"serial_setup_async_normal_mode"
.LASF13:
	.string	"ASYNC_DOUBLE"
.LASF30:
	.string	"serial_setup_sync_master"
.LASF14:
	.string	"SYNC_MASTER"
.LASF16:
	.string	"serial_enable_rxtx"
.LASF4:
	.string	"unsigned int"
.LASF8:
	.string	"long long unsigned int"
.LASF1:
	.string	"uint8_t"
.LASF25:
	.string	"serial_setup_async_double_speed"
.LASF17:
	.string	"ENA_RX"
.LASF26:
	.string	"GNU C 4.8.3 -fpreprocessed -mmcu=atmega168p -g -ggdb -Os -std=gnu99 -ffunction-sections -fdata-sections"
.LASF18:
	.string	"ENA_TX"
.LASF7:
	.string	"long long int"
.LASF5:
	.string	"long int"
.LASF23:
	.string	"ena_rxtx"
.LASF2:
	.string	"signed char"
.LASF9:
	.string	"serial_frame_type"
.LASF12:
	.string	"ASYNC_NORMAL"
	.ident	"GCC: (GNU) 4.8.3"
