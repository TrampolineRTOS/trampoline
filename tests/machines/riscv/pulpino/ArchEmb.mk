CC = riscv32-unknown-elf-gcc
CFLAGS = -O
AR = riscv32-unknown-elf-ar
ARFLAGS = ru
RANLIB = riscv32-unknown-elf-ranlib

$(TARGET): $(OBJS) makedestdir
	$(AR) $(ARFLAGS) $(OUTPUT)$@ $(OBJS)
	$(RANLIB) $(OUTPUT)$@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

