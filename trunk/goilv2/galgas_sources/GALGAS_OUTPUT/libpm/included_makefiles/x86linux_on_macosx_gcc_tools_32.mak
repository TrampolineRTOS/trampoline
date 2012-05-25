#---------------------------------------------------------------*
#                                                               *
# 32-bit linux tools on MAC OS X                                *
#                                                               *
#---------------------------------------------------------------*

UNIX_TOOL_PREFIX := /usr/local/gcc-4.5.2-for-linux32/bin/i586-pc-linux
COMPILER_TOOL := $(UNIX_TOOL_PREFIX)-gcc
LINKER_TOOL   := $(UNIX_TOOL_PREFIX)-g++
STRIP_TOOL    := $(UNIX_TOOL_PREFIX)-strip --strip-all
SUDO_TOOL     := sudo
COMPILATION_MESSAGE := 32-Bit Compiling for Linux
LINKING_MESSAGE := 32-Bit Linking for Linux

#---------------------------------------------------------------*

#--- Options for all compilers
COMPILER_OPTIONS_FOR_THIS_CHAIN := -Wconversion

#--- Options for release mode
COMPILER_OPTIONS_RELEASE_FOR_THIS_CHAIN := -O2

#--- Options for debug mode 
COMPILER_OPTIONS_DEBUG_FOR_THIS_CHAIN :=

#--- Options for C compiling (.c extension)
C_COMPILER_OPTIONS_FOR_THIS_CHAIN :=

#--- Options for C++ compiling (.cpp extension)
CPP_COMPILER_OPTIONS_FOR_THIS_CHAIN := -Weffc++
CPP_COMPILER_OPTIONS_FOR_THIS_CHAIN += -Wsign-promo

#--- Options for Objective-C compiling (.m extension)
OC_COMPILER_OPTIONS_FOR_THIS_CHAIN := 

#--- Options for Objective-C++ compiling (.mm extension)
OCPP_COMPILER_OPTIONS_FOR_THIS_CHAIN := 

#---------------------------------------------------------------*
