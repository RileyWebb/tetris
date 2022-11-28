#include "console.h"

#define COMMANDBUFFERSIZE 16448

con_display_mode con_mode = con_display_mode_hybrid;
int con_width = 60, con_height = 15;
con_pixel **con_framebuffer;

char commmandBuffer[COMMANDBUFFERSIZE];

void con_init(con_display_mode mode)
{
    setvbuf(stdout, &commmandBuffer, _IOFBF, 16448);

    CON_DISABLECURSOR();
    CON_DISABLESCROLLBAR();

    con_resize(con_width, con_height);
}

void con_resize(int width, int height)
{
    con_width = width;
    con_height = height;

    if(&con_framebuffer != NULL)
        free(con_framebuffer);

    con_framebuffer = (con_pixel **) malloc(con_width * sizeof(con_pixel *));
    for (size_t r = 0; r < con_width; r++)
        con_framebuffer[r] = (con_pixel*) malloc(con_height * sizeof(con_pixel));

    for (size_t x = 0; x < con_width; x++)
        for (size_t y = 0; y < con_height; y++)
        {
            con_framebuffer[x][y].data = ASCII_PIXEL;
            con_framebuffer[x][y].fgcolor = CON_COLOR_BLACK;
            con_framebuffer[x][y].bgcolor = CON_COLOR_BLACK;
        }

    CON_SETSIZE(con_width, con_height);

    con_forceDraw();
}

void con_setPixel(int x, int y, char color)
{
    if (y % 2 == 0)
        con_framebuffer[x][y/2].fgcolor = color;
    else
        con_framebuffer[x][y/2].bgcolor = color;

    con_framebuffer[x][y/2].data = ASCII_PIXEL;

    CON_SETCURSOR(x + 1, y / 2 + 1);
    printf("\033[%d;%dm%c\033[0m", con_framebuffer[x][y/2].bgcolor, con_framebuffer[x][y/2].fgcolor + 10, con_framebuffer[x][y/2].data);
}

void con_drawString(int x, int y, char *text)
{
    CON_SETCURSOR(x + 1, y + 1);
    printf("%s", text);
}

void con_draw()
{
    fflush(stdout);
}

void con_forceDraw()
{
    printf("\033[0;0H"); //Set Cursor To 0, 0

    for (size_t y = 0; y < con_height; y++)
    {
        for (size_t x = 0; x < con_width; x++)
            printf("\x1B[%d;%dm%c\033[0m", con_framebuffer[x][y].bgcolor, con_framebuffer[x][y].fgcolor + 10,
                   con_framebuffer[x][y].data);

        //if (!(y > con_height - 1))
            //printf("\n");
    }

    fflush(stdout);
}

void con_clear()
{
    memset(&commmandBuffer, 0, COMMANDBUFFERSIZE);
    con_resize(con_width, con_height);
}