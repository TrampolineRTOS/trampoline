include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
TASK8_SRCS = tests_tasksManagement_sequence8.c task1_instance1.c task1_instance2.c task2_instance.c

#CFLAGS already defined in ../../Make-rules
TASK8FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:
	
#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
TASK8_OBJS = $(addprefix $(O_PATH)/,$(TASK8_SRCS:.c=.o))

TASK8FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(TASK8_OBJS)
	-@cd ../embUnit		;$(MAKE) all

$(O_PATH)/%.o: %.c
	$(CC) $(TASK8FLAGS) -c $< -o $@
