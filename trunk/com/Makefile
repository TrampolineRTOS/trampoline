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
COM_SRCS = \
tpl_com_app_copy.c  \
tpl_com_filtering.c  \
tpl_com_filters.c \
tpl_com_internal_com.c \
tpl_com_notification.c \
tpl_com_queue.c \
tpl_com_message_management.c

#################### end of configuration.
O_PATH = ../$(OBJ_PATH)

#COM_OBJS = $(addprefix $(O_DIR)/,$(COM_SRCS:.c=.o))

#M4 preprocessor file
#M4_OS_SCRIPT= ../$(OS_MACHINE_DIR)/tpl_$(ARCH)_macros.m4 tpl_os_macros.m4

#File prefix of generated file (.c and .h)
#M4GENERATEDFILEPREFIX = ../$(APP_DIR)/tpl_os_generated_configuration

CFLAGS += -I../os -I../$(OS_MACHINE_PATH) -I../$(OIL_OUTPUT_PATH) -I. 
COM_OBJS = $(addprefix $(O_PATH)/,$(notdir $(COM_SRCS:.c=.o)))

#this file must be generated directly by the user app.
#OS_SRCS += $(M4GENERATEDFILEPREFIX).c


COM: $(COM_OBJS)
	

$(O_PATH)/%.o: %.c #$(M4GENERATEDFILEPREFIX).c
	$(CC) $(CFLAGS) -c $< -o $@

#$(M4GENERATEDFILEPREFIX).h: $(M4_OS_SCRIPT) ../$(M4FILE)
#	m4 -Dheader $(M4_OS_SCRIPT) ../$(M4FILE) > $(M4GENERATEDFILEPREFIX).h 

#$(M4GENERATEDFILEPREFIX).c: $(M4GENERATEDFILEPREFIX).h $(M4_OS_SCRIPT) ../$(M4FILE)
#	m4 $(M4_OS_SCRIPT) ../$(M4FILE) > $(M4GENERATEDFILEPREFIX).c

#AD: 
#	@cd ../$(OS_MACHINE_DIR) && make ad

clean:
	
