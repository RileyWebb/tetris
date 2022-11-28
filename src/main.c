#include <stdio.h>

#include "console.h"
#include "game.h"

int main(void) {
    con_init(con_display_mode_hybrid);

    g_menu();
    g_start(0);
    CON_SETSIZE(10,10);
    CON_SETTITLE(%s, "Tetris");
    printf("Hello, World!\n");
    while(getchar()){}
    return 0;
}
