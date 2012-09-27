#
# Trampoline OS
#
# Trampoline is copyright (c) IRCCyN 2005+
# Trampoline est protege par la loi sur la propriete intellectuelle
#
# This software is distributed under the Lesser GNU Public Licence
#
# $Date$
# $Rev$
# $Author$
# $URL$
#

#kernel COM files
SOURCES += tpl_ioc_kernel.c
SOURCES += tpl_ioc_queue.c

ifeq ($(strip $(WITH_SYSTEM_CALL)),false)
SOURCES += tpl_ioc_message_management.c
endif