include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
TASK7_SRCS = tests_tasksManagement_sequence7.c task1_instance1.c task1_instance2.c

#CFLAGS already defined in ../../Make-rules
TASK7FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:


#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
TASK7_OBJS = $(addprefix $(O_PATH)/,$(TASK7_SRCS:.c=.o))

TASK7FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(TASK7_OBJS)
	-@cd ../embUnit		;$(MAKE) all
	
$(O_PATH)/%.o: %.c
	$(CC) $(TASK7FLAGS) -c $< -o $@
