#---------------------------------------------------------------*
#                                                               *
# MINGW32 tools on Win32 DEFINITION                             *
#                                                               *
#---------------------------------------------------------------*

COMPILER_TOOL := mingw32-gcc -m32 -D_WIN32_WINDOWS=0x410
LINKER_TOOL   := mingw32-g++ -m32 --enable-auto-import
STRIP_TOOL    := strip --strip-all
SUDO_TOOL     :=
COMPILATION_MESSAGE := Compiling
LINKING_MESSAGE := Linking

#---------------------------------------------------------------*

#--- Options for all compilers
COMPILER_OPTIONS_FOR_THIS_CHAIN := -Wconversion

#--- Options for release mode
#--- No optimization (MinGW is very very very very slow with -O1)
COMPILER_OPTIONS_RELEASE_FOR_THIS_CHAIN :=

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
