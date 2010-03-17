
AR=arm-none-eabi-ar
RANLIB=arm-none-eabi-ranlib
CC=arm-none-eabi-gcc -c

TRAMPOLINE_ROOT = ../../../..

CFLAGS += -mcpu=arm7tdmi -I. -I$(TRAMPOLINE_ROOT)/machines/arm/simtec-eb675001/default_drivers

CFLAGS_DEBUG = $(CFLAGS) -g
ASFLAGS_DEBUG = $(ASFLAGS) -g

STATIC_LIB_NAME = libsimtec-userdrivers
DEBUG_SUFFIX = -dbg

STATIC_LIB = $(STATIC_LIB_NAME).a
STATIC_DEBUG_LIB = $(STATIC_LIB_NAME)$(DEBUG_SUFFIX).a

SOURCES = gpio_suffix.c uart_suffix.c 
OBJS = $(SOURCES:%_suffix.c=%.o)
DEBUG_OBJS = $(SOURCES:%_suffix.c=%$(DEBUG_SUFFIX).o)

.PHONY: all
all: $(STATIC_LIB) $(STATIC_DEBUG_LIB)

.PHONY: clean
clean:
	rm -f *.o

.PHONY: mrproper
mrproper: clean
	rm -f $(STATIC_LIB) $(STATIC_DEBUG_LIB)

$(STATIC_LIB): $(OBJS)
	$(AR) ru $@ $+
	$(RANLIB) $@

$(STATIC_DEBUG_LIB): $(DEBUG_OBJS)
	$(AR) ru $@ $+
	$(RANLIB) $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

%$(DEBUG_SUFFIX).o: %.c
	$(CC) $(CFLAGS_DEBUG) -o $@ $<


