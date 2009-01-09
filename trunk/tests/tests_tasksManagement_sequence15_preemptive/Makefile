include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
TASK15_SRCS = tests_tasksManagement_sequence15.c task1_instance.c

#CFLAGS already defined in ../../Make-rules
TASK15FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:
	
#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
TASK15_OBJS = $(addprefix $(O_PATH)/,$(TASK15_SRCS:.c=.o))

TASK15FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(TASK15_OBJS)
	-@cd ../embUnit		;$(MAKE) all

$(O_PATH)/%.o: %.c
	$(CC) $(TASK15FLAGS) -c $< -o $@
