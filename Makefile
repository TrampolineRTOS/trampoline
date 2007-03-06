#
# Trampoline OS
#
# Trampoline is copyright (c) IRCCyN 2005+
# Trampoline est protégé par la loi sur la propriété intellectuelle
#
# This software is distributed under the Lesser GNU Public Licence
#
# $Date$
# $Rev$
# $Author$
# $URL$
#

#Warning, this Makefile must not be modified directly!
#Please define your configuration in the Make-rules file.
#

include Make-rules

ALL: $(EXE)
	

DOC:
	doxygen

#compile oil file into c, and then into .o
OIL_OBJ_OIL_FILE = $(addprefix $(OBJ_PATH)/,$(notdir $(OIL_GENERATED_C_FILE:.c=.o)))
CFLAGS += -I$(OS_MACHINE_PATH)  -I$(OIL_OUTPUT_PATH) -I$(OS_PATH) -I$(COM_PATH)

OIL: OBJ $(OIL_OBJ_OIL_FILE)

$(OIL_GENERATED_C_FILE): $(OIL_FILE) 
	$(GOIL_COMPILER) --target=$(ARCH) --templates=$(GOIL_TEMPLATE_PATH) $(OIL_FILE)

$(OIL_OBJ_OIL_FILE) : $(OIL_GENERATED_C_FILE) 
	$(CC) $(CFLAGS) -c $< -o $@

#make OS objects.
OS: OBJ OIL
	@cd $(OS_PATH) && make OS

#make COM objects.
COM: OBJ
	@cd $(COM_DIR) && make COM

#make User Application objects.
APP: OBJ OIL
	@cd $(APP_PATH) && make APP

#make object directory.
OBJ:
	@if [ ! -d $(OBJ_PATH) ]; then mkdir $(OBJ_PATH); fi; 

$(EXE): OS APP #COM
	$(CC) $(LDFLAGS) -o $@ $(OBJ_PATH)/*.o

clean: cleanOIL
	@cd $(OS_PATH) && make clean 
	@cd $(OS_MACHINE_PATH) && make clean 
	@cd $(APP_PATH) && make clean 
	@rm -rf $(OBJ_PATH) $(EXE)

cleanOIL:
	@cd $(OIL_OUTPUT_PATH) && rm -f tpl_os_generated_configuration.c tpl_os_generated_configuration.h tpl_app_objects.h
