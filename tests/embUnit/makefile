include ../../Make-rules

ARFLAGS = ru
OUTPUT = ../lib/
BIN = libembUnit.a
TEST_OBJS = AssertImpl.o RepeatedTest.o stdImpl.o TestCaller.o TestCase.o TestResult.o TestRunner.o TestSuite.o TestPrint.o

O_PATH = ../../$(OBJ_PATH)
AD_OBJS = $(addprefix $(O_PATH)/,$(TEST_OBJS))

CFLAGS += -I. -I../TestGN/

all: $(BIN) 

$(BIN): $(AD_OBJS)
	$(AR) $(ARFLAGS) $(OUTPUT)$@ $(AD_OBJS)
	$(RANLIB) $(OUTPUT)$@

$(O_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Specific rule to build architecture dependent function
# to print output (TestPrint.c, should be located into
# $(ARCH) subdirectory)
$(O_PATH)/%.o: $(ARCH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-$(RM) $(AD_OBJS) $(BIN)

.PHONY: clean all
