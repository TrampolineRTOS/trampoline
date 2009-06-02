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
# Trampoline static module (vp_ipc.a)
##
TPL_MODULE_dir     = ipc
TPL_MODULE_src     = com.c viper.c util/fifo.c
TPL_MODULE_bin     = ipc/libvp_ipc.a
TPL_MODULE_hdr     = com.h viper.h util/fifo.h
TPL_MODULE_obj_dir = $(MODULE_obj_dir)
TPL_MODULE_obj     = $(addprefix $(MODULE_obj_dir)/,$(TPL_MODULE_src:.c=.o))
TPL_MODULE_cflags  = -I$(MODULE_dir)
TPL_MODULE_ldflags = ru

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
mod : $(TPL_MODULE_bin)
all: default mod

##
# Python module
##
$(MODULE_dir)/$(INTERFACE_SRC): $(MODULE_dir)/$(INTERFACE)
	$(SWIG) $(SWIG_CFLAGS) -o $@ $<

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
# Clean & Mrproper
##
.PHONY : clean mrproper

clean:
	@rm -rf $(OBJ_dir)/ *~ $(MODULE_dir)/$(INTERFACE_SRC)

mrproper: clean
	@rm -f $(MODULE_bin) ipc/$(MODULE_name) *.pyc ipc/*.pyc $(TPL_MODULE_bin)

