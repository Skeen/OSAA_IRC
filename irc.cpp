/*
 * This file is part of OSAA IRC.
 *
 * OSAA IRC is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * FlyBoy is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * OSAA IRC. If not, see <http://www.gnu.org/licenses/>.
 */

#include <list>
#include <string>
#include <cassert>

#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <termios.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>

#define DEBUG
#ifdef DEBUG
    #define debug_printf	printf
#else
    #define debug_printf(f,...)
#endif

#define DELAYTIMEMIN	50000
#define DELAYTIMEMAX	250000
#define DELAYTIMESTEP	100
volatile int delaytime = DELAYTIMEMAX;

void timer_start()
{
	struct itimerval itv;
	itv.it_interval.tv_sec = 0;
	itv.it_interval.tv_usec = 0;
	itv.it_value.tv_sec = 0;
	itv.it_value.tv_usec = delaytime;
	setitimer(ITIMER_REAL, &itv, NULL);
	if(delaytime > DELAYTIMEMIN)
		delaytime -= DELAYTIMESTEP;
}

void timer_stop()
{
	struct itimerval itv;
	memset(&itv, 0, sizeof(itv));
	setitimer(ITIMER_REAL, &itv, NULL);
}

#include "font.hpp"

constexpr uint8_t XSIZE = 20;
constexpr uint8_t YSIZE = 120;

char backstore[YSIZE][XSIZE];
char frontstore[YSIZE][XSIZE];

volatile bool quit = false;
int pfd[2];
struct termios orig_termios;

void sfpix(uint8_t x, uint8_t y, bool v)
{
    if((x) >= 0 && (x) < XSIZE && (y) >= 0 && (y) < YSIZE) \
        frontstore[(y)][(x)] = (v); \
}

int serial_open(const char *port)
{
	struct termios term_opt;
	int fd = open(port, O_RDWR);

	if(fd < 0) {
		perror("failed to open serial port");
		return -1;
	}

	tcgetattr(fd, &term_opt);
	cfsetispeed(&term_opt, B38400);
	cfsetospeed(&term_opt, B38400);
	tcsetattr(fd, TCSAFLUSH, &term_opt);
	return fd;
}

ssize_t xwrite(int fd, void *p, size_t n)
{
	ssize_t x;
	size_t s = n;
	while(n) {
		if(-1 == (x = write(fd, p, n))) {
			if(errno == EINTR)
				continue;
			return -1;
		}
		if(!x)
			return s - n;
		n -= x;
		p += x;
	}
	return s;
}

ssize_t xread(int fd, char *p, size_t n)
{
	ssize_t x;
	size_t s = n;
	while(n) {
		if(-1 == (x = read(fd, p, n))) {
			if(errno == EINTR)
				continue;
		}
		if(!x)
			return s - n;
		n -= x;
		p += x;
	}
	return s;
}

void scr_pixel(int fd, int x, int y, int clr)
{
	clr = clr ? 1 : 0;
	if(x >= 0 && x < XSIZE && y >= 0 && y < YSIZE) {
		if(backstore[y][x] ^ clr) {
			uint8_t buf[2];
			buf[0] = x | (clr ? 0x80 : 0);
			buf[1] = y;
			xwrite(fd, buf, 2);
			backstore[y][x] = clr;
		}
	}
}

void scr_frontmap(int fd)
{
	int x, y;

	for(y = 0; y < YSIZE; y++) {
		for(x = 0; x < XSIZE; x++) {
			scr_pixel(fd, x, y, frontstore[y][x]);
		}
	}
}

void clear(int fd)
{
    /*
    memset(frontstore, 0, sizeof(frontstore));
    scr_frontmap(fd);
    */
    int x, y;
    for(y = 0; y < YSIZE; y++) {
		for(x = 0; x < XSIZE; x++) {
			scr_pixel(fd, x, y, 1);
		}
	}
}

static const char usage_str[] =
"Usage: osaa_irc [-h] <ttyDevice>\n \
 Hook up to #osaa at freenode, via;\n \
   tail -f ircbot/a.log | ./osaa_irc <ttyDevice>\n \
 Assuming ircbot is running.\n"
	;

static void sighandler(int sig)
{
	(void)sig;
	quit = true;
}

static void sigalrm(int sig)
{
	char c = 0;
	(void)sig;
	xwrite(pfd[1], &c, 1);
}

void reset_tty(void)
{
	tcsetattr(0, TCSAFLUSH, &orig_termios);
}

// Function, which renders a single letter 'l' at char_y, char_x
void put_letter(int char_y, int scroll_x, int char_x, Letter l)
{
    int x, y;
    for(x = scroll_x; x < l.letter_width; x++)
    {
        for(y = 0; y < LETTER_HEIGHT; y++)
        {
            sfpix(char_y + y, char_x + x, l.pix_map[y*l.letter_width + x + scroll_x] & 1);
        }
    }
}


// Function, which renders a single letter 'l' at char_y, char_x
void put_letter2(int char_y, int scroll_x, int char_x, Letter l)
{
    int x, y;
    for(x = 0; x < l.letter_width - scroll_x; x++)
    {
        for(y = 0; y < LETTER_HEIGHT; y++)
        {
            sfpix(char_y + y, char_x + x, l.pix_map[y*l.letter_width + x + scroll_x] & 1);
        }
    }
}


// Look up a pixel letter, via a character
Letter find_letter(char c)
{
    if(c < 0)
    {
        debug_printf("Invalid character: %c\n", c);
        return undef;
    }
    return ASCII[c];
}

struct scroll_string
{
    std::string str;
    int line;
    int scroll_pos = 0;
    int scroll_dir = 1;
    int delay = 0;
};

scroll_string strings[3];

void scroller(int fd)
{
    memset(frontstore, 0, sizeof(frontstore));
    
    auto render_string = [](std::string str, int start_line, int scroll_x)
    {
        str.append("     ");
        // The start line, and start x coordinate
        int line = start_line;
        int char_x = scroll_x == 0 ? 1 : 0;
        // Run the entire string, char by char
        for(char& c : str)
        {
            // Find the pixel letter corresponding to the char
            Letter l = find_letter(c);

            if(l.letter_width/2 < scroll_x)
            {
                scroll_x -= (l.letter_width/2);
                continue;
            }
            // We may still need to print a half character

            // If we overflow this line, by adding it, do a line break
            if(char_x + l.letter_width >= YSIZE)
            {
                return true;
            }

            // Calculate our y coord, based upon the line, we're in
            int char_y = 0 + line * (LETTER_HEIGHT + 1);
            // Do the actual printing of the character
            put_letter(char_y, scroll_x, char_x, l);
            // Move the size of this letter, and 1 character,
            // before rendering the next character
            char_x += l.letter_width;
            char_x += 1;

            scroll_x = std::max(scroll_x - (l.letter_width + 1), 0);
        }
        return false;
    };

    for(scroll_string& s : strings)
    {
        bool overflow = render_string(s.str, s.line, s.scroll_pos);
        if(overflow == false && s.scroll_dir == 1)
        {
            s.scroll_dir = -1;
            s.delay = 10;
        }

        if(s.delay == 0)
        {
            s.scroll_pos += 1 * s.scroll_dir;
        }
        else
        {
            s.delay--;
        }

        if(s.scroll_pos < 0)
        {
            s.scroll_dir = 1;
            s.scroll_pos = 0;
            s.delay = 10;
        }
    }

    // Render!
    scr_frontmap(fd);
}

void set_string(std::string str, int line)
{
    scroll_string s;
    s.str = str;
    s.line = line;

    strings[line] = s;
}

int main(int argc, char *argv[])
{
	int fd;
	int optc;
	char *serial_port = NULL;

	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	signal(SIGHUP, sighandler);
	signal(SIGALRM, sigalrm);

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	while(EOF != (optc = getopt(argc, argv, "h"))) {
		switch(optc) {
		case 'h':
			printf("%s", usage_str);
		default:
			break;
		}
	}

	if(optind >= argc) {
		fprintf(stderr, "Missing serial port\n");
		exit(1);
	} else {
		serial_port = strdup(argv[optind]);
	}

	if(-1 == pipe(pfd)) {
		perror("pipe");
		exit(1);
	}

	if((fd = serial_open(serial_port)) < 0)
    {
        debug_printf("Couldn't open serial port\n");
		exit(1);
    }

	if(isatty(0)) {
		struct termios raw;

		raw = orig_termios;
		//cfmakeraw(&raw);
		raw.c_cc[VMIN] = 0;
		raw.c_cc[VTIME] = 0;

		/* put terminal in raw mode after flushing */
		if(tcsetattr(0, TCSAFLUSH, &raw) < 0) {
			perror("tcsetattr raw mode");
			exit(1);
		}
		atexit(reset_tty);
	}

    clear(fd);
    timer_start();

	while(!quit) {
		fd_set fds;
		FD_ZERO(&fds);
		FD_SET(0, &fds);
		FD_SET(pfd[0], &fds);
		if(-1 == select(pfd[0] + 1, &fds, NULL, NULL, NULL)) {
			if(errno == EINTR)
				continue;
			perror("select");
			exit(1);
		}
		if(FD_ISSET(0, &fds)) {
            char buffer[80];
            memset(buffer, 0, sizeof(char)*80);
			ssize_t n = read(0, &buffer, 80);
			if(-1 == n) {
				perror("read char");
				exit(1);
			} else if(!n) {
				fprintf(stderr, "Serial port closed on me...\r\n");
				exit(1);
			}

            set_string(" 0 1 2 3 4 5 6 7 8 9 [ \\ ] ^ _ ` { | } ~ ", 0);
            set_string(" a b c d e f g h i j k l m o p q r t s t u v w x y z ", 1);
            set_string(" ! \" # $ % & ' ( ) * + , - . / : ; < = > ? @ ", 2);
            while(true)
            {
                usleep(100);
                scroller(fd);
            }
        }

        if(FD_ISSET(pfd[0], &fds)) {
            char c;
			timer_start();
            xread(pfd[0], &c, 1);
        }
        scr_frontmap(fd);
    }

    timer_stop();
	close(fd);
	return 0;
}
