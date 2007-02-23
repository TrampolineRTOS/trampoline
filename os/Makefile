#
# Trampoline OS
#
# Trampoline is copyright (c) IRCCyN 2005+
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

#kernel OS files
OS_SRCS = \
tpl_os_error.c  \
tpl_os_alarm_management.c  \
tpl_os_event_management.c \
tpl_os_interrupts.c \
tpl_os_kernel.c \
tpl_os_resources_management.c \
tpl_os_task_management.c \
tpl_os.c

#################### end of configuration.
O_PATH = ../$(OBJ_PATH)

CFLAGS += -I../$(OS_MACHINE_PATH) -I. -I../$(OIL_OUTPUT_PATH)
OS_OBJS = $(addprefix $(O_PATH)/,$(notdir $(OS_SRCS:.c=.o)))

OS: $(OS_OBJS) AD
	

$(O_PATH)/%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

AD: 
	@cd ../$(OS_MACHINE_PATH) && make ad

clean:
	
