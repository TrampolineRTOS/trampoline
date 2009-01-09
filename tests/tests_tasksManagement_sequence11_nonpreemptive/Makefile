include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
TASK11_SRCS = tests_tasksManagement_sequence11.c task1_instance.c task2_instance.c task3_instance.c task4_instance.c

#CFLAGS already defined in ../../Make-rules
TASK11FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:


#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
TASK11_OBJS = $(addprefix $(O_PATH)/,$(TASK11_SRCS:.c=.o))

TASK11FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(TASK11_OBJS)
	-@cd ../embUnit		;$(MAKE) all
	
$(O_PATH)/%.o: %.c
	$(CC) $(TASK11FLAGS) -c $< -o $@
