CC = arm-none-eabi-gcc
CFLAGS += -mcpu=cortex-m3
CFLAGS += -mthumb
CFLAGS += -mfloat-abi=soft
CFLAGS += -DNO_STDIO_PRINTF
AR = arm-none-eabi-ar
ARFLAGS = -cr

ifndef ARCH_CUSTOM_SOURCE
  $(error ARCH_CUSTOM_SOURCE is not set)
endif

ARCH_CUSTOM_OBJ = $(notdir $(ARCH_CUSTOM_SOURCE:.c=.o))
OBJS += $(ARCH_CUSTOM_OBJ)

$(ARCH_CUSTOM_OBJ) : $(ARCH_CUSTOM_SOURCE) config.h
		$(CC) $(CFLAGS) $(INCLUDES) -c $(ARCH_CUSTOM_SOURCE) -o $(ARCH_CUSTOM_OBJ)

$(TARGET): $(OBJS) makedestdir
	$(AR) $(ARFLAGS) $(OUTPUT)$@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

