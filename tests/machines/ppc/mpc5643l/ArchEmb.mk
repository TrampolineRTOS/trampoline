CC = ../../examples/ppc/tools/cxvle_auto.py
CFLAGS += -DNO_STDIO_PRINTF
AR = clib
ARFLAGS = -c

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

