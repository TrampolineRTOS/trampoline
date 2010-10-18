SOURCES += tpl_start.S
SOURCES += tpl_os_it.S
SOURCES += tpl_dispatch.S
SOURCES += tpl_it_handler.S
SOURCES += tpl_ctx_switch.S
SOURCES += tpl_init.S
SOURCES += tpl_init_term.c
ifeq ($(strip $(WITH_MEMORY_PROTECTION)),true)
SOURCES += tpl_call_trusted_fct.S
endif