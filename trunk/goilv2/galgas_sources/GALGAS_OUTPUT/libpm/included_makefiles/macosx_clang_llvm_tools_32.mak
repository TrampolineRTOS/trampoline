#---------------------------------------------------------------*
#                                                               *
# MAC OS X CLANG-LLVM TOOLS DEFINITION                          *
#                                                               *
#---------------------------------------------------------------*

CLANG_LLVM_DIRECTORY := /usr/local/llvm-clang-2.7

#---------------------------------------------------------------*

COMPILER_TOOL := $(CLANG_LLVM_DIRECTORY)/bin/clang -m32
LINKER_TOOL   := $(CLANG_LLVM_DIRECTORY)/bin/clang++ -m32
STRIP_TOOL    := strip
SUDO_TOOL     := sudo
COMPILATION_MESSAGE := 32-Bit CLANG-LLVM Compiling for Mac OS X
LINKING_MESSAGE := 32-Bit CLANG-LLVM Linking

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
CPP_COMPILER_OPTIONS_FOR_THIS_CHAIN :=

#--- Options for Objective-C compiling (.m extension)
OC_COMPILER_OPTIONS_FOR_THIS_CHAIN := 

#--- Options for Objective-C++ compiling (.mm extension)
OCPP_COMPILER_OPTIONS_FOR_THIS_CHAIN := 

#---------------------------------------------------------------*
