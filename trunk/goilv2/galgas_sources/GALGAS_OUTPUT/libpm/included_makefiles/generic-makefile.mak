#----------------------------------------------------------------------------*
#                                                                            *
# MAKEFILE for building libpm based applications                             *
#                                                                            *
# This makefile cannot be called directly, but from project makefile         *
#                                                                            *
#----------------------------------------------------------------------------*

#----------------------------------------------------------------------------*
#                                                                            *
#     Build Options                                                          *
#                                                                            *
#----------------------------------------------------------------------------*

include $(LIBPM_DIRECTORY_PATH)/included_makefiles/default_build_options.mak

C_COMPILER_OPTIONS += -fexceptions

#----------------------------------------------------------------------------*
#                                                                            *
#          Compiler calls, with all options                                  *
#                                                                            *
#----------------------------------------------------------------------------*

#--- C compiler and options for release version
C_COMPILER_CALL_RELEASE := $(COMPILER_TOOL) $(COMPILER_OPTIONS) $(COMPILER_OPTIONS_RELEASE) $(C_COMPILER_OPTIONS)

#--- C compiler and options for debug version
C_COMPILER_CALL_DEBUG := $(COMPILER_TOOL) $(COMPILER_OPTIONS) $(COMPILER_OPTIONS_DEBUG) $(C_COMPILER_OPTIONS)


#--- C++ compiler and options for release version
CPP_COMPILER_CALL_RELEASE := $(COMPILER_TOOL) $(COMPILER_OPTIONS) $(COMPILER_OPTIONS_RELEASE) $(CPP_COMPILER_OPTIONS)

#--- C++ compiler and options for debug version
CPP_COMPILER_CALL_DEBUG := $(COMPILER_TOOL) $(COMPILER_OPTIONS) $(COMPILER_OPTIONS_DEBUG) $(CPP_COMPILER_OPTIONS)


#--- Objective C compiler and options for release version
OC_COMPILER_CALL_RELEASE := $(COMPILER_TOOL) $(COMPILER_OPTIONS) $(COMPILER_OPTIONS_RELEASE) $(OC_COMPILER_OPTIONS)

#--- Objective C compiler and options for debug version
OC_COMPILER_CALL_DEBUG := $(COMPILER_TOOL) $(COMPILER_OPTIONS) $(COMPILER_OPTIONS_DEBUG) $(OC_COMPILER_OPTIONS)


#--- Objective C++ compiler and options for release version
OCPP_COMPILER_CALL_RELEASE := $(COMPILER_TOOL) $(COMPILER_OPTIONS) $(COMPILER_OPTIONS_RELEASE) $(OCPP_COMPILER_OPTIONS)

#--- Objective C++ compiler and options for debug version
OCPP_COMPILER_CALL_DEBUG := $(COMPILER_TOOL) $(COMPILER_OPTIONS) $(COMPILER_OPTIONS_DEBUG) $(OCPP_COMPILER_OPTIONS)

#----------------------------------------------------------------------------*
#                                                                            *
#          Include pathes                                                    *
#                                                                            *
#----------------------------------------------------------------------------*

INCLUDE_PATHS := -I$(LIBPM_DIRECTORY_PATH) $(patsubst %, -I%, $(SOURCES_DIR))

#----------------------------------------------------------------------------*
#                                                                            *
#          Source directories from LIBPM                                     *
#                                                                            *
#----------------------------------------------------------------------------*

SOURCES_DIR += $(LIBPM_DIRECTORY_PATH)/bdd
SOURCES_DIR += $(LIBPM_DIRECTORY_PATH)/cache
SOURCES_DIR += $(LIBPM_DIRECTORY_PATH)/command_line_interface
SOURCES_DIR += $(LIBPM_DIRECTORY_PATH)/files
SOURCES_DIR += $(LIBPM_DIRECTORY_PATH)/galgas
SOURCES_DIR += $(LIBPM_DIRECTORY_PATH)/galgas2
SOURCES_DIR += $(LIBPM_DIRECTORY_PATH)/streams
SOURCES_DIR += $(LIBPM_DIRECTORY_PATH)/time
SOURCES_DIR += $(LIBPM_DIRECTORY_PATH)/strings
SOURCES_DIR += $(LIBPM_DIRECTORY_PATH)/utilities

#----------------------------------------------------------------------------*
#                                                                            *
#             Verbose option                                                 *
#                                                                            *
#----------------------------------------------------------------------------*

ifdef VERBOSE
  SILENT_CHAR :=
else
  SILENT_CHAR := @
endif 

#----------------------------------------------------------------------------*
#                                                                            *
#             GOALS                                                          *
#(for running make install and make uninstall, you must be root)             *
#                                                                            *
#----------------------------------------------------------------------------*

all: $(EXECUTABLE) $(EXECUTABLE_DEBUG)

install: $(EXECUTABLE)
	@echo "- Installing: $<"
	$(SILENT_CHAR)$(SUDO_TOOL) mkdir -p $(INSTALL_DIR)
	$(SILENT_CHAR)$(SUDO_TOOL) cp $(EXECUTABLE) $(INSTALL_DIR)/$(EXECUTABLE)

install_debug: $(EXECUTABLE_DEBUG)
	@echo "- Installing: $<"
	$(SILENT_CHAR)$(SUDO_TOOL) mkdir -p $(INSTALL_DIR)
	$(SILENT_CHAR)$(SUDO_TOOL) cp $(EXECUTABLE_DEBUG) $(INSTALL_DIR)/$(EXECUTABLE_DEBUG)

uninstall:
	@echo "- Uninstalling '$(EXECUTABLE)' and '$(EXECUTABLE_DEBUG)'"
	$(SILENT_CHAR)$(SUDO_TOOL) rm -f $(INSTALL_DIR)/$(EXECUTABLE)
	$(SILENT_CHAR)$(SUDO_TOOL) rm -f $(INSTALL_DIR)/$(EXECUTABLE_DEBUG)

clean:
	rm -f $(EXECUTABLE) $(EXECUTABLE_DEBUG)
	rm -Rf $(OBJECTS_DIR)
	rm -Rf $(DEBUG_OBJECTS_DIR)

#----------------------------------------------------------------------------*
#                                                                            *
#    D O W N L O A D   T O O L    C H A I N                                  *
#                                                                            *
#----------------------------------------------------------------------------*

CURL := curl --fail --location --output

#----------------------------------------------------------------------------*

$(TOOL_CHAIN_ARCHIVE).tar.bz2:
	$(CURL) $(TOOL_CHAIN_ARCHIVE).tar.bz2 $(TOOL_CHAIN_URL)

#----------------------------------------------------------------------------*

$(COMPILER_PATH):
	rm -f $(TOOL_CHAIN_ARCHIVE).tar
	@echo "****** TOOL CHAIN IS NOT INSTALLED ********"
	@echo "The tool chain url is $(TOOL_CHAIN_URL)"
	@echo "Download and installation is done automatically."
	@echo "You will enter the administrator password in order to install $(notdir $(TOOL_CHAIN_INSTALL_PATH)) in $(dir $(TOOL_CHAIN_INSTALL_PATH))"
	@echo "****** DOWNLOADING..."
	$(MAKE) $(TOOL_CHAIN_ARCHIVE).tar.bz2
	@echo "****** UNTARING..."
	bunzip2 -kc $(TOOL_CHAIN_ARCHIVE).tar.bz2 > $(TOOL_CHAIN_ARCHIVE).tar
	rm $(TOOL_CHAIN_ARCHIVE).tar.bz2
	tar xf $(TOOL_CHAIN_ARCHIVE).tar
	rm $(TOOL_CHAIN_ARCHIVE).tar
	@echo "****** INSTALLING..."
	sudo mv -f $(TOOL_CHAIN_ARCHIVE) $(TOOL_CHAIN_INSTALL_PATH)
	@echo "****** DONE."

#----------------------------------------------------------------------------*
#                                                                            *
#   Build executable                                                         *
#                                                                            *
#----------------------------------------------------------------------------*

OBJECT_FILES_LIST := $(patsubst %,$(OBJECTS_DIR)/%.o, $(SOURCES))

DEPENDENCY_FILE_LIST := $(patsubst %, %.d, $(OBJECT_FILES_LIST))

#----------------------------------------------------------------------------*

$(OBJECTS_DIR):
	@echo "- Making '$(OBJECTS_DIR)' directory"
	$(SILENT_CHAR)mkdir -p $(OBJECTS_DIR)

#----------------------------------------------------------------------------*

$(EXECUTABLE):$(OBJECT_FILES_LIST)
	@echo "- $(LINKING_MESSAGE): $(EXECUTABLE)"
	$(SILENT_CHAR)$(LINKER_TOOL) $(OBJECT_FILES_LIST) -o $(EXECUTABLE) $(LINKER_OPTIONS) $(PLATFORM_LINKER_OPTIONS) && $(STRIP_TOOL) $(STRIP_OPTION) $(EXECUTABLE)

#----------------------------------------------------------------------------*
#                                                                            *
#   Build executable in debug mode                                           *
#                                                                            *
#----------------------------------------------------------------------------*

DEBUG_OBJECT_FILES_LIST := $(patsubst %,$(DEBUG_OBJECTS_DIR)/%.o, $(SOURCES))

DEBUG_DEPENDENCY_FILE_LIST := $(patsubst %, %.d, $(DEBUG_OBJECT_FILES_LIST))

#----------------------------------------------------------------------------*

$(DEBUG_OBJECTS_DIR):
	@echo "- Making '$(DEBUG_OBJECTS_DIR)' directory"
	$(SILENT_CHAR)mkdir -p $(DEBUG_OBJECTS_DIR)

#----------------------------------------------------------------------------*

$(EXECUTABLE_DEBUG):$(DEBUG_OBJECT_FILES_LIST)
	@echo "- $(LINKING_MESSAGE): $(EXECUTABLE_DEBUG)"
	$(SILENT_CHAR)$(LINKER_TOOL) $(DEBUG_OBJECT_FILES_LIST) -o $(EXECUTABLE_DEBUG) $(LINKER_OPTIONS) $(PLATFORM_LINKER_OPTIONS)

#----------------------------------------------------------------------------*
#                                                                            *
#   Build compiler rules                                                     *
#                                                                            *
#----------------------------------------------------------------------------*

TEMP_SOURCE_DIRS := $(SOURCES_DIR)
include $(LIBPM_DIRECTORY_PATH)/included_makefiles/compiler-calls.mak

#----------------------------------------------------------------------------*
#                                                                            *
#          Weak include of dependency files                                  *
#         (should be the last of the makefile)                               *
#                                                                            *
#----------------------------------------------------------------------------*

-include $(DEPENDENCY_FILE_LIST) $(DEBUG_DEPENDENCY_FILE_LIST)

#----------------------------------------------------------------------------*
