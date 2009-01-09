include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
ISR3_SRCS = tests_InterruptProcessing_sequence3.c task1_instance.c isr2_instance.c isr3_instance.c

#CFLAGS already defined in ../../Make-rules
ISR3FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:
	
#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
ISR3_OBJS = $(addprefix $(O_PATH)/,$(ISR3_SRCS:.c=.o))

ISR3FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(ISR3_OBJS)
	-@cd ../embUnit		;$(MAKE) all

$(O_PATH)/%.o: %.c
	$(CC) $(ISR3FLAGS) -c $< -o $@
