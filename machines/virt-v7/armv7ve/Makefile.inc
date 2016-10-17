#/**
# Copyright (c) 2012 Anup Patel.
# All rights reserved.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
# @file Makefile.inc
# @author Anup Patel (anup@brainfault.org)
# @brief common makefile to build basic firmware
# */

# Include top-level configuration file if present
-include $(build_dir)/openconf/.config

FW_CROSS_COMPILE=$(CROSS_COMPILE)
FW_CPPFLAGS=-I. -I$(common_dir) -DTEXT_START=$(board_text_start)
FW_CFLAGS=-g -Wall -Werror -nostdlib -msoft-float -marm
FW_ASFLAGS=-g -Wall -Werror -nostdlib -msoft-float -marm -D__ASSEMBLY__
ifeq ($(board_arch),v7ve)
FW_CPPFLAGS+=-DARM_ARCH_v7ve
FW_CFLAGS+=-march=armv7ve $(FW_CPPFLAGS)
FW_ASFLAGS+=-march=armv7ve $(FW_CPPFLAGS)
endif
FW_LDFLAGS=$(FW_CFLAGS) -Wl,--build-id=none
FW_AS=$(FW_CROSS_COMPILE)gcc
FW_CC=$(FW_CROSS_COMPILE)gcc
FW_CPP=$(FW_CROSS_COMPILE)cpp
FW_OBJCOPY=$(FW_CROSS_COMPILE)objcopy

ifeq ($(board_arch),v7ve)
FIRMWARE_OBJS=$(obj_dir)/arm_entry_v7.o \
		$(obj_dir)/arm_cache_v7.o \
		$(obj_dir)/arm_mmu_v7.o
endif

FIRMWARE_OBJS+=$(board_objs)

FIRMWARE_OBJS+=$(obj_dir)/arm_main.o \
		$(obj_dir)/arm_heap.o \
		$(obj_dir)/arm_irq.o \
		$(obj_dir)/arm_stdio.o \
		$(obj_dir)/arm_string.o \
		$(obj_dir)/arm_math.o \
		$(obj_dir)/dhry_1.o \
		$(obj_dir)/dhry_2.o \
		$(obj_dir)/dhry_port.o

ifeq ($(board_fdt_support),y)
FIRMWARE_OBJS+=$(obj_dir)/libfdt/fdt.o \
		$(obj_dir)/libfdt/fdt_ro.o \
		$(obj_dir)/libfdt/fdt_rw.o \
		$(obj_dir)/libfdt/fdt_strerror.o \
		$(obj_dir)/libfdt/fdt_support.o \
		$(obj_dir)/libfdt/fdt_sw.o \
		$(obj_dir)/libfdt/fdt_wip.o
endif

FIRMWARE_CPPFLAGS=-DFIRMWARE_BOOT
ifeq ($(board_smp), y)
FIRMWARE_CPPFLAGS+=-DBOARD_SMP
endif
ifeq ($(board_secure_extn),y)
FIRMWARE_CPPFLAGS+=-DARM_SECURE_EXTN_IMPLEMENTED
endif
ifeq ($(board_fdt_support),y)
FIRMWARE_CPPFLAGS+=-DBOARD_FDT_SUPPORT
endif
FIRMWARE_CPPFLAGS+=$(board_cppflags)
FIRMWARE_CFLAGS=$(FIRMWARE_CPPFLAGS) $(board_cflags)
FIRMWARE_ASFLAGS=$(FIRMWARE_CPPFLAGS) $(board_asflags)
FIRMWARE_LINK_SCRIPT=$(obj_dir)/firmware.lnk
FIRMWARE_LDFLAGS=-Wl,-T$(FIRMWARE_LINK_SCRIPT) $(FIRMWARE_CPPFLAGS) $(board_ldflags)

FIRMWARE_COMMON_DEPS=$(common_dir)/arm_asm_macro.h \
                $(common_dir)/arm_math.h \
                $(common_dir)/arm_defines.h \
                $(common_dir)/arm_types.h \
                $(common_dir)/arm_board.h \
                $(common_dir)/arm_heap.h \
                $(common_dir)/arm_inline_asm.h \
                $(common_dir)/arm_cache.h \
                $(common_dir)/arm_io.h \
                $(common_dir)/arm_irq.h \
                $(common_dir)/arm_mmu.h \
                $(common_dir)/arm_stdio.h \
                $(common_dir)/arm_string.h

ifeq ($(board_fdt_support),y)
FIRMWARE_COMMON_DEPS+=$(common_dir)/libfdt/fdt.h \
                $(common_dir)/libfdt/fdt_support.h \
                $(common_dir)/libfdt/libfdt.h \
                $(common_dir)/libfdt/libfdt_env.h \
                $(common_dir)/libfdt/libfdt_internal.h
endif

CPATCH32=$(build_dir)/tools/cpatch/cpatch32
ELF2CPATCH=$(top_dir)/arch/arm/cpu/arm32/elf2cpatch.py

cmd_patch_elf = CROSS_COMPILE=$(FW_CROSS_COMPILE) \
		$(ELF2CPATCH) -f $@ | $(CPATCH32) $@ 0

FIRMWARE_TARGETS = $(obj_dir)/firmware.bin
ifdef CONFIG_ARM32
FIRMWARE_TARGETS += $(obj_dir)/firmware.bin.patched
endif

.PHONY: all
all: $(FIRMWARE_TARGETS)

$(obj_dir)/firmware.bin.patched: $(obj_dir)/firmware.elf.patched
	@mkdir -p `dirname $@`
	@echo " (OBJCOPY)   $(subst $(obj_dir)/,,$@)"
	@$(FW_OBJCOPY) -O binary $< $@

$(obj_dir)/firmware.elf.patched: $(obj_dir)/firmware.elf
	@mkdir -p `dirname $@`
	@cp $< $@
	@echo " (PATCH)     $(subst $(obj_dir)/,,$@)"
	@$(call cmd_patch_elf)

$(obj_dir)/firmware.bin: $(obj_dir)/firmware.elf
	@mkdir -p `dirname $@`
	@echo " (OBJCOPY)   $(subst $(obj_dir)/,,$@)"
	@$(FW_OBJCOPY) -O binary $< $@

$(obj_dir)/firmware.elf: $(FIRMWARE_OBJS) $(FIRMWARE_LINK_SCRIPT)
	@mkdir -p `dirname $@`
	@echo " (LD)        $(subst $(obj_dir)/,,$@)"
	@$(FW_CC) $(FIRMWARE_OBJS) $(FW_LDFLAGS) $(FIRMWARE_LDFLAGS) -o $@

$(obj_dir)/%.lnk: $(common_dir)/%.ld
	@mkdir -p `dirname $@`
	@echo " (CPP)       $(subst $(obj_dir)/,,$@)"
	@$(FW_CPP) $(FW_CPPFLAGS) $(FIRMWARE_CPPFLAGS) $< | grep -v "\#" > $@

$(obj_dir)/%.o: %.c $(FIRMWARE_COMMON_DEPS)
	@mkdir -p `dirname $@`
	@echo " (CC)        $(subst $(obj_dir)/,,$@)"
	@$(FW_CC) $(FW_CFLAGS) $(FIRMWARE_CFLAGS) -c $< -o $@

$(obj_dir)/%.o: $(common_dir)/%.c $(FIRMWARE_COMMON_DEPS)
	@mkdir -p `dirname $@`
	@echo " (CC)        $(subst $(obj_dir)/,,$@)"
	@$(FW_CC) $(FW_CFLAGS) $(FIRMWARE_CFLAGS) -c $< -o $@

$(obj_dir)/%.o: %.S $(FIRMWARE_COMMON_DEPS)
	@mkdir -p `dirname $@`
	@echo " (AS)        $(subst $(obj_dir)/,,$@)"
	@$(FW_AS) $(FW_ASFLAGS) $(FIRMWARE_ASFLAGS) -c $< -o $@

$(obj_dir)/%.o: $(common_dir)/%.S $(FIRMWARE_COMMON_DEPS)
	@mkdir -p `dirname $@`
	@echo " (AS)        $(subst $(obj_dir)/,,$@)"
	@$(FW_AS) $(FW_ASFLAGS) $(FIRMWARE_ASFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo " (RM)        firmware.elf*"
	@rm -f $(obj_dir)/firmware.elf*
	@echo " (RM)        firmware.bin*"
	@rm -f $(obj_dir)/firmware.bin*
	@echo " (RM)        $(obj_dir)"
	@rm -rf $(obj_dir)
