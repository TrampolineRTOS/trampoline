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

ifeq ($(AUTOSAR), true)
CFLAGS += -I../$(AUTOSAR_PATH) -I../$(DEBUG)
endif

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


CFLAGS += -I../os -I../$(OS_MACHINE_PATH) -I../$(OIL_OUTPUT_PATH) -I. 
#COM_OBJS = $(addprefix $(O_PATH)/,$(notdir $(COM_SRCS:.c=.o)))
COM_OBJS = $(patsubst %, $(O_PATH)/%.o, $(COM_SRCS))


COM: $(COM_OBJS)
	

$(O_PATH)/%.c.o: %.c #$(M4GENERATEDFILEPREFIX).c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	
