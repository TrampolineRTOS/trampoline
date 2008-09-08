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

include ../../../Make-rules

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../../../$(AUTOSAR_PATH) -I../../../$(DEBUG_PATH)
endif

#kernel OS architecture dependant files
AD_SRCS = tpl_machine_h8300h.c  tpl_machine.h8h

#################### end of configuration.
O_PATH = ../../../$(OBJ_PATH)
AD_OBJS = $(patsubst %, $(O_PATH)/%.o, $(AD_SRCS))
#AD_OBJS = $(addprefix $(O_PATH)/,$(AD_SRCS:.c=.o))

CFLAGS += -I../.. -I../../../$(OIL_OUTPUT_PATH) -I.

$(O_PATH)/%.c.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(O_PATH)/%.h8h.o: %.h8h
	$(AS) $< -o $@

ad:	$(AD_OBJS)

clean:
	

