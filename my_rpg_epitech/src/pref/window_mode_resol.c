/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <SFML/Window/Window.h>

/*
WIN MODE
0: Window Mode
1: Fullscreen Mode
2: Borderless Window
*/
void pref_update_window(void)
{
    sfVideoMode mode = {game.pref.x, game.pref.y, BITS};
    sfVector2i window_pos;

    sfRenderWindow_close(game.w);
    sfRenderWindow_destroy(game.w);
    window_pos.x = (sfVideoMode_getDesktopMode().width - mode.width) / 2;
    window_pos.y = (sfVideoMode_getDesktopMode().height - mode.height) / 2;
    if (game.pref.win == 0)
        game.w = sfRenderWindow_create(mode, "Final Guntasy",
    sfTitlebar | sfClose, NULL);
    if (game.pref.win == 1)
        game.w = sfRenderWindow_create(mode, "Final Guntasy",
    sfFullscreen, NULL);
    if (game.pref.win == 2)
        game.w = sfRenderWindow_create(mode, "Final Guntasy",
    sfNone, NULL);
    sfRenderWindow_setFramerateLimit(game.w, FPS);
    sfRenderWindow_setPosition(game.w, window_pos);
}

void ui_main_prefload(btn_t *btn)
{
    btn_set_vis("ui_pause_screen", 0, 1);
    game.ui.ui_id = 0;
    btns_unhover();
    game.ui.ui_id = 1;
    text_set_vis("ui_pref_windmode", 1, 0);
    text_set_vis("ui_pref_windres", 1, 0);
    btn_set_nvis("ui_pref", 1);
}

void pref_window_mode(btn_t *btn)
{
    game.pref.win += 1;
    if (game.pref.win > 2)
        game.pref.win = 0;
    if (game.pref.win == 0)
        text_set_text("ui_pref_windmode", "Windowed", 0);
    if (game.pref.win == 1)
        text_set_text("ui_pref_windmode", "Fullscreen", 0);
    if (game.pref.win == 2)
        text_set_text("ui_pref_windmode", "Borderless", 0);
    pref_update_window();
}

void pref_resolution_mode(btn_t *btn)
{
    if (game.pref.x == 1922){
        game.pref.x = 1920;
        game.pref.y = 1080;
        text_set_text("ui_pref_windres", "1920x1080", 0);
        return pref_update_window();
    }
    if (game.pref.x == 1920){
        game.pref.x = 1921;
        game.pref.y = 1081;
        text_set_text("ui_pref_windres", "1921x1081", 0);
        return pref_update_window();
    }
    if (game.pref.x == 1921){
        game.pref.x = 1922;
        game.pref.y = 1082;
        text_set_text("ui_pref_windres", "1922x1082", 0);
        return pref_update_window();
    }
}
