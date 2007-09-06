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
AD_SRCS = tpl_machine_libpcl.c tpl_viper_interface.c 

#################### end of configuration.
O_PATH = ../../../$(OBJ_PATH)
AD_OBJS = $(addprefix $(O_PATH)/,$(AD_SRCS:.c=.o))

CFLAGS += -I../.. -I../../../$(OIL_OUTPUT_PATH) -I. -I../../../$(VIPER_PATH) 

$(O_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

ad:	$(AD_OBJS)

clean:
	

