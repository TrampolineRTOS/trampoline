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
# Application specific Makefile.
# This makefile contains files related to the application.
# The OIL file is compiled using rules in the Makefile of 
# the root directory.
#
# 2 rules may be called for this Makefile from the parent Makefile:
# * make APP : it must compile all sources related to the
#   application (except OiL generated files) and put them 
#   into the object directory (using $(OBJ_PATH))
# * make clean : it can be used to clean extra files. 
#   object in $(OBJ_PATH) are already removed
#
# 

include ../Make-rules

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../$(AUTOSAR_PATH)
endif

#Add your source files here.
APP_SRCS = tpl_default_tasks_workstation.c

#CFLAGS already defined in ../Make-rules
APP_FLAGS = $(CFLAGS)

# application specific clean (objects are automatically removed)
clean:
	
#################### end of configuration.
 
O_PATH = ../$(OBJ_PATH)
APP_OBJS = $(addprefix $(O_PATH)/,$(APP_SRCS:.c=.o))

APPFLAGS += -I. -I../$(OS_PATH) -I../$(OS_MACHINE_PATH) -I../$(OIL_OUTPUT_PATH)

APP: $(APP_OBJS)
	
$(O_PATH)/%.o: %.c
	$(CC) $(APPFLAGS) -c $< -o $@

