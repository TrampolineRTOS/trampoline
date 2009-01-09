include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
TASK10_SRCS = tests_tasksManagement_sequence10.c task1_instance.c task2_instance.c task3_instance.c

#CFLAGS already defined in ../../Make-rules
TASK10FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:
	
#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
TASK10_OBJS = $(addprefix $(O_PATH)/,$(TASK10_SRCS:.c=.o))

TASK10FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(TASK10_OBJS)
	-@cd ../embUnit		;$(MAKE) all

$(O_PATH)/%.o: %.c
	$(CC) $(TASK10FLAGS) -c $< -o $@
