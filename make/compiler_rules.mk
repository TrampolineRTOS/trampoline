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
$(OBJ_DIR)/%.c.o: $(A_DIR)/%.c Makefile
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	$(CC) $(CFLAGS) -c $< -o $@

# generate dep files for c files
# OIL compiler should have made his work (some .c and .h files are generated).
$(DEP_DIR)/%.c.d: $(A_DIR)/%.c Makefile $(DEP_DIR) $(OIL_OUTPUT_PATH)/$(OIL_GENERATED_C_FILE)
	@$(CC) $(CFLAGS) -MM $< | perl -e  'while(<STDIN>) { s@$*.o:@$(OBJ_DIR)/$*.c.o $(DEP_DIR)/$*.c.d:@ ;print ;}' > $@;

#----------------------------------------------------------------------*
#### Compilation rules. ASM files.
#----------------------------------------------------------------------*
$(OBJ_DIR)/%.s.o: $(A_DIR)/%.s Makefile
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	$(AS) $(ASFLAGS) $< -o $@

#----------------------------------------------------------------------*
#### Compilation rules. c++ files.
## extensions are: .cpp .cc .cxx .C
#----------------------------------------------------------------------*

$(OBJ_DIR)/%.cpp.o: $(A_DIR)/%.cpp Makefile
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	$(CXX) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.cc.o: $(A_DIR)/%.cc Makefile
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	$(CXX) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.cxx.o: $(A_DIR)/%.cxx Makefile
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	$(CXX) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.C.o: $(A_DIR)/%.C Makefile
	@if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi;
	$(CXX) $(CFLAGS) -c $< -o $@

# generate dep files for c++ files
$(DEP_DIR)/%.cpp.d: $(A_DIR)/%.cpp Makefile $(DEP_DIR) $(OIL_OUTPUT_PATH)/$(OIL_GENERATED_C_FILE)
	@$(CC) $(CFLAGS) -MM $< | perl -e  'while(<STDIN>) { s@$*.o:@$(OBJ_DIR)/$*.cpp.o $(DEP_DIR)/$*.d:@ ;print ;}' > $@;

$(DEP_DIR)/%.cc.d: $(A_DIR)/%.cc Makefile $(DEP_DIR) $(OIL_OUTPUT_PATH)/$(OIL_GENERATED_C_FILE)
	@$(CC) $(CFLAGS) -MM $< | perl -e  'while(<STDIN>) { s@$*.o:@$(OBJ_DIR)/$*.cc.o $(DEP_DIR)/$*.d:@ ;print ;}' > $@;

$(DEP_DIR)/%.cxx.d: $(A_DIR)/%.cxx Makefile $(DEP_DIR) $(OIL_OUTPUT_PATH)/$(OIL_GENERATED_C_FILE)
	@$(CC) $(CFLAGS) -MM $< | perl -e  'while(<STDIN>) { s@$*.o:@$(OBJ_DIR)/$*.cxx.o $(DEP_DIR)/$*.d:@ ;print ;}' > $@;

$(DEP_DIR)/%.C.d: $(A_DIR)/%.C Makefile $(DEP_DIR) $(OIL_OUTPUT_PATH)/$(OIL_GENERATED_C_FILE)
	@$(CC) $(CFLAGS) -MM $< | perl -e  'while(<STDIN>) { s@$*.o:@$(OBJ_DIR)/$*.C.o $(DEP_DIR)/$*.d:@ ;print ;}' > $@;

#----------------------------------------------------------------------*
#Call recursively this file, without the first item of TEMP_SOURCE_DIRS *
#----------------------------------------------------------------------*
TEMP_SOURCE_DIRS := $(filter-out $(word 1, $(TEMP_SOURCE_DIRS)), $(TEMP_SOURCE_DIRS))
include $(OS_MAKE_PATH)/compiler_rules.mk
#----------------------------------------------------------------------*

endif
# vim:ft=make
