CC = gcc
CFLAGS = -O
AR = ar
ARFLAGS = ru
RANLIB = ranlib
RM = rm
CP = cp
OUTPUT = ../lib/
TARGET = libembUnit.a
OBJS = AssertImpl.o RepeatedTest.o stdImpl.o TestCaller.o TestCase.o TestResult.o TestRunner.o TestSuite.o SchedulingCheck.o

ifneq ($(strip $(ARCH_CUSTOM_SOURCE)),)
 ARCH_CUSTOM_OBJ = $(notdir $(ARCH_CUSTOM_SOURCE:.c=.o))
 CFLAGS += -DNO_STDIO_PRINTF
 OBJS += $(ARCH_CUSTOM_OBJ)
endif

all: $(TARGET)

$(TARGET): $(OBJS) makedestdir
	$(AR) $(ARFLAGS) $(OUTPUT)$@ $(OBJS)
	$(RANLIB) $(OUTPUT)$@

makedestdir:
	mkdir -p $(OUTPUT)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

AssertImpl.o: AssertImpl.h stdImpl.h
RepeatedTest.o: RepeatedTest.h Test.h
stdImpl.o: stdImpl.h
TestCaller.o: TestCaller.h TestResult.h TestListener.h TestCase.h Test.h
TestCase.o: TestCase.h TestResult.h TestListener.h Test.h
TestResult.o: TestResult.h TestListener.h Test.h
TestRunner.o: TestRunner.h TestResult.h TestListener.h Test.h stdImpl.h config.h
TestSuite.o: TestSuite.h TestResult.h TestListener.h Test.h
SchedulingCheck.o: SchedulingCheck.h TestRunner.h Test.h config.h AssertImpl.h

ifneq ($(strip $(ARCH_CUSTOM_SOURCE)),)
  $(ARCH_CUSTOM_OBJ) : $(ARCH_CUSTOM_SOURCE) config.h
		$(CC) $(CFLAGS) $(INCLUDES) -c $<
endif

clean:
	-$(RM) -f $(OBJS) $(OUTPUT)$(TARGET)

.PHONY: clean all
