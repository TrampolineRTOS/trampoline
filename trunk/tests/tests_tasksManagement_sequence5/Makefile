include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
TASK5_SRCS = tests_tasksManagement_sequence5.c task1_instance.c task2_instance.c task3_instance.c

#CFLAGS already defined in ../../Make-rules
TASK5FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:
	
#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
TASK5_OBJS = $(addprefix $(O_PATH)/,$(TASK5_SRCS:.c=.o))

TASK5FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(TASK5_OBJS)
	-@cd ../embUnit		;$(MAKE) all

$(O_PATH)/%.o: %.c
	$(CC) $(TASK5FLAGS) -c $< -o $@
