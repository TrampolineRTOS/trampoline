include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
ISR2_SRCS = tests_InterruptProcessing_sequence2.c task1_instance.c

#CFLAGS already defined in ../../Make-rules
ISR2FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:
	
#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
ISR2_OBJS = $(addprefix $(O_PATH)/,$(ISR2_SRCS:.c=.o))

ISR2FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(ISR2_OBJS)
	-@cd ../embUnit		;$(MAKE) all

$(O_PATH)/%.o: %.c
	$(CC) $(ISR2FLAGS) -c $< -o $@
