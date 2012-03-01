#---------------------------------------------------------------*
#                                                               *
#     Compiler Options                                          *
#                                                               *
#---------------------------------------------------------------*

#--- Options for all compilers
COMPILER_OPTIONS := $(COMPILER_OPTIONS_FOR_THIS_CHAIN)
COMPILER_OPTIONS += -Wall
COMPILER_OPTIONS += -Werror
COMPILER_OPTIONS += -Wreturn-type
COMPILER_OPTIONS += -Wformat
COMPILER_OPTIONS += -Wsign-compare
COMPILER_OPTIONS += -Wpointer-arith
#--- Options added for GALGAS 1.9.0
COMPILER_OPTIONS += -ansi
COMPILER_OPTIONS += -W
#COMPILER_OPTIONS += -Wshadow
#COMPILER_OPTIONS += -Wcast-qual
COMPILER_OPTIONS += -Wwrite-strings

#--- Options for release mode
COMPILER_OPTIONS_RELEASE := $(COMPILER_OPTIONS_RELEASE_FOR_THIS_CHAIN)
COMPILER_OPTIONS_RELEASE += -fomit-frame-pointer
COMPILER_OPTIONS_RELEASE += -DDO_NOT_GENERATE_CHECKINGS
COMPILER_OPTIONS_RELEASE += -Wunused-variable

#--- Options for debug mode 
COMPILER_OPTIONS_DEBUG := $(COMPILER_OPTIONS_DEBUG_FOR_THIS_CHAIN)
COMPILER_OPTIONS_DEBUG += -g

#--- Options for C compiling (.c extension)
C_COMPILER_OPTIONS := $(C_COMPILER_OPTIONS_FOR_THIS_CHAIN)

#--- Options for C++ compiling (.cpp extension)
CPP_COMPILER_OPTIONS := $(CPP_COMPILER_OPTIONS_FOR_THIS_CHAIN)
CPP_COMPILER_OPTIONS += -Woverloaded-virtual

#--- Options for Objective-C compiling (.m extension)
OC_COMPILER_OPTIONS := $(OC_COMPILER_OPTIONS_FOR_THIS_CHAIN)

#--- Options for Objective-C++ compiling (.mm extension)
OCPP_COMPILER_OPTIONS := $(OCPP_COMPILER_OPTIONS_FOR_THIS_CHAIN)

#---------------------------------------------------------------*
#                                                               *
#     Linker Options                                            *
#                                                               *
#---------------------------------------------------------------*

LINKER_OPTIONS :=

#---------------------------------------------------------------*
#                                                               *
#     Strip Options                                             *
#                                                               *
#---------------------------------------------------------------*

STRIP_OPTION :=

#---------------------------------------------------------------*
