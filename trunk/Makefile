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

#make OS objects.
OS: OBJ
	@cd $(OS_DIR) && make OS

#make User Application objects.
APP: OBJ
	@cd $(APP_DIR) && make APP

#make object directory.
OBJ:
	@if [ ! -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi; 

$(EXE): OS APP
	$(CC) $(LDFLAGS) -o $@ $(OBJ_DIR)/*.o 
			
clean:
	@cd $(OS_DIR) && make clean 
	@cd $(OS_MACHINE_DIR) && make clean 
	@cd $(APP_DIR) && make clean 
	@rm -rf $(OBJ_DIR) $(EXE)
