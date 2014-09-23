#---------------------------------------------------------------*
#                                                               *
# MINGW32 tools on MAC OS X DEFINITION                          *
#                                                               *
#---------------------------------------------------------------*

TOOL_CHAIN_ARCHIVE := gcc-4.8.0-qt-4.8.4-for-mingw32
TOOL_CHAIN_URL := http://crossgcc.rts-software.org/download/gcc-4.8.0-qt-4.8.4-win32/$(TOOL_CHAIN_ARCHIVE).tar.bz2
TOOL_CHAIN_INSTALL_PATH := /usr/local/$(TOOL_CHAIN_ARCHIVE)

#---------------------------------------------------------------*

MINGW_TOOL_PATH := $(TOOL_CHAIN_INSTALL_PATH)/win32-gcc/bin
COMPILER_PATH := $(MINGW_TOOL_PATH)/i586-mingw32-gcc
COMPILER_TOOL := $(COMPILER_PATH) -m32 -D_WIN32_WINNT=0x501
LINKER_TOOL   := $(MINGW_TOOL_PATH)/i586-mingw32-g++ -m32 --enable-auto-import -Wl,--gc-sections
STRIP_TOOL    := $(MINGW_TOOL_PATH)/i586-mingw32-strip --strip-all

SUDO_TOOL     := sudo
COMPILATION_MESSAGE := 32-Bit Compiling for Win32
LINKING_MESSAGE := 32-Bit Linking for Win32

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
