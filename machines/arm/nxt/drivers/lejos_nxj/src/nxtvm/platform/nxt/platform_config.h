#ifndef _PLATFORM_CONFIG_H
#  define _PLATFORM_CONFIG_H

// Basic types

typedef unsigned char byte;
typedef signed char JBYTE;
typedef signed short JSHORT;
typedef signed long JINT;
typedef unsigned short TWOBYTES;
typedef unsigned long FOURBYTES;

#  include "systime.h"

// Converting words to pointers

#  define ptr2word(PTR_) ((STACKWORD) (PTR_))
#  define word2ptr(WRD_) ((void *) (WRD_))

// Macro to get 4-byte system time, used in sleep.

#  define get_sys_time() get_sys_time_impl()

// Byte order:

#  define LITTLE_ENDIAN 1

// Floating point arithmetic supported?

#  define FP_ARITHMETIC 1

// Are we using the timer IRQ to switch threads? Not yet.

#  define PLATFORM_HANDLES_SWITCH_THREAD 0
#  define TICKS_PER_TIME_SLICE          2

#endif // _PLATFORM_CONFIG_H
