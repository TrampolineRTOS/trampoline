OS = $(shell uname)
#Linux requires -lrt, while Darwin does not.
ifeq ($(strip $(OS)),Linux)
	LDFLAGS += -lrt
endif

CFLAGS += -I$(VIPER_DIR)
