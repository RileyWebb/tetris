#include "game.h"
#include "console.h"

g_state g_currentState;

void g_drawMenu()
{
    static char charColors[6] = {CON_COLOR_RED, CON_COLOR_BLUE, CON_COLOR_GREEN, CON_COLOR_YELLOW, CON_COLOR_CYAN, CON_COLOR_BRIGHTRED};

    //T
    con_setPixel(4,3,charColors[0]);
    con_setPixel(5,3,charColors[0]);
    con_setPixel(6,3,charColors[0]);
    con_setPixel(7,3,charColors[0]);
    con_setPixel(8,3,charColors[0]);
    con_setPixel(6,4,charColors[0]);
    con_setPixel(6,5,charColors[0]);
    con_setPixel(6,6,charColors[0]);
    con_setPixel(6,7,charColors[0]);
    //E
    con_setPixel(10,3,charColors[1]);
    con_setPixel(11,3,charColors[1]);
    con_setPixel(12,3,charColors[1]);
    con_setPixel(13,3,charColors[1]);
    con_setPixel(10,4,charColors[1]);
    con_setPixel(10,5,charColors[1]);
    con_setPixel(11,5,charColors[1]);
    con_setPixel(12,5,charColors[1]);
    con_setPixel(13,5,charColors[1]);
    con_setPixel(10,6,charColors[1]);
    con_setPixel(10,7,charColors[1]);
    con_setPixel(11,7,charColors[1]);
    con_setPixel(12,7,charColors[1]);
    con_setPixel(13,7,charColors[1]);
    //T
    con_setPixel(15,3,charColors[2]);
    con_setPixel(16,3,charColors[2]);
    con_setPixel(17,3,charColors[2]);
    con_setPixel(18,3,charColors[2]);
    con_setPixel(19,3,charColors[2]);
    con_setPixel(17,4,charColors[2]);
    con_setPixel(17,5,charColors[2]);
    con_setPixel(17,6,charColors[2]);
    con_setPixel(17,7,charColors[2]);
    //R
    con_setPixel(21,3,charColors[3]);
    con_setPixel(21,4,charColors[3]);
    con_setPixel(21,5,charColors[3]);
    con_setPixel(21,6,charColors[3]);
    con_setPixel(21,7,charColors[3]);
    con_setPixel(22,3,charColors[3]);
    con_setPixel(23,3,charColors[3]);
    con_setPixel(24,3,charColors[3]);
    con_setPixel(24,4,charColors[3]);
    con_setPixel(24,5,charColors[3]);
    con_setPixel(23,5,charColors[3]);
    con_setPixel(22,5,charColors[3]);
    con_setPixel(23,6,charColors[3]);
    con_setPixel(24,7,charColors[3]);
    //I
    con_setPixel(26,3,charColors[4]);
    con_setPixel(27,3,charColors[4]);
    con_setPixel(28,3,charColors[4]);
    con_setPixel(29,3,charColors[4]);
    con_setPixel(30,3,charColors[4]);
    con_setPixel(28,4,charColors[4]);
    con_setPixel(28,5,charColors[4]);
    con_setPixel(28,6,charColors[4]);
    con_setPixel(28,7,charColors[4]);
    con_setPixel(26,7,charColors[4]);
    con_setPixel(27,7,charColors[4]);
    con_setPixel(29,7,charColors[4]);
    con_setPixel(30,7,charColors[4]);
    //S
    con_setPixel(32,3,charColors[5]);
    con_setPixel(33,3,charColors[5]);
    con_setPixel(34,3,charColors[5]);
    con_setPixel(35,3,charColors[5]);
    con_setPixel(36,3,charColors[5]);
    con_setPixel(32,4,charColors[5]);
    con_setPixel(32,5,charColors[5]);
    con_setPixel(33,5,charColors[5]);
    con_setPixel(34,5,charColors[5]);
    con_setPixel(35,5,charColors[5]);
    con_setPixel(36,5,charColors[5]);
    con_setPixel(36,6,charColors[5]);
    con_setPixel(36,7,charColors[5]);
    con_setPixel(35,7,charColors[5]);
    con_setPixel(34,7,charColors[5]);
    con_setPixel(33,7,charColors[5]);
    con_setPixel(32,7,charColors[5]);

    int tempData  = charColors[0];
    for(size_t k = 0; k < 6-1; k++){
        charColors[k] = charColors[k+1];
    }

    charColors[6-1] = tempData;

    con_drawString(6, 6,"\033[1m[X] PLAY\033[0m");
    //printf("\\a");
}

void g_menu()
{
    con_resize(41,14);

    con_draw();
    con_forceDraw();

    while (1)
    {
        g_drawMenu();
        con_draw();
        _sleep(650);
    }
}

void g_start(int level)
{
    g_currentState = g_state_playing;
    

}