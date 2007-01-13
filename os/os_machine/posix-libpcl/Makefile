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

O_DIR = ../../../$(OBJ_DIR)

#kernel OS architecture dependant files
AD_SRCS = tpl_machine_libpcl.c tpl_viper_interface.c 

#################### end of configuration.
AD_OBJS = $(addprefix $(O_DIR)/,$(AD_SRCS:.c=.o))

ASMFLAGS += -I../.. -I. -I../../../viper

$(O_DIR)/%.o: %.c 
	$(CC) $(ASMFLAGS) $(CFLAGS) $(PAPP) -c $< -o $@

ad:	$(AD_OBJS) 


clean:
	
