/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <SFML/System/Sleep.h>
#include <SFML/System/Time.h>

static void start_new_game(btn_t *btn)
{
    read_map('1', 0);
}

void help_display(btn_t *btn)
{
    btn_set_vis("help_ui", 1, 0);
    btn_set_vis("ui_load_close", 1, 0);
    game.ui.ui_id = 0;
    btns_unhover();
    game.ui.ui_id = 1;
}

void ui_main_menu_load2(btn_t *btn)
{
    text_t *tmp = txt_create("dialogue", 0, 50, "tmp");

    text_origin(tmp, 0.0f, 1.0f);
    text_pos(tmp, (v_size_t){0.0f, 1.0f, 100, -200});
    game.ui.dialogue = tmp;
    btn = btn_create("Continue Game", "r/UI/_menu/continue", 1, 1);
    btn_pos(btn, (v_size_t){1.0, 1.0, -625, -350});
    btn_origin(btn, 1, 1);
    btn->callback = start_new_game;
    btn = btn_create("How to Play", "r/UI/_menu/tutorial", 1, 1);
    btn_pos(btn, (v_size_t){1.0, 1.0, -20, -100});
    btn_origin(btn, 1, 1);
    btn->callback = help_display;
    ui_pause_requirements();
}

void ui_main_menu_load(void)
{
    btn_t *btn;

    btn = btn_create("Menu Background", "r/UI/_menu/title", 1, 0);
    btn = btn_create("New Game", "r/UI/_menu/new", 1, 1);
    btn_pos(btn, (v_size_t){1.0, 1.0, -20, -500});
    btn_origin(btn, 1, 1);
    btn->callback = start_new_game;
    btn = btn_create("Load Game", "r/UI/_menu/load", 1, 1);
    btn->callback = ui_main_saveload;
    btn_pos(btn, (v_size_t){1.0, 1.0, -20, -370});
    btn_origin(btn, 1, 1);
    btn = btn_create("Preferences", "r/UI/_menu/pref", 1, 1);
    btn_pos(btn, (v_size_t){1.0, 1.0, -140, -230});
    btn_origin(btn, 1, 1);
    btn->callback = ui_main_prefload;
    btn = btn_create("Quit Game", "r/UI/_menu/quit", 1, 1);
    btn->callback = game_quit_btn;
    btn_pos(btn, (v_size_t){1.0, 1.0, -140, -100});
    btn_origin(btn, 1, 1);
    ui_main_menu_load2(btn);
}

void toggle_main_menu(int toggle)
{
    btn_set_vis("Menu Background", toggle, 0);
    btn_set_vis("New Game", toggle, 0);
    btn_set_vis("Load Game", toggle, 0);
    btn_set_vis("Preferences", toggle, 0);
    btn_set_vis("Quit Game", toggle, 0);
    btn_set_vis("Continue Game", toggle, 0);
    btn_set_vis("How to Play", toggle, 0);
    game.main = toggle;
}

void open_main_menu(btn_t *btn)
{
    toggle_main_menu(1);
    game_pause_toggle(0);
}
