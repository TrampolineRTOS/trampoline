# 
# viper
# 
#  viper is copyright (c) IRCCyN 2005+
#  viper est protege par la loi sur la propriete intellectuelle
# 
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  $Date: 2005-10-19 13:23:49 +0200 (Wed, 19 Oct 2005) $
#  $Rev: 22 $
#  $Author: mik $
#  $URL$
#  $Id: Makefile 22 2005-10-19 11:23:49Z mik $

#arch may be either LINUX or DARWIN (MacOsX) at this time.
ARCH = $(shell uname -s)
SRCS= com.c exec.c log.c main.c timer.c control.c
CFLAGS += -fcommon

########################################################
# ARCH dependant stuff
########################################################
#Darwin does not require to be linked to these libraries 
ifeq ($(strip $(ARCH)),Linux)
	LDFLAGS = -lpthread -lrt
	CFLAGS += -DLINUX
endif
ifeq ($(strip $(ARCH)),Darwin)
	CFLAGS += -DDARWIN
endif


########################################################
OBJ_DIR = .obj

EXE = viper

OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

ALL: OBJ_DIR_CREATE $(EXE) 

$(EXE): $(OBJ) 
	$(CC) -o $@ $(OBJ) $(LDFLAGS) 

$(OBJ_DIR)/%.o: %.c 
	$(CC) -c $(CFLAGS) $< -o $@

OBJ_DIR_CREATE: 
	@if [ ! -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi;

clean:
	@rm -rf $(OBJ_DIR)/ *~

dist-clean: clean
	@rm -rf $(EXE) build/
