#
# Trampoline OS
#
# Trampoline is copyright (c) IRCCyN 2005+
# Trampoline is protected by the French intellectual property law.
#
# This software is distributed under the Lesser GNU Public Licence
#
# $Date: 2008-02-22 15:39:51 +0100 (Ven, 22 fÃ©v 2008) $
# $Rev: 422 $
# $Author: mik $
# $URL: https://trampoline.rts-software.org/svn/trunk/os/Makefile $

ifneq ($(words $(TEMP_SOURCE_DIRS)), 0)

#----------------------------------------------------------------------*
#  Building inference rules                                            *
#----------------------------------------------------------------------*

A_DIR := $(word 1, $(TEMP_SOURCE_DIRS))

#----------------------------------------------------------------------*
#### Compilation rules. C files.
#----------------------------------------------------------------------*
$(OBJ_DIR)/%.c.o: $(A_DIR)/%.c $(OIL_OUTPUTS)
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	@echo compiling $<
	$(CC) $(genDep) $(CFLAGS) -c $< -o $@

#----------------------------------------------------------------------*
#### Compilation rules. ASM files.
#----------------------------------------------------------------------*
#use the assembly directly
$(OBJ_DIR)/%.s.o: $(A_DIR)/%.s $(OIL_OUTPUTS)
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	@echo assembling $<
	$(AS) $(ASFLAGS) $< -o $@

#call the assembly through the C compiler.
$(OBJ_DIR)/%.S.o: $(A_DIR)/%.S $(OIL_OUTPUTS)
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	@echo assembling $<
	$(CC) $(CFLAGS) -c $< -o $@

#----------------------------------------------------------------------*
#### Compilation rules. c++ files.
## extensions are: .cpp .cc .cxx .C
#----------------------------------------------------------------------*

$(OBJ_DIR)/%.cpp.o: $(A_DIR)/%.cpp $(OIL_OUTPUTS)
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	@echo compiling $<
	$(CPP) $(genDep) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/%.cc.o: $(A_DIR)/%.cc $(OIL_OUTPUTS)
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	@echo compiling $<
	$(CPP) $(genDep) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/%.cxx.o: $(A_DIR)/%.cxx $(OIL_OUTPUTS)
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	@echo compiling $<
	$(CPP) $(genDep) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/%.C.o: $(A_DIR)/%.C $(OIL_OUTPUTS)
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	@echo compiling $<
	$(CPP) $(genDep) $(CPPFLAGS) -c $< -o $@

#----------------------------------------------------------------------*
#Call recursively this file, without the first item of TEMP_SOURCE_DIRS *
#----------------------------------------------------------------------*
TEMP_SOURCE_DIRS := $(filter-out $(word 1, $(TEMP_SOURCE_DIRS)), $(TEMP_SOURCE_DIRS))
include $(OS_MAKE_PATH)/compiler_rules.mk
#----------------------------------------------------------------------*

endif
# vim:ft=make
