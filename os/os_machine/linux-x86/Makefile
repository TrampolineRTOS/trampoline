#
# Trampoline OS
#
# Trampoline is copyright (c) IRCCyN 2005+
# Trampoline est protege par la loi sur la propriete intellectuelle
#
# This software is distributed under the Lesser GNU Public Licence
#
# $Date$
# $Rev$
# $Author$
# $URL$
#

include ../../../Make-rules

#kernel OS architecture dependant files
AD_SRCS = tpl_machine_linux-x86.c tpl_viper_interface.c 
ASM_SRCS = tpl_ctx_switch.s

#################### end of configuration.
O_DIR = ../../../$(OBJ_DIR)
AD_OBJS = $(addprefix $(O_DIR)/,$(AD_SRCS:.c=.o))
ASM_OBJS = $(addprefix $(O_DIR)/,$(ASM_SRCS:.s=.o))

ASMFLAGS += -I../.. -I. -I../../../viper

$(O_DIR)/%.o: %.c
	$(CC) $(ASMFLAGS) -c $< -o $@

$(O_DIR)/%.o: %.s
	$(CC) $(ASMFLAGS) -c $< -o $@

ad:	$(AD_OBJS) $(ASM_OBJS)

clean:
	
