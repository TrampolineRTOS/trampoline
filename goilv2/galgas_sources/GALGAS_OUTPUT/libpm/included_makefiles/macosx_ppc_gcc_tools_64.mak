#---------------------------------------------------------------*
#                                                               *
# MAC OS X TOOLS DEFINITION                                     *
#                                                               *
#---------------------------------------------------------------*

COMPILER_TOOL := gcc -arch ppc64 -mtune=G5 -isysroot /Developer/SDKs/MacOSX10.5.sdk
LINKER_TOOL   := g++ -arch ppc64 -mtune=G5 -isysroot /Developer/SDKs/MacOSX10.5.sdk -mmacosx-version-min=10.5
STRIP_TOOL    := strip -A -n -r -u
SUDO_TOOL     := sudo
COMPILATION_MESSAGE := 64-Bit Compiling for Mac OS X Leopard G5
LINKING_MESSAGE := 64-Bit Linking for Mac OS X Leopard G5

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
