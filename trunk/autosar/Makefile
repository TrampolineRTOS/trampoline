#
# Trampoline OS
#
# Trampoline is copyright (c) IRCCyN 2005-2007
# Autosar extension is copyright (c) IRCCyN and ESEO 2007
# Trampoline est protégé par la loi sur la propriété intellectuelle
#
# This software is distributed under the Lesser GNU Public Licence
#
# $Date$
# $Rev$
# $Author$
# $URL$
#

include ../Make-rules

#kernel AUTOSAR files
AUTOSAR_SRCS += tpl_as_schedtable.c
AUTOSAR_SRCS += tpl_as_timing_protec.c
AUTOSAR_SRCS += tpl_as_protec_hook.c
AUTOSAR_SRCS += tpl_as_stack_monitor.c
AUTOSAR_SRCS += tpl_as_st_kernel.c
AUTOSAR_SRCS += tpl_as_isr.c
AUTOSAR_SRCS += tpl_as_isr_kernel.c
AUTOSAR_SRCS += tpl_as_watchdog_kernel.c
AUTOSAR_SRCS += tpl_as_isr.c
AUTOSAR_SRCS += tpl_as_counter.c
AUTOSAR_SRCS += tpl_as_action.c


#################### end of configuration.
O_PATH = ../$(OBJ_PATH)

CFLAGS += -I../$(OS_PATH) -I../$(OS_MACHINE_PATH) -I../$(OIL_OUTPUT_PATH) -I../$(DEBUG_PATH) -I.
AUTOSAR_OBJS = $(patsubst %, $(O_PATH)/%.o, $(notdir $(AUTOSAR_SRCS)))
#AUTOSAR_OBJS = $(addprefix $(O_PATH)/,$(notdir $(AUTOSAR_SRCS:.c=.o)))

AUTOSAR: $(AUTOSAR_OBJS)
	

$(O_PATH)/%.c.o: %.c #$(M4GENERATEDFILEPREFIX).c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	
