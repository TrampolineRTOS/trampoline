OS = $(shell uname)
#Linux requires -lrt, while Darwin does not.
ifeq ($(strip $(OS)),Linux)
    LDFLAGS += -lrt
    CFLAGS += -D_XOPEN_SOURCE=600
endif

CFLAGS  += -I$(TPL_BASE_PATH)/viper2/ipc
LDFLAGS += -L$(TPL_BASE_PATH)/viper2/ipc -lvp_ipc
