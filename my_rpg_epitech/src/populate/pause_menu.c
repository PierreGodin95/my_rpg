/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

void ui_pause_back2(int show, btn_t *btn)
{
    btn = btn_create("ui_pause_screen", "r/UI/_pause/load", show, 11);
    btn_pos(btn, (v_size_t){.5, .5, 57, 40});
    btn_origin(btn, .5, .5);
    btn->callback = ui_main_saveload;
    btn->is_modal = 1;
    btn = btn_create("ui_pause_screen", "r/UI/_pause/save", show, 11);
    btn_pos(btn, (v_size_t){.5, .5, -57, 40});
    btn_origin(btn, .5, .5);
    btn->callback = ui_main_saveprompt;
    btn->is_modal = 1;
    btn = btn_create("ui_pause_screen", "r/UI/_pause/sett", show, 11);
    btn_pos(btn, (v_size_t){.5, .5, 170, 40});
    btn_origin(btn, .5, .5);
    btn->is_modal = 1;
    btn->callback = ui_main_prefload;
}

void ui_pause_back(int show)
{
    btn_t *btn;

    btn = btn_create("ui_pause_screen", "r/UI/_pause/back", show, 10);
    btn_pos(btn, (v_size_t){.5, .5, 0, -50});
    btn_origin(btn, .5, .5);
    btn->is_modal = 1;
    btn = btn_create("ui_pause_screen", "r/UI/_pause/title", show, 11);
    btn_pos(btn, (v_size_t){.5, .5, 0, -65});
    btn_origin(btn, .5, .5);
    btn->callback = open_main_menu;
    btn->is_modal = 1;
    btn = btn_create("ui_pause_screen", "r/UI/_pause/backpack", show, 11);
    btn_pos(btn, (v_size_t){.5, .5, -170, 40});
    btn_origin(btn, .5, .5);
    btn->callback = backpack_show_btn;
    btn->is_modal = 1;
    ui_pause_back2(show, btn);
}

void ui_pause_req_saves(void)
{
    btn_t *btn;

    btn = btn_create("ui_load_back", "r/UI/_load/back", 0, 2);
    btn_pos(btn, (v_size_t){.5, .5, 0, -50});
    btn_origin(btn, .5, .5);
    btn->is_modal = 1;
    btn = btn_create("ui_load_close", "r/UI/close", 0, 3);
    btn_pos(btn, (v_size_t){.5, .5, 300, 332});
    btn_origin(btn, .5, .5);
    btn->is_modal = 1;
    btn->callback = ui_main_closeall;
}

void ui_pause_requirements(void)
{
    btn_t *btn = btn_create("help_ui", "r/UI/_menu/help", 0, 2);

    btn_pos(btn, (v_size_t){.5, .5, 0, -50});
    btn_origin(btn, .5, .5);
    btn->is_modal = 1;
    ui_pause_req_saves();
    ui_pause_req_sett();
}

/*
void game_pause_toggle(int force)
** Toggle the game pause state
** @param force: 0 to toggle, 1 to pause, 2 to unpause
*/
static void pause_toggle_fct(void)
{
    if (btn_set_vis("ui_pause_screen", 1, 1) == 0)
        ui_pause_back(1);
}

void game_pause_toggle(int force)
{
    if (game.ui.ui_id == 1) {
        ui_main_closeall(NULL);
        game.ui.ui_id = 0;
        game.paused = 0;
        return;
    }
    if (force == 2 || (game.paused == 1 && force == 0)) {
        game.paused = 0;
        btn_set_vis("ui_pause_screen", 0, 1);
        game.ui.ui_id = 0;
    } else if (force == 1 || game.paused == 0) {
        game.paused = 1;
        pause_toggle_fct();
        game.ui.ui_id = 1;
    }
}
