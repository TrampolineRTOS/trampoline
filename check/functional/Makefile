#
# Trampoline OS
#
# Trampoline is copyright (c) IRCCyN 2005+
# Trampoline is protected by the French intellectual property law.
#
# This software is distributed under the Lesser GNU Public Licence
#
# $Date: 2008-02-22 15:39:51 +0100 (Fri, 22 Feb 2008) $
# $Rev: 422 $
# $Author: mik $
# $URL: https://trampoline.rts-software.org/svn/trunk/os/Makefile $
#

include ../Make-rules

ifeq ($(AUTOSAR),true)
  CFLAGS += -I../$(AUTOSAR_PATH)
endif

#kernel OS files
CHECK_SRCS = tc_check.c

#################### end of configuration.
O_PATH = ../$(OBJ_PATH)

CFLAGS += -I../$(OS_PATH) -I../$(OS_MACHINE_PATH) -I. -I../$(OIL_OUTPUT_PATH) -I../$(DEBUG_PATH)
CHECK_OBJS = $(patsubst %, $(O_PATH)/%.o, $(CHECK_SRCS))
#OS_OBJS = $(addprefix $(O_PATH)/,$(notdir $(OS_SRCS:.c=.o)))

check: $(CHECK_OBJS)
	@echo "Checking Trampoline"
	@sh test_all


$(O_PATH)/%.c.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

