CC = gcc -c
LD = gcc
RM = rm -f

CFLAGS = -Wall -g
LDFLAGS = -g

all: decode_mmu_structs

clean:
	$(RM) decode_mmu_structs decode_mmu_structs.o

decode_mmu_structs: decode_mmu_structs.o
	$(LD) $(LDFLAGS) -o $@ $+

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<
