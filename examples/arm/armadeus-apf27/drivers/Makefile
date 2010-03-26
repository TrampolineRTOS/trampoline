
CC = arm-none-eabi-gcc -c
AS = arm-none-eabi-as
LD = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CPU = arm926ej-s

CFLAGS = -Wall -mcpu=$(CPU)
ASFLAGS = -mcpu=$(CPU)
LDFLAGS = -T ldscript --relocatable

OBJS = uart.o generic.o

all: libuart.o

libuart.o: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.s
	$(AS) $(CFLAGS) $< -o $@
