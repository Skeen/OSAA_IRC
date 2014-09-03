
CFLAGS=-Wall -O2 -g
LIBS=-lm

SRCS=\
	irc.c

OBJS=$(SRCS:.c=.o)


irc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $+ $(LIBS)

irc.o: irc.c

clean::
	$(RM) irc $(OBJS)
