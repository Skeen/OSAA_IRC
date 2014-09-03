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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/time.h>
#include <math.h>

#define DEBUG
#ifdef DEBUG
#define debug_printf	printf
#else
#define debug_printf(f,...)
#endif

#include "font.hpp"

constexpr uint8_t XSIZE = 20;
constexpr uint8_t YSIZE = 120;

char backstore[YSIZE][XSIZE];
char frontstore[YSIZE][XSIZE];

volatile bool quit = false;
int pfd[2];
struct termios orig_termios;

#define sfpix(x,y,v)	do { \
				if((x) >= 0 && (x) < XSIZE && (y) >= 0 && (y) < YSIZE) \
					frontstore[(y)][(x)] = (v); \
			} while(0);
#define iscol(x,y)	((x) >= 0 && (x) < XSIZE && (y) >= 0 && (y) < YSIZE && frontstore[(y)][(x)])

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
    int x, y;
    for(y = 0; y < YSIZE; y++) {
		for(x = 0; x < XSIZE; x++) {
			scr_pixel(fd, x, y, 1);
		}
	}
}

static const char usage_str[] =
	"Usage: osaa_irc [-h] <ttyDevice>\n"
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

#define SCREEN_HEIGHT 3
#define SCREEN_WIDTH 18

char SCREEN[SCREEN_HEIGHT][SCREEN_WIDTH];

void scroll()
{
    int line;
    int character;
    // MOVE LINES UP
    for(line = 1; line < SCREEN_HEIGHT; line++)
    {
        for(character = 0; character < SCREEN_WIDTH; character++)
        {
            SCREEN[line-1][character] = SCREEN[line][character];
        }
    }
    // CLEAR NEW LINE
    for(character = 0; character < SCREEN_WIDTH; character++)
    {
        SCREEN[SCREEN_HEIGHT - 1][character] = ' ';
    }
}

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void put_string(int line, char* str)
{
    if(line > SCREEN_HEIGHT)
    {
        debug_printf("trying to write invalid line number");
        exit(-1);
    }
    
    int x;
    for(x=0; str[x] != '\0' && x < SCREEN_WIDTH; x++)
    {
        SCREEN[line][x] = str[x];
    }
    x = MAX(0, x-1);
    for(; x<SCREEN_WIDTH; x++)
    {
        SCREEN[line][x] = ' ';
    }
}

void put_string_scroll(char* str)
{
    scroll();
    put_string(SCREEN_HEIGHT - 1, str);
}

void clear_line(int line)
{
    for(int x = 0; x < XSIZE; x++)
    {
        for(int y = 0; y < LETTER_HEIGHT; y++)
        {
            sfpix(y + line * (LETTER_HEIGHT + 1), x, 0);
        }
    }
}

int put_letter(int char_y, int char_x, Letter l)
{
    int x, y;
    for(x = 0; x < l.letter_width; x++)
    {
        for(y = 0; y < LETTER_HEIGHT; y++)
        {
            sfpix(char_y + y, char_x + x, l.pix_map[y*l.letter_width + x] & 1);
        }
    }
    return l.letter_width;
}

int put_character(int char_y, int char_x, char c)
{
    int index = c - 97;
    if(index >= 0 && index < 28)
    {
        return put_letter(char_y, char_x, Alphabet[index]);
    }
    else
    {
        index = c - 65;
        if(index >= 0 && index < 28)
        {
            return put_letter(char_y, char_x, Alphabet[index]);
        }
        switch(c)
        {
            case ' ':
                return put_letter(char_y, char_x, space);
                break;
            case ',':
                return put_letter(char_y, char_x, comma);
                break;
            case '.':
                return put_letter(char_y, char_x, dot);
                break;
            case ':':
                return put_letter(char_y, char_x, colon);
                break;
            case '\n':
                return 0;
                break;
            default:
                return put_letter(char_y, char_x, undef);
                break;
        }
    }
    return 0;
}

void render_screen(int fd)
{
    int line, character;
    for(line = 0; line < SCREEN_HEIGHT; line++)
    {
        clear_line(line);

        int char_x = 1;
        for(character = 0; character < SCREEN_WIDTH; character++)
        {
            int char_y = 0 + line * (LETTER_HEIGHT + 1);
            char_x += put_character(char_y, char_x, SCREEN[line][character]);
            char_x += 1;
        }
    }
    scr_frontmap(fd);
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
        debug_printf("Couldn't open serial port");
		exit(1);
    }

	/* save the original terminal setup to restore at exit */
    /*
	if(tcgetattr(0,&orig_termios) < 0) {
		perror("tcgetattr terminal");
		exit(1);
	}
    */

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
			//char c;
            //debug_printf("READING");
			ssize_t n = read(0, &buffer, 80);
            //debug_printf("DONE READING");
			if(-1 == n) {
				perror("read char");
				exit(1);
			} else if(!n) {
				fprintf(stderr, "Serial port closed on me...\r\n");
				exit(1);
			}

            put_string_scroll(buffer);
            render_screen(fd);

			switch(buffer[0]) {
                case 'T':
                    debug_printf("'space' pressed\r\n");
                    clear(fd);
                    put_letter(0,0,space);
                    break;

                case 'R':
				    debug_printf("'R' pressed\r\n");
                    quit = true;
				    break;
			}
        }

        if(FD_ISSET(pfd[0], &fds)) {
            char c;
            xread(pfd[0], &c, 1);
        }
        scr_frontmap(fd);
    }

	close(fd);
	return 0;
}
