#
# Trampoline OS
#
# Trampoline is copyright (c) IRCCyN 2005+
# Trampoline est prot��par la loi sur la propri��intellectuelle
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

#CFLAGS already defined in ../Make-rules
APP_FLAGS = $(CFLAGS)

#################### end of configuration.
O_DIR = ../$(OBJ_DIR)
APP_OBJS = $(addprefix $(O_DIR)/,$(APP_SRCS:.c=.o))

APPFLAGS += -I. -I../$(OS_DIR) -I../$(OS_MACHINE_DIR)

APP: $(APP_OBJS)
	
$(O_DIR)/%.o: %.c
	$(CC) $(APPFLAGS) -c $< -o $@

# remove object files and tpl_os_generated_configuration.* 
clean:
	@rm -vf tpl_os_generated_configuration.c tpl_os_generated_configuration.h