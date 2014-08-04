# 1 "my_ext_ctrl_modul.c"
# 1 "/home/jto2si/avr_sdk/projects/my_ext_ctrl_modul//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "my_ext_ctrl_modul.c"
# 21 "my_ext_ctrl_modul.c"
# 1 "my_ext_ctrl_modul.h" 1
# 22 "my_ext_ctrl_modul.h"
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 1 3
# 99 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/sfr_defs.h" 1 3
# 126 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/sfr_defs.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/inttypes.h" 1 3
# 37 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/inttypes.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/include/stdint.h" 1 3 4


# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 1 3 4
# 121 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 3 4
typedef int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));

typedef int int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int uint64_t __attribute__((__mode__(__DI__)));
# 142 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 3 4
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 159 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 3 4
typedef int8_t int_least8_t;




typedef uint8_t uint_least8_t;




typedef int16_t int_least16_t;




typedef uint16_t uint_least16_t;




typedef int32_t int_least32_t;




typedef uint32_t uint_least32_t;







typedef int64_t int_least64_t;






typedef uint64_t uint_least64_t;
# 213 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 3 4
typedef int8_t int_fast8_t;




typedef uint8_t uint_fast8_t;




typedef int16_t int_fast16_t;




typedef uint16_t uint_fast16_t;




typedef int32_t int_fast32_t;




typedef uint32_t uint_fast32_t;







typedef int64_t int_fast64_t;






typedef uint64_t uint_fast64_t;
# 273 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 3 4
typedef int64_t intmax_t;




typedef uint64_t uintmax_t;
# 4 "/usr/lib/gcc/avr/4.5.3/include/stdint.h" 2 3 4
# 38 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/inttypes.h" 2 3
# 77 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/inttypes.h" 3
typedef int32_t int_farptr_t;



typedef uint32_t uint_farptr_t;
# 127 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/sfr_defs.h" 2 3
# 100 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3
# 206 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/iom32.h" 1 3
# 207 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3
# 432 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/portpins.h" 1 3
# 433 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3

# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/common.h" 1 3
# 435 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3

# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/version.h" 1 3
# 437 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3


# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/fuse.h" 1 3
# 248 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/fuse.h" 3
typedef struct
{
    unsigned char low;
    unsigned char high;
} __fuse_t;
# 440 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3


# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/lock.h" 1 3
# 443 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3
# 23 "my_ext_ctrl_modul.h" 2


# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay.h" 1 3
# 43 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay_basic.h" 1 3
# 40 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay_basic.h" 3
static inline void _delay_loop_1(uint8_t __count) __attribute__((always_inline));
static inline void _delay_loop_2(uint16_t __count) __attribute__((always_inline));
# 80 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay_basic.h" 3
void
_delay_loop_1(uint8_t __count)
{
 __asm__ volatile (
  "1: dec %0" "\n\t"
  "brne 1b"
  : "=r" (__count)
  : "0" (__count)
 );
}
# 102 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay_basic.h" 3
void
_delay_loop_2(uint16_t __count)
{
 __asm__ volatile (
  "1: sbiw %0,1" "\n\t"
  "brne 1b"
  : "=w" (__count)
  : "0" (__count)
 );
}
# 44 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay.h" 2 3
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 1 3
# 127 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 3
extern double cos(double __x) __attribute__((__const__));





extern double sin(double __x) __attribute__((__const__));





extern double tan(double __x) __attribute__((__const__));






extern double fabs(double __x) __attribute__((__const__));






extern double fmod(double __x, double __y) __attribute__((__const__));
# 168 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 3
extern double modf(double __x, double *__iptr);



extern float modff (float __x, float *__iptr);




extern double sqrt(double __x) __attribute__((__const__));





extern double cbrt(double __x) __attribute__((__const__));
# 194 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 3
extern double hypot (double __x, double __y) __attribute__((__const__));







extern double square(double __x) __attribute__((__const__));






extern double floor(double __x) __attribute__((__const__));






extern double ceil(double __x) __attribute__((__const__));
# 234 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 3
extern double frexp(double __x, int *__pexp);







extern double ldexp(double __x, int __exp) __attribute__((__const__));





extern double exp(double __x) __attribute__((__const__));





extern double cosh(double __x) __attribute__((__const__));





extern double sinh(double __x) __attribute__((__const__));





extern double tanh(double __x) __attribute__((__const__));







extern double acos(double __x) __attribute__((__const__));







extern double asin(double __x) __attribute__((__const__));






extern double atan(double __x) __attribute__((__const__));
# 298 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 3
extern double atan2(double __y, double __x) __attribute__((__const__));





extern double log(double __x) __attribute__((__const__));





extern double log10(double __x) __attribute__((__const__));





extern double pow(double __x, double __y) __attribute__((__const__));






extern int isnan(double __x) __attribute__((__const__));
# 333 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 3
extern int isinf(double __x) __attribute__((__const__));






__attribute__((__const__)) static inline int isfinite (double __x)
{
    unsigned char __exp;
    __asm__ (
 "mov	%0, %C1		\n\t"
 "lsl	%0		\n\t"
 "mov	%0, %D1		\n\t"
 "rol	%0		"
 : "=r" (__exp)
 : "r" (__x) );
    return __exp != 0xff;
}






__attribute__((__const__)) static inline double copysign (double __x, double __y)
{
    __asm__ (
 "bst	%D2, 7	\n\t"
 "bld	%D0, 7	"
 : "=r" (__x)
 : "0" (__x), "r" (__y) );
    return __x;
}
# 376 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 3
extern int signbit (double __x) __attribute__((__const__));






extern double fdim (double __x, double __y) __attribute__((__const__));
# 392 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 3
extern double fma (double __x, double __y, double __z) __attribute__((__const__));







extern double fmax (double __x, double __y) __attribute__((__const__));







extern double fmin (double __x, double __y) __attribute__((__const__));






extern double trunc (double __x) __attribute__((__const__));
# 426 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 3
extern double round (double __x) __attribute__((__const__));
# 439 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 3
extern long lround (double __x) __attribute__((__const__));
# 453 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/math.h" 3
extern long lrint (double __x) __attribute__((__const__));
# 45 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay.h" 2 3
# 84 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay.h" 3
static inline void _delay_us(double __us) __attribute__((always_inline));
static inline void _delay_ms(double __ms) __attribute__((always_inline));
# 132 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay.h" 3
void
_delay_ms(double __ms)
{
 uint16_t __ticks;
 double __tmp ;
# 156 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay.h" 3
 __tmp = ((16000000UL) / 4e3) * __ms;
 if (__tmp < 1.0)
  __ticks = 1;
 else if (__tmp > 65535)
 {

  __ticks = (uint16_t) (__ms * 10.0);
  while(__ticks)
  {

   _delay_loop_2(((16000000UL) / 4e3) / 10);
   __ticks --;
  }
  return;
 }
 else
  __ticks = (uint16_t)__tmp;
 _delay_loop_2(__ticks);

}
# 209 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay.h" 3
void
_delay_us(double __us)
{
 uint8_t __ticks;
 double __tmp ;
# 233 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/util/delay.h" 3
 __tmp = ((16000000UL) / 3e6) * __us;
 if (__tmp < 1.0)
  __ticks = 1;
 else if (__tmp > 255)
 {
  _delay_ms(__us / 1000.0);
  return;
 }
 else
  __ticks = (uint8_t)__tmp;
 _delay_loop_1(__ticks);

}
# 26 "my_ext_ctrl_modul.h" 2




# 1 "/home/jto2si/avr_sdk/include/avr_compile_macros.h" 1
# 31 "my_ext_ctrl_modul.h" 2
# 1 "/home/jto2si/avr_sdk/include/libavrhelper.h" 1
# 29 "/home/jto2si/avr_sdk/include/libavrhelper.h"
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 1 3
# 47 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/include/stddef.h" 1 3 4
# 211 "/usr/lib/gcc/avr/4.5.3/include/stddef.h" 3 4
typedef unsigned int size_t;
# 323 "/usr/lib/gcc/avr/4.5.3/include/stddef.h" 3 4
typedef int wchar_t;
# 48 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 2 3
# 68 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
typedef struct {
 int quot;
 int rem;
} div_t;


typedef struct {
 long quot;
 long rem;
} ldiv_t;


typedef int (*__compar_fn_t)(const void *, const void *);
# 106 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern void abort(void) __attribute__((__noreturn__));




extern int abs(int __i) __attribute__((__const__));
# 120 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern long labs(long __i) __attribute__((__const__));
# 143 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern void *bsearch(const void *__key, const void *__base, size_t __nmemb,
       size_t __size, int (*__compar)(const void *, const void *));







extern div_t div(int __num, int __denom) __asm__("__divmodhi4") __attribute__((__const__));





extern ldiv_t ldiv(long __num, long __denom) __asm__("__divmodsi4") __attribute__((__const__));
# 175 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern void qsort(void *__base, size_t __nmemb, size_t __size,
    __compar_fn_t __compar);
# 208 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern long strtol(const char *__nptr, char **__endptr, int __base);
# 242 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern unsigned long strtoul(const char *__nptr, char **__endptr, int __base);
# 254 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern long atol(const char *__s) __attribute__((__pure__));
# 266 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern int atoi(const char *__s) __attribute__((__pure__));
# 278 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern void exit(int __status) __attribute__((__noreturn__));
# 290 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern void *malloc(size_t __size) __attribute__((__malloc__));






extern void free(void *__ptr);




extern size_t __malloc_margin;




extern char *__malloc_heap_start;




extern char *__malloc_heap_end;






extern void *calloc(size_t __nele, size_t __size) __attribute__((__malloc__));
# 338 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern void *realloc(void *__ptr, size_t __size) __attribute__((__malloc__));

extern double strtod(const char *__nptr, char **__endptr);

extern double atof(const char *__nptr);
# 364 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern int rand(void);



extern void srand(unsigned int __seed);






extern int rand_r(unsigned long *__ctx);
# 406 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern char *itoa(int __val, char *__s, int __radix);
# 434 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern char *ltoa(long int __val, char *__s, int __radix);
# 460 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern char *utoa(unsigned int __val, char *__s, int __radix);
# 486 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern char *ultoa(unsigned long int __val, char *__s, int __radix);
# 504 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern long random(void);




extern void srandom(unsigned long __seed);







extern long random_r(unsigned long *__ctx);
# 563 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern char *dtostre(double __val, char *__s, unsigned char __prec,
       unsigned char __flags);
# 580 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdlib.h" 3
extern char *dtostrf(double __val, signed char __width,
                     unsigned char __prec, char *__s);
# 30 "/home/jto2si/avr_sdk/include/libavrhelper.h" 2
# 69 "/home/jto2si/avr_sdk/include/libavrhelper.h"
void
helper_convert_ushort_to_string(unsigned char data_string[], unsigned short data);





void
helper_convert_uchar_to_string(unsigned char data_string[], unsigned char data);
# 32 "my_ext_ctrl_modul.h" 2
# 1 "/home/jto2si/avr_sdk/include/libavrserial.h" 1
# 37 "/home/jto2si/avr_sdk/include/libavrserial.h"
typedef enum serial_errors {
 SERIAL_RCV_ERROR = 0x01,
 SERIAL_SEND_ERROR,
 SERIAL_INIT_DEFAULT,
 SERIAL_RCV_DEFAULT,
 SERIAL_SEND_DEFAULT,
 SERIAL_UNKNOWN
} serial_errors_t;
# 91 "/home/jto2si/avr_sdk/include/libavrserial.h"
typedef enum serial_frame_type {
        DATA_8_STOP_1_NO_PARITY = 0x01
} serial_frame_type_t;
# 103 "/home/jto2si/avr_sdk/include/libavrserial.h"
typedef enum serial_send_mode {
 SERIAL_SEND_NORMAL = 0x01,
 SERIAL_SEND_ASCII
} serial_send_mode_t;
# 119 "/home/jto2si/avr_sdk/include/libavrserial.h"
void
serial_setup_async_normal_mode(serial_frame_type_t frame_type);







void
serial_setup_async_double_speed(serial_frame_type_t frame_type);







void
serial_setup_sync_master(serial_frame_type_t frame_type);







void
serial_setup_sync_slave(serial_frame_type_t frame_type);
# 160 "/home/jto2si/avr_sdk/include/libavrserial.h"
unsigned short
serial_receive_data();






unsigned char
serial_receive_byte();






unsigned char *
serial_receive_string(const unsigned char size);
# 190 "/home/jto2si/avr_sdk/include/libavrserial.h"
void
serial_send_data(const unsigned short data);
# 202 "/home/jto2si/avr_sdk/include/libavrserial.h"
void
serial_send_byte(const unsigned char byte,
   serial_send_mode_t mode);







void
serial_send_string(const unsigned char *data);
# 33 "my_ext_ctrl_modul.h" 2
# 1 "/home/jto2si/avr_sdk/include/libavradc.h" 1
# 37 "/home/jto2si/avr_sdk/include/libavradc.h"
typedef enum adc_errors {
 ADC_INIT_DEFAULT = 0x00,
 ADC_UNKNOWN
} adc_errors_t;




typedef enum adc_channels {
 ADC_CH0 = 0x00,
 ADC_CH1
} adc_channels_t;
# 84 "/home/jto2si/avr_sdk/include/libavradc.h"
void
adc_setup_adc(unsigned char adc_channel);
# 34 "my_ext_ctrl_modul.h" 2
# 1 "/home/jto2si/avr_sdk/include/libavrlcd.h" 1
# 48 "/home/jto2si/avr_sdk/include/libavrlcd.h"
typedef enum lcd_errors {
 LCD_SET_CURSOR_DEFAULT = 0x00,
 LCD_LINE_OVERFLOW,
 LCD_UNKNOWN
} lcd_errors_t;





typedef enum lcd_lines {
 LCD_LINE_1 = 0x00,
 LCD_LINE_2,
 LCD_LINE_3,
 LCD_LINE_4
} lcd_lines_t;
# 108 "/home/jto2si/avr_sdk/include/libavrlcd.h"
void
lcd_setup_display(void);







void
lcd_reset_lcd(void);
# 127 "/home/jto2si/avr_sdk/include/libavrlcd.h"
void lcd_clear_display();





void lcd_set_cursor_to_home_pos();





void lcd_set_cursor(unsigned char x, lcd_lines_t line);





void lcd_set_display_off();





void lcd_set_display_on();





void lcd_set_cursor_off();





void lcd_set_cursor_on();
# 173 "/home/jto2si/avr_sdk/include/libavrlcd.h"
void
lcd_send_character(unsigned char data);





void
lcd_send_string(const unsigned char *data);
# 35 "my_ext_ctrl_modul.h" 2
# 1 "/home/jto2si/avr_sdk/include/libavrcyclon.h" 1
# 35 "/home/jto2si/avr_sdk/include/libavrcyclon.h"
void
cyclon_setup_port(void);
# 45 "/home/jto2si/avr_sdk/include/libavrcyclon.h"
void
cyclon_run(const unsigned short count,
    unsigned char starting_led,
    double delay_time);
# 58 "/home/jto2si/avr_sdk/include/libavrcyclon.h"
void
cyclon_double_run(const unsigned short count,
    double delay_time);
# 36 "my_ext_ctrl_modul.h" 2
# 46 "my_ext_ctrl_modul.h"
extern unsigned char serial_errno;





extern unsigned char adc_errno;





extern unsigned char lcd_errno;
# 22 "my_ext_ctrl_modul.c" 2
# 48 "my_ext_ctrl_modul.c"
unsigned char state_of_template = 0x00;





void
__attribute__((noinline)) init_template(void)
{

 ((*(volatile uint8_t *)(((uint16_t) &((*(volatile uint8_t *)((0x17) + 0x20)))))) |= (1 << 0));
}





void
error_indication(const unsigned char *error_string)
{




   if (state_of_template & 0x08) {


 } else {
  while (1) {
   ((*(volatile uint8_t *)(((uint16_t) &((*(volatile uint8_t *)((0x18) + 0x20)))))) |= (1 << 0));
   _delay_ms(100);

   ((*(volatile uint8_t *)(((uint16_t) &((*(volatile uint8_t *)((0x18) + 0x20)))))) &= ~(1 << 0));
   _delay_ms(100);
  }
 }
}




int
__attribute__((OS_main)) main(void)
{






 const unsigned char greeting_string[] = "hello ... i'm an atmega32";
 const unsigned char error_string[] = "an error occured ... pls check";
 unsigned char data_string[5];

 memset(data_string, 0, sizeof(data_string));
# 138 "my_ext_ctrl_modul.c"
 lcd_setup_display();
 if (lcd_errno != 0)
  error_indication(error_string);


 state_of_template |= 0x08;
 lcd_send_string(greeting_string);
# 181 "my_ext_ctrl_modul.c"
 init_template();
# 198 "my_ext_ctrl_modul.c"
 _delay_ms(5 * 1000);

 lcd_set_cursor_to_home_pos();
 _delay_ms(5 * 1000);

 lcd_set_display_off();
 _delay_ms(5 * 1000);
 lcd_set_display_on();
 _delay_ms(5 * 1000);
 lcd_set_cursor_off();

 _delay_ms(5 * 1000);
 lcd_clear_display();
 _delay_ms(5 * 1000);
 lcd_set_cursor_on();



 while (1) {


  ((*(volatile uint8_t *)(((uint16_t) &((*(volatile uint8_t *)((0x18) + 0x20)))))) |= (1 << 0));
  _delay_ms(1000);


  ((*(volatile uint8_t *)(((uint16_t) &((*(volatile uint8_t *)((0x18) + 0x20)))))) &= ~(1 << 0));
  _delay_ms(1000);

 }
}
