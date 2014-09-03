CFLAGS=-Wall -O2 -g -std=c++11
LIBS=-lm

SRCS= \
	  irc.cpp

irc: irc.cpp
	g++ $(CFLAGS) -o $@ $+ $(LIBS) 

clean:
	$(RM) irc $(OBJS)
