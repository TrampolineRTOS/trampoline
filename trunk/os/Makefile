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
O_DIR = ../$(OBJ_DIR)

OS_OBJS = $(addprefix $(O_DIR)/,$(OS_SRCS:.c=.o))

#M4 preprocessor file
M4_OS_SCRIPT= ../$(OS_MACHINE_DIR)/tpl_$(ARCH)_macros.m4 tpl_os_macros.m4

#File prefix of generated file (.c and .h)
M4GENERATEDFILEPREFIX = ../$(APP_DIR)/tpl_os_generated_configuration

CFLAGS += -I../$(OS_MACHINE_DIR) -I. -I.. -I../$(APP_DIR)
OS_OBJS = $(addprefix $(O_DIR)/,$(notdir $(OS_SRCS:.c=.o)))

#this file must be generated directly by the user app.
#OS_SRCS += $(M4GENERATEDFILEPREFIX).c


OS: $(OS_OBJS) AD
	

$(O_DIR)/%.o: %.c $(M4GENERATEDFILEPREFIX).c
	$(CC) $(CFLAGS) -c $< -o $@

$(M4GENERATEDFILEPREFIX).h: $(M4_OS_SCRIPT) ../$(M4FILE)
	m4 -Dheader $(M4_OS_SCRIPT) ../$(M4FILE) > $(M4GENERATEDFILEPREFIX).h 

$(M4GENERATEDFILEPREFIX).c: $(M4GENERATEDFILEPREFIX).h $(M4_OS_SCRIPT) ../$(M4FILE)
	m4 $(M4_OS_SCRIPT) ../$(M4FILE) > $(M4GENERATEDFILEPREFIX).c

AD: 
	@cd ../$(OS_MACHINE_DIR) && make ad

clean:
	
