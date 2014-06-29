# 1 "libavrserial.c"
# 1 "/home/tjohann/avr_sdk/src/libavrserial//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "libavrserial.c"







# 1 "libavrserial.h" 1
# 25 "libavrserial.h"
# 1 "/home/tjohann/avr_sdk/include/libavrhelper.h" 1
# 62 "/home/tjohann/avr_sdk/include/libavrhelper.h"
void
helper_dummy(void);
# 26 "libavrserial.h" 2
# 48 "libavrserial.h"
typedef enum serial_frame_type {
        DATA_8_STOP_1_NO_PARITY = 0x01
} serial_frame_type_t;
# 62 "libavrserial.h"
void
serial_setup_async_normal_mode(serial_frame_type_t frame_type);






void
serial_setup_async_double_speed(serial_frame_type_t frame_type);




void
serial_setup_sync_master(serial_frame_type_t frame_type);
# 9 "libavrserial.c" 2
# 1 "libavrserial_priv.h" 1
# 26 "libavrserial_priv.h"
# 1 "/home/tjohann/avr_sdk/include/libavrserial.h" 1
# 27 "libavrserial_priv.h" 2
# 1 "/usr/avr/include/avr/io.h" 1 3
# 99 "/usr/avr/include/avr/io.h" 3
# 1 "/usr/avr/include/avr/sfr_defs.h" 1 3
# 126 "/usr/avr/include/avr/sfr_defs.h" 3
# 1 "/usr/avr/include/inttypes.h" 1 3
# 37 "/usr/avr/include/inttypes.h" 3
# 1 "/usr/lib64/gcc/avr/4.8.3/include/stdint.h" 1 3 4
# 9 "/usr/lib64/gcc/avr/4.8.3/include/stdint.h" 3 4
# 1 "/usr/avr/include/stdint.h" 1 3 4
# 121 "/usr/avr/include/stdint.h" 3 4
typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef signed int int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef signed int int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));

typedef signed int int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int uint64_t __attribute__((__mode__(__DI__)));
# 142 "/usr/avr/include/stdint.h" 3 4
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 159 "/usr/avr/include/stdint.h" 3 4
typedef int8_t int_least8_t;




typedef uint8_t uint_least8_t;




typedef int16_t int_least16_t;




typedef uint16_t uint_least16_t;




typedef int32_t int_least32_t;




typedef uint32_t uint_least32_t;







typedef int64_t int_least64_t;






typedef uint64_t uint_least64_t;
# 213 "/usr/avr/include/stdint.h" 3 4
typedef int8_t int_fast8_t;




typedef uint8_t uint_fast8_t;




typedef int16_t int_fast16_t;




typedef uint16_t uint_fast16_t;




typedef int32_t int_fast32_t;




typedef uint32_t uint_fast32_t;







typedef int64_t int_fast64_t;






typedef uint64_t uint_fast64_t;
# 273 "/usr/avr/include/stdint.h" 3 4
typedef int64_t intmax_t;




typedef uint64_t uintmax_t;
# 10 "/usr/lib64/gcc/avr/4.8.3/include/stdint.h" 2 3 4
# 38 "/usr/avr/include/inttypes.h" 2 3
# 77 "/usr/avr/include/inttypes.h" 3
typedef int32_t int_farptr_t;



typedef uint32_t uint_farptr_t;
# 127 "/usr/avr/include/avr/sfr_defs.h" 2 3
# 100 "/usr/avr/include/avr/io.h" 2 3
# 256 "/usr/avr/include/avr/io.h" 3
# 1 "/usr/avr/include/avr/iom168p.h" 1 3
# 257 "/usr/avr/include/avr/io.h" 2 3
# 432 "/usr/avr/include/avr/io.h" 3
# 1 "/usr/avr/include/avr/portpins.h" 1 3
# 433 "/usr/avr/include/avr/io.h" 2 3

# 1 "/usr/avr/include/avr/common.h" 1 3
# 435 "/usr/avr/include/avr/io.h" 2 3

# 1 "/usr/avr/include/avr/version.h" 1 3
# 437 "/usr/avr/include/avr/io.h" 2 3


# 1 "/usr/avr/include/avr/fuse.h" 1 3
# 239 "/usr/avr/include/avr/fuse.h" 3
typedef struct
{
    unsigned char low;
    unsigned char high;
    unsigned char extended;
} __fuse_t;
# 440 "/usr/avr/include/avr/io.h" 2 3


# 1 "/usr/avr/include/avr/lock.h" 1 3
# 443 "/usr/avr/include/avr/io.h" 2 3
# 28 "libavrserial_priv.h" 2
# 1 "/usr/avr/include/util/setbaud.h" 1 3
# 29 "libavrserial_priv.h" 2

typedef enum serial_op_mode {
 ASYNC_NORMAL = 0x01,
 ASYNC_DOUBLE,
 SYNC_MASTER
} serial_op_mode_t;


typedef enum serial_enable_rxtx {
 ENA_RX = 0x01,
 ENA_TX,
 ENA_ALL
} serial_enable_rxtx_t;





void
serial_setup_usart(serial_op_mode_t op_mode,
     serial_frame_type_t frame_type,
     serial_enable_rxtx_t ena_rxtx);
# 10 "libavrserial.c" 2






void
serial_setup_async_normal_mode(serial_frame_type_t frame_type)
{
 serial_setup_usart(ASYNC_NORMAL,
      frame_type,
      ENA_ALL);
}






void
serial_setup_async_double_speed(serial_frame_type_t frame_type)
{
 serial_setup_usart(ASYNC_DOUBLE,
      frame_type,
      ENA_ALL);
}






void
serial_setup_sync_master(serial_frame_type_t frame_type)
{
        serial_setup_usart(SYNC_MASTER,
      frame_type,
      ENA_ALL);
}
# 60 "libavrserial.c"
void
serial_setup_usart(serial_op_mode_t op_mode,
     serial_frame_type_t frame_type,
     serial_enable_rxtx_t ena_rxtx)
{
# 75 "libavrserial.c"
 (*(volatile uint8_t *)(0xC5)) = ((((1000000UL) + 4UL * (9600)) / (8UL * (9600)) -1UL) >> 8);
 (*(volatile uint8_t *)(0xC4)) = ((((1000000UL) + 4UL * (9600)) / (8UL * (9600)) -1UL) & 0xff);


 switch (op_mode) {
 case ASYNC_NORMAL:
  (*(volatile uint8_t *)(0xC0)) &= ~(1 << 1);

  break;
 case ASYNC_DOUBLE:
  (*(volatile uint8_t *)(0xC0)) &= ~(1 << 1);
  break;
 case SYNC_MASTER:






  break;
 default:

  (*(volatile uint8_t *)(0xC0)) &= ~(1 << 1);

 }


 switch (ena_rxtx) {
 case ENA_ALL:
  (*(volatile uint8_t *)(0xC1)) = (1 << 3) | (1 << 4);
  break;
 case ENA_RX:
  (*(volatile uint8_t *)(0xC1)) = (1 << 4);
  (*(volatile uint8_t *)(0xC1)) &= ~(1 << 3);
  break;
 case ENA_TX:
  (*(volatile uint8_t *)(0xC1)) = (1 << 3);
  (*(volatile uint8_t *)(0xC1)) &= ~(1 << 4);
  break;
 default:

  (*(volatile uint8_t *)(0xC1)) = (1 << 3) | (1 << 4);
 }

}
