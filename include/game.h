typedef enum g_state_t
{
    g_state_menu,
    g_state_paused,
    g_state_playing,
} g_state;

extern g_state g_currentState;

void g_menu();
void g_start(int level);