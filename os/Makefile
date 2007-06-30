#
# Trampoline OS
#
# Trampoline is copyright (c) IRCCyN 2005+
# Trampoline is protected by the French intellectual property law.
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
tpl_os.c \
tpl_os_error.c  \
tpl_os_event.c \
tpl_os_task.c \
tpl_os_alarm.c  \
tpl_os_it.c  \
tpl_os_rez.c \
tpl_os_kernel.c \
tpl_os_action.c \
tpl_os_alarm_kernel.c \
tpl_os_it_kernel.c \
tpl_os_rez_kernel.c

#################### end of configuration.
O_PATH = ../$(OBJ_PATH)

CFLAGS += -I../$(OS_MACHINE_PATH) -I. -I../$(OIL_OUTPUT_PATH) -I../$(DEBUG_PATH)
OS_OBJS = $(addprefix $(O_PATH)/,$(notdir $(OS_SRCS:.c=.o)))

OS: $(OS_OBJS) AD
	

$(O_PATH)/%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

AD: 
	@cd ../$(OS_MACHINE_PATH) && make ad

clean:
	
