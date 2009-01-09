include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
TESTGN_SRCS = test_tasks.c

#CFLAGS already defined in ../../Make-rules
TESTGNFLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:


#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
TESTGN_OBJS = $(addprefix $(O_PATH)/,$(TESTGN_SRCS:.c=.o))

TESTGNFLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(TESTGN_OBJS)
	-@cd ../embUnit		;$(MAKE) all
	
$(O_PATH)/%.o: %.c
	$(CC) $(TESTGNFLAGS) -c $< -o $@
