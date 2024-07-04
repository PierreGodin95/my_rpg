/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

void ui_pause_req_sett3(void)
{
    text_t *txt = txt_create("ui_pref_windres", 0, 20, "1920x1080");

    text_pos(txt, (v_size_t){.5, .5, -205, 183});
    text_origin(txt, 0.5, 0.5);
    text_linked(txt);
    txt->is_modal = 1;
    txt = txt_create("ui_pref_windmode", 0, 20, "Windowed");
    text_pos(txt, (v_size_t){.5, .5, 185, 183});
    text_origin(txt, 0.5, 0.5);
    txt->is_modal = 1;
    text_linked(txt);
    ui_pause_req_sett4();
}

void ui_pause_req_sett2(btn_t *btn)
{
    btn = btn_create("ui_pref_btn", "r/UI/_pref/arrow_side", 0, 3);
    btn_pos(btn, (v_size_t){.5, .5, -65, 185});
    btn_origin(btn, .5, .5);
    btn->callback = pref_resolution_mode;
    btn->is_modal = 1;
    sfSprite_rotate(btn->s, 180.0);
    btn = btn_create("ui_pref_btn", "r/UI/_pref/arrow_side", 0, 3);
    btn_pos(btn, (v_size_t){.5, .5, 45, 191});
    btn_origin(btn, .5, .5);
    btn->callback = pref_window_mode;
    btn->is_modal = 1;
    btn = btn_create("ui_pref_btn", "r/UI/_pref/arrow_side", 0, 3);
    btn_pos(btn, (v_size_t){.5, .5, 330, 185});
    btn_origin(btn, .5, .5);
    btn->is_modal = 1;
    btn->callback = pref_window_mode;
    sfSprite_rotate(btn->s, 180.0);
    ui_pause_req_sett3();
}

void ui_pause_req_sett(void)
{
    btn_t *btn;

    btn = btn_create("ui_pref_back", "r/UI/_pref/back", 0, 2);
    btn_pos(btn, (v_size_t){.5, .5, 0, -50});
    btn_origin(btn, .5, .5);
    btn->is_modal = 1;
    btn = btn_create("ui_pref_close", "r/UI/close", 0, 3);
    btn_pos(btn, (v_size_t){.5, .5, 300, 332});
    btn_origin(btn, .5, .5);
    btn->is_modal = 1;
    btn->callback = ui_main_closeall;
    btn = btn_create("ui_pref_btn", "r/UI/_pref/arrow_side", 0, 3);
    btn_pos(btn, (v_size_t){.5, .5, -340, 191});
    btn_origin(btn, .5, .5);
    btn->callback = pref_resolution_mode;
    btn->is_modal = 1;
    ui_pause_req_sett2(btn);
}
