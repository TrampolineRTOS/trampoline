CC = gcc
CFLAGS = -O
AR = ar
ARFLAGS = ru
RANLIB = ranlib

$(TARGET): $(OBJS) makedestdir
	$(AR) $(ARFLAGS) $(OUTPUT)$@ $(OBJS)
	$(RANLIB) $(OUTPUT)$@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

