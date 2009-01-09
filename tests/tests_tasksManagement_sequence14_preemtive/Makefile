include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
TASK14_SRCS = tests_tasksManagement_sequence14.c task1_instance.c task2_instance.c task3_instance.c task4_instance.c task5_instance.c task6_instance.c task7_instance.c task8_instance.c task9_instance.c task10_instance.c task11_instance.c task12_instance.c task13_instance.c task14_instance.c task15_instance.c task16_instance.c

#CFLAGS already defined in ../../Make-rules
TASK14FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:
	
#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
TASK14_OBJS = $(addprefix $(O_PATH)/,$(TASK14_SRCS:.c=.o))

TASK14FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(TASK14_OBJS)
	-@cd ../embUnit		;$(MAKE) all

$(O_PATH)/%.o: %.c
	$(CC) $(TASK14FLAGS) -c $< -o $@
