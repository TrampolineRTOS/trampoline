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

#Add your source files here.
APP_SRCS = tpl_default_tasks_workstation.c tpl_os_generated_configuration.c

#################### end of configuration.
O_DIR = ../$(OBJ_DIR)
APP_OBJS = $(addprefix $(O_DIR)/,$(APP_SRCS:.c=.o))

CFLAGS += -I. -I../$(OS_DIR) -I../$(OS_MACHINE_DIR)

APP: $(APP_OBJS)
	
$(O_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# remove object files and tpl_os_generated_configuration.* 
clean:
	@rm -vf tpl_os_generated_configuration.c tpl_os_generated_configuration.h