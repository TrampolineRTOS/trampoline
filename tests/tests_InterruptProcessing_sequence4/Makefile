include ../../Make-rules

CFLAGS += -I../embUnit/ -I. -I../../os/

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../$(AUTOSAR_PATH) -I../embUnit/
endif

#Add your source files here.
ISR4_SRCS = tests_InterruptProcessing_sequence4.c task1_instance.c isr2_instance.c isr3_instance.c

#CFLAGS already defined in ../../Make-rules
ISR4FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:
	
#################### end of configuration.
 
O_PATH = ../../$(OBJ_PATH)
ISR4_OBJS = $(addprefix $(O_PATH)/,$(ISR4_SRCS:.c=.o))

ISR4FLAGS += -I. -I../../$(OS_PATH) -I../../$(OS_MACHINE_PATH) -I../../$(OIL_OUTPUT_PATH)

APP: $(ISR4_OBJS)
	-@cd ../embUnit		;$(MAKE) all

$(O_PATH)/%.o: %.c
	$(CC) $(ISR4FLAGS) -c $< -o $@
