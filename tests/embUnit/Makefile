
OBJ_PATH = .

CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
AR=arm-none-eabi-ar
RANLIB=arm-none-eabi-ranlib

ARFLAGS = ru
OUTPUT = lib
BIN = $(OUTPUT)/libembUnitARM7.a
TEST_OBJS = AssertImpl.o RepeatedTest.o stdImpl.o TestCaller.o TestCase.o TestResult.o TestRunner.o TestSuite.o TestPrint.o

O_PATH = $(OBJ_PATH)
#AD_OBJS = $(addprefix $(O_PATH)/,$(TEST_OBJS)) 
AD_OBJS = $(TEST_OBJS)

CFLAGS += -I. 

all: $(BIN) 

$(BIN): $(AD_OBJS)
	$(AR) $(ARFLAGS) $@ $(AD_OBJS)
	$(RANLIB) $@

$(O_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Specific rule to build architecture dependent function
# to print output (TestPrint.c, should be located into
# $(ARCH) subdirectory)

ARCH=ARM7

$(O_PATH)/%.o: $(ARCH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#SOURCES +=AssertImpl.c RepeatedTest.c stdImpl.c TestCaller.c TestCase.c TestResult.c TestRunner.c TestSuite.c 


# a voir  
#ifeq ($(TARGET), ARM7)
#SOURCES +=TestPrint.c
#else

#endif
