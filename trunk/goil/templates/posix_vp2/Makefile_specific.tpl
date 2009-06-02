OS = $(shell uname)
#Linux requires -lrt, while Darwin does not.
ifeq ($(strip $(OS)),Linux)
	LDFLAGS += -lrt
    CFLAGS += -D_XOPEN_SOURCE=600
endif

