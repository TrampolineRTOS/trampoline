#
# Trampoline OS
#
# Trampoline is copyright (c) IRCCyN 2005-2007
# Autosar extension is copyright (c) IRCCyN and ESEO 2007
# Trampoline est protégé par la loi sur la propriété intellectuelle
#
# This software is distributed under the Lesser GNU Public Licence
#
# $Date$
# $Rev$
# $Author$
# $URL$
#

#kernel AUTOSAR files
SOURCES += tpl_as_counter_kernel.c
SOURCES += tpl_as_st_kernel.c
SOURCES += tpl_as_isr_kernel.c
SOURCES += tpl_as_stack_monitor.c
SOURCES += tpl_as_timing_protec.c
SOURCES += tpl_as_action.c
SOURCES += tpl_as_protec_hook.c

ifeq ($(strip $(WITH_MEMORY_PROTECTION)), true)
SOURCES += tpl_as_memprot_kernel.c
endif

ifeq ($(strip $(AUTOSAR_OSAPPLICATIONS)),true)
SOURCES += tpl_as_app_kernel.c
ifeq ($(strip $(WITH_MEMORY_PROTECTION)),false)
SOURCES += tpl_as_trusted_fct_kernel.c
endif
endif


ifeq ($(strip $(WITH_SYSTEM_CALL)),false)
SOURCES += tpl_as_counter.c
SOURCES += tpl_as_isr.c
SOURCES += tpl_as_schedtable.c
ifeq ($(strip $(WITH_MEMORY_PROTECTION)), true)
SOURCES += tpl_as_memprot.c
endif
ifeq ($(strip $(AUTOSAR_OSAPPLICATIONS)),true)
SOURCES += tpl_as_trusted_fct.c
SOURCES += tpl_as_application.c
endif
endif

