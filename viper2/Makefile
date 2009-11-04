########################################################
# Variables
########################################################
##
# Commons
##
CFLAGS    += -Wall --std=c99 -D_XOPEN_SOURCE=600 -pedantic 
LDFLAGS   += 
AR         = ar
RANLIB     = ranlib
OBJ_dir    = .obj
PYTHON_inc =  PYTHON_INCLUDE

##
# Python module (ipc_mod)
##
MODULE_dir     = ipc
MODULE_src     = com.c ipc_mod.c util/fifo.c
MODULE_hdr     = com.h ipc_mod.h util/fifo.h
MODULE_swig    = ipc_mod.h consts.h
MODULE_bin     = _ipc.so
MODULE_name    = ipc.py
MODULE_obj_dir = $(OBJ_dir)/$(MODULE_dir)
MODULE_obj     = $(addprefix $(MODULE_obj_dir)/,$(MODULE_src:.c=.o))
MODULE_cflags  = -I$(PYTHON_inc) -I$(MODULE_dir)
MODULE_ldflags = -dynamiclib

##
# Trampoline static module (vp_ipc.a)
##
TPL_MODULE_dir     = ipc
TPL_MODULE_src     = com.c viper.c util/fifo.c device/tpl_can_driver.c
TPL_MODULE_bin     = ipc/libvp_ipc.a
TPL_MODULE_hdr     = com.h viper.h util/fifo.h device/tpl_can_driver.h
TPL_MODULE_obj_dir = $(MODULE_obj_dir)
TPL_MODULE_obj     = $(addprefix $(MODULE_obj_dir)/,$(TPL_MODULE_src:.c=.o))
TPL_MODULE_cflags  = -I$(MODULE_dir)
TPL_MODULE_ldflags = ru

##
# CAN
##
CAN_dir = device
CAN_src = tpl_can_driver.c
CAN_obj = $(addprefix $(MODULE_obj_dir)/$(CAN_dir)/,$(CAN_src:.c=.o))
CAN_cflags = -I$(MODULE_dir)
CAN_ldflags =

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
SWIG_BASENAME = $(shell which swig)

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
	CFLAGS         += -DDARWIN
	SWIG_CFLAGS    += -DDARWIN
endif
MODULE_ldflags += PYTHON_LDFLAGS

########################################################
# Makefile
########################################################
##
# Default
##
all: wrapper can mod
wrapper : $(MODULE_bin)
mod : $(TPL_MODULE_bin)

##
# Python module
##
$(MODULE_dir)/$(INTERFACE_SRC): $(MODULE_dir)/$(INTERFACE) ipc/ipc_mod.h ipc/consts.h
ifneq "$(SWIG_BASENAME)" ""
	$(SWIG) $(SWIG_CFLAGS) -o $@ $<
endif

MODULE_src += $(INTERFACE_SRC)

$(MODULE_bin) : $(MODULE_obj) 
		$(CC) -o $@ $(MODULE_obj) $(MODULE_ldflags) $(LDFLAGS)

$(MODULE_obj_dir)/%.o : $(MODULE_dir)/%.c
		@if [ ! -d $(OBJ_dir) ]; then mkdir $(OBJ_dir); fi;
		@if [ ! -d $(MODULE_obj_dir) ]; then mkdir $(MODULE_obj_dir); fi;
		@if [ ! -d $(MODULE_obj_dir)/util ]; then mkdir $(MODULE_obj_dir)/util; fi;
		$(CC) -o $@ -c $< $(CFLAGS) $(MODULE_cflags)

$(TPL_MODULE_bin): $(TPL_MODULE_obj)
	$(AR) $(TPL_MODULE_ldflags) $@ $(TPL_MODULE_obj)
	$(RANLIB) $@

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
	@rm -rf $(OBJ_dir)/ *~

mrproper: clean
	@rm -f $(MODULE_bin) *.pyc ipc/*.pyc device/*.pyc module/*.pyc widget/*.pyc config.pyc $(TPL_MODULE_bin)

