#---------------------------------------------------------------*
#                                                               *
# MAC OS X TOOLS DEFINITION                                     *
#                                                               *
#---------------------------------------------------------------*

LEOPARD_SDK := $(shell file /Developer/SDKs/MacOSX10.5.sdk | awk '/directory$$/ { print $$2; }')

#--- For XCode 4.3
SNOW_LEOPARD_SDK := $(shell file /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk | awk '/directory$$/ { print $$2; }')

#---------------------------------------------------------------*

ifeq ($(LEOPARD_SDK), directory)
  COMPILER_TOOL := gcc -m64 -isysroot /Developer/SDKs/MacOSX10.5.sdk
  LINKER_TOOL   := g++ -m64 -isysroot /Developer/SDKs/MacOSX10.5.sdk -mmacosx-version-min=10.5
  STRIP_TOOL    := strip -A -n -r -u
  SUDO_TOOL     := sudo
  COMPILATION_MESSAGE := 64-Bit Compiling for Mac OS X (Leopard)
  LINKING_MESSAGE := 64-Bit Linking (Leopard)
else
  ifeq ($(SNOW_LEOPARD_SDK), directory)
    COMPILER_TOOL := gcc -m64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk
    LINKER_TOOL := g++ -m64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk -mmacosx-version-min=10.5
    STRIP_TOOL    := strip -A -n -r -u
    SUDO_TOOL     := sudo
    COMPILATION_MESSAGE := 64-Bit Compiling for Mac OS X Snow Leopard
    LINKING_MESSAGE := 64-Bit Linking for Mac OS X Snow Leopard
  else
    COMPILER_TOOL := gcc -m64
    LINKER_TOOL   := g++ -m64
    STRIP_TOOL    := strip -A -n -r -u
    SUDO_TOOL     := sudo
    COMPILATION_MESSAGE := 64-Bit Compiling for Mac OS X
    LINKING_MESSAGE := 64-Bit Linking for Mac OS X
  endif
endif

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
