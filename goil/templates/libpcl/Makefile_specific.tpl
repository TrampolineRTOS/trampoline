#Libpcl uses viper support, and needs extra-libs.
OS = $(shell uname)
LDFLAGS += -lpcl 
#Linux requires -lrt, while Darwin does not.
ifeq ($(strip $(OS)),Linux)
	LDFLAGS += -lrt
endif

CFLAGS += -I$(VIPER_PATH)
