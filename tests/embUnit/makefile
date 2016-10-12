RM = rm
CP = cp
OUTPUT = ../lib/
TARGET = libembUnit.a
OBJS = AssertImpl.o RepeatedTest.o stdImpl.o TestCaller.o TestCase.o TestResult.o TestRunner.o TestSuite.o SchedulingCheck.o

all: $(TARGET)

-include ArchEmb.mk

AssertImpl.o: AssertImpl.h stdImpl.h
RepeatedTest.o: RepeatedTest.h Test.h
stdImpl.o: stdImpl.h
TestCaller.o: TestCaller.h TestResult.h TestListener.h TestCase.h Test.h
TestCase.o: TestCase.h TestResult.h TestListener.h Test.h
TestResult.o: TestResult.h TestListener.h Test.h
TestRunner.o: TestRunner.h TestResult.h TestListener.h Test.h stdImpl.h config.h
TestSuite.o: TestSuite.h TestResult.h TestListener.h Test.h
SchedulingCheck.o: SchedulingCheck.h TestRunner.h Test.h config.h AssertImpl.h

makedestdir:
	mkdir -p $(OUTPUT)

clean:
	-$(RM) -f $(OBJS) $(OUTPUT)$(TARGET)

.PHONY: clean makedestdir all

