#---------------------------------------------------------------*
#                                                               *
# MAC OS X TOOLS DEFINITION                                     *
#                                                               *
# This fragment tests the Mac OS X gcc version:                 *
#   -m32 is not recognized by GCC 3.3 and earlier;              *
#   if Tiger SDK is found, it is used;                          *
#   otherwise native SDK is used.                               *
#                                                               *
#---------------------------------------------------------------*

GCC_VERSION := $(shell gcc --version | awk '/(GCC)/ { print $$3; }')
TIGER_SDK := $(shell file /Developer/SDKs/MacOSX10.4u.sdk | awk '/directory$$/ { print $$2; }')

#---------------------------------------------------------------*

ifeq ($(GCC_VERSION), 3.3)
  COMPILER_TOOL := gcc -mdynamic-no-pic
  LINKER_TOOL := g++
  COMPILATION_MESSAGE := 32-Bit Compiling for Mac OS X with GCC 3.3
  LINKING_MESSAGE := 32-Bit Linking for Mac OS X Tiger with GCC 3.3
else
  ifeq ($(TIGER_SDK), directory)
    COMPILER_TOOL := gcc-4.0 -m32 -isysroot /Developer/SDKs/MacOSX10.4u.sdk
    LINKER_TOOL := g++-4.0 -m32 -isysroot /Developer/SDKs/MacOSX10.4u.sdk -mmacosx-version-min=10.4
    COMPILATION_MESSAGE := 32-Bit Compiling for Mac OS X Tiger
    LINKING_MESSAGE := 32-Bit Linking for Mac OS X Tiger
  else
    COMPILER_TOOL := gcc -m32
    LINKER_TOOL := g++ -m32
    COMPILATION_MESSAGE := 32-Bit Compiling for Mac OS X with native SDK
    LINKING_MESSAGE := 32-Bit Linking for Mac OS X with native SDK
  endif
endif

#---------------------------------------------------------------*

STRIP_TOOL    := strip
SUDO_TOOL     := sudo

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
