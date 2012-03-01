#---------------------------------------------------------------*
#                                                               *
# MAC OS X TOOLS DEFINITION                                     *
#                                                               *
# This fragment tests the Mac OS X gcc version, since -m32      *
# is not recognized by GCC 3.3 and earlier.                     *
#---------------------------------------------------------------*

COMPILER_TOOL := gcc-4.0 -arch ppc750 -mtune=G3 -isysroot /Developer/SDKs/MacOSX10.4u.sdk
LINKER_TOOL   := g++-4.0 -arch ppc750 -mtune=G3 -isysroot /Developer/SDKs/MacOSX10.4u.sdk -mmacosx-version-min=10.4
STRIP_TOOL    := strip
SUDO_TOOL     := sudo
COMPILATION_MESSAGE := 32-Bit Compiling for Mac OS Tiger G3
LINKING_MESSAGE := 32-Bit Linking for Mac OS X Tiger G3

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
