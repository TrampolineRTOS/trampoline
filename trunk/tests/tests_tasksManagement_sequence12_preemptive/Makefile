include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
TASK12_SRCS = tests_tasksManagement_sequence12.c task1_instance.c

#CFLAGS already defined in ../../Make-rules
TASK12FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:
	
#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
TASK12_OBJS = $(addprefix $(O_PATH)/,$(TASK12_SRCS:.c=.o))

TASK12FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(TASK12_OBJS)
	-@cd ../embUnit		;$(MAKE) all

$(O_PATH)/%.o: %.c
	$(CC) $(TASK12FLAGS) -c $< -o $@
