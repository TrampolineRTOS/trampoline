########################################################
# Variables
########################################################
##
# Commons
##
CFLAGS    += -Wall --std=c99 -D_XOPEN_SOURCE=600 -pedantic 
LDFLAGS   += 
OBJ_dir    = .obj
PYTHON_inc =  $(shell echo /usr/include/python* | tr ' ' '\n' | tail -n1)

##
# Python module (ipc_mod)
##
MODULE_dir     = ipc
MODULE_src     = com.c ipc_mod.c util/fifo.c
MODULE_hdr     = com.h ipc_mod.h util/fifo.h
MODULE_bin     = _ipc.so
MODULE_name    = ipc.py
MODULE_obj_dir = $(OBJ_dir)/$(MODULE_dir)
MODULE_obj     = $(addprefix $(MODULE_obj_dir)/,$(MODULE_src:.c=.o))
MODULE_cflags  = -I$(PYTHON_inc) -I$(MODULE_dir)
MODULE_ldflags = -dynamiclib

##
# CAN
##
CAN_dir = device
CAN_src = tpl_can_driver.c
CAN_obj = $(addprefix $(MODULE_obj_dir)/$(CAN_dir)/,$(CAN_src:.c=.o))
CAN_cflags = -I$(MODULE_dir)
CAN_ldflags =

##
# Trampoline
##
TPL_MOD_src = viper.c
TPL_MOD_hdr = viper.h
TPL_MOD_obj = $(addprefix $(MODULE_obj_dir)/,$(TPL_MOD_src:.c=.o))

############# Swig configuration #######################
# Swig is used to generate a Wrapper between C 
# and Python (or other script languages)
# see http://www.swig.org
# Lib name: ipc is the module name defined in ipc.i
########################################################
# swig understand -Dflags for conditional compilation (DEFINES)
SWIG          = swig -python -shadow 
SWIG_CFLAGS   = -Wall
INTERFACE     = ipc_mod.i
INTERFACE_SRC = ipc_mod_wrap.c

########################################################
# ARCH dependant stuff
########################################################
ARCH = $(shell uname -s)
ifeq ($(strip $(ARCH)),Linux)
	MODULE_ldflags += -shared
	LDFLAGS     += -lpthread -lrt
	CFLAGS      += -DLINUX
	SWIG_CFLAGS += -DLINUX
endif
ifeq ($(strip $(ARCH)),Darwin)
  	MODULE_ldflags += -lpython
	CFLAGS         += -DDARWIN
	SWIG_CFLAGS    += -DDARWIN
endif

########################################################
# Makefile
########################################################
##
# Default
##
default : $(MODULE_bin)
all: default

##
# Python module
##
$(MODULE_dir)/$(INTERFACE_SRC): $(MODULE_dir)/$(INTERFACE)
	$(SWIG) $(SWIG_CFLAGS) -o $@ $<

MODULE_src += $(INTERFACE_SRC)

$(MODULE_bin) : $(MODULE_obj) $(TPL_MOD_obj)
		$(CC) -o $@ $(MODULE_obj) $(MODULE_ldflags) $(LDFLAGS)

$(MODULE_obj_dir)/%.o : $(MODULE_dir)/%.c
		@if [ ! -d $(OBJ_dir) ]; then mkdir $(OBJ_dir); fi;
		@if [ ! -d $(MODULE_obj_dir) ]; then mkdir $(MODULE_obj_dir); fi;
		@if [ ! -d $(MODULE_obj_dir)/util ]; then mkdir $(MODULE_obj_dir)/util; fi;
		$(CC) -o $@ -c $< $(CFLAGS) $(MODULE_cflags)

##
# CAN
# ##
can : $(CAN_obj)

$(CAN_obj) : $(CAN_dir)/$(CAN_src)
	@if [ ! -d $(MODULE_obj_dir)/$(CAN_dir) ]; then mkdir $(MODULE_obj_dir)/$(CAN_dir);fi;
	$(CC) -o $@ -c $< $(CFLAGS) $(CAN_cflags)
 		
##
# Clean & Mrproper
##
.PHONY : clean mrproper

clean:
	@rm -rf $(OBJ_dir)/ *~ $(MODULE_dir)/$(INTERFACE_SRC)

mrproper: clean
	@rm -f $(MODULE_bin) ipc/$(MODULE_name) *.pyc ipc/*.pyc

