#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CON_DISABLECURSOR()         printf("\e[?25l");
#define CON_DISABLESCROLLBAR()      printf("\033[?30l");
#define CON_SETSIZE(width, height)  printf("\e[8;%d;%dt", height, width);
#define CON_SETTITLE(format, ...)   printf("\033]0;"#format"\007", __VA_ARGS__);
#define CON_SETCURSOR(x, y)         printf("\033[%d;%dH", y, x);

#define ASCII_PIXEL 0xDC

#define CON_COLOR_BLACK 30
#define CON_COLOR_RED 31
#define CON_COLOR_GREEN 32
#define CON_COLOR_YELLOW 33
#define CON_COLOR_BLUE 34
#define CON_COLOR_MAGENTA 35
#define CON_COLOR_CYAN 36
#define CON_COLOR_DARKGRAY 37

#define CON_COLOR_LIGHTGRAY 90
#define CON_COLOR_BRIGHTRED 91
#define CON_COLOR_BRIGHTGREEN 92
#define CON_COLOR_BRIGHTYELLOW 93
#define CON_COLOR_BRIGHTBLUE 94
#define CON_COLOR_BRIGHTMAGENTA 95
#define CON_COLOR_BRIGHTCYAN 96
#define CON_COLOR_WHITE 97

typedef enum con_display_mode_t
{
    con_display_mode_pixel,
    con_display_mode_hybrid,
    con_display_mode_text,
} con_display_mode;

typedef struct con_pixel_t
{
    char data;
    char fgcolor;
    char bgcolor;
} con_pixel;

extern con_display_mode con_mode;
extern int con_width, con_height;
extern con_pixel **con_framebuffer;

void con_init(con_display_mode mode);
void con_resize(int width, int height);
void con_setPixel(int x, int y, char color);
void con_drawString(int x, int y, char *text);
void con_draw();
void con_forceDraw();
