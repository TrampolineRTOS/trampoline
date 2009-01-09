include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
TASK1_SRCS = tests_tasksManagement_sequence1.c task1_instance.c task2_instance.c isr1_instance.c isr2_instance.c

#CFLAGS already defined in ../../Make-rules
TASK1FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:
	
#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
TASK1_OBJS = $(addprefix $(O_PATH)/,$(TASK1_SRCS:.c=.o))

TASK1FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(TASK1_OBJS)
	-@cd ../embUnit		;$(MAKE) all

$(O_PATH)/%.o: %.c
	$(CC) $(TASK1FLAGS) -c $< -o $@
