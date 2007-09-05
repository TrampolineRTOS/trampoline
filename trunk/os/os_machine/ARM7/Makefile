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
  CFLAGS += -I../$(AUTOSAR_PATH)
endif

AD_OBJS = tpl_machine_arm7.o tpl_machine_arm7_asm.o
O_DIR = ../../../$(OBJ_DIR)

ASMFLAGS += -I../.. -I.

$(O_DIR)/%.o: %.c
	$(CC) $(ASMFLAGS) -c $< -o $@

$(O_DIR)/%.o: %.s
	$(AS) $(ASMFLAGS) $< -o $@	
	
ad:	$(AD_OBJS)

clean:
	@rm -vf $(AD_OBJS)
