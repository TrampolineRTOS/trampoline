include ../../Make-rules

O_PATH = ../../$(OBJ_PATH)

LIBS = ../lib
BIN = samples
OBJS = AllTests.o taskManagement.o taskManagementTest.o

CFLAGS += -I../embUnit/ -I. -I../../os/
CFLAGS += -I../../$(OS_MACHINE_PATH) -I. -I../../$(OIL_OUTPUT_PATH)
AD_OBJS = $(addprefix $(O_PATH)/,$(OBJS))

all: $(BIN)

$(BIN): $(AD_OBJS)
	$(LD) -o $@ $(AD_OBJS) -L$(LIBS) -lembUnit -lARM7 #-ltextui

$(O_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-$(RM) $(BIN) $(OBJS)

.PHONY: clean all
