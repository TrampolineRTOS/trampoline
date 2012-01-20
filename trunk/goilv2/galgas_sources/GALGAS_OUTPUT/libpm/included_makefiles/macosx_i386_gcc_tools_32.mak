#---------------------------------------------------------------*
#                                                               *
# MAC OS X TOOLS DEFINITION                                     *
#                                                               *
#---------------------------------------------------------------*

COMPILER_TOOL := gcc -m32 -mdynamic-no-pic -arch i386
LINKER_TOOL   := g++ -m32 -arch i386
STRIP_TOOL    := strip -A -n -r -u
SUDO_TOOL     := sudo
COMPILATION_MESSAGE := 32-Bit Compiling for Intel Mac
LINKING_MESSAGE := 32-Bit Linking for Intel Mac

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
