include ../../Make-rules
AD_SRCS = tpl_machine_c167.c
AD_OBJS = $(AD_SRCS:.c=.o)

ASMFLAGS += -I../.. -I.

%.o: %.c
	$(CC) $(ASMFLAGS) -c $< -o $@

ad:	$(AD_OBJS)

clean:
	@rm -vf $(AD_OBJS)