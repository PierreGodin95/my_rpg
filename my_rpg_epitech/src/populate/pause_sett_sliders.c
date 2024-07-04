/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

void ui_pause_req_sett5(btn_t *btn)
{
    btn = btn_create("ui_pref_s_h_1", "r/UI/_pref/hitbox", 0, 3);
    btn_pos(btn, (v_size_t){0.5, 0.5, -370, -145});
    btn->callback = pref_upt_slider;
    btn->is_modal = 1;
    btn = btn_create("ui_pref_s_h_2", "r/UI/_pref/hitbox", 0, 3);
    btn_pos(btn, (v_size_t){0.5, 0.5, -370, -35});
    btn->callback = pref_upt_slider;
    btn->is_modal = 1;
    btn = btn_create("ui_pref_s_h_3", "r/UI/_pref/hitbox", 0, 3);
    btn_pos(btn, (v_size_t){0.5, 0.5, -370, -260});
    btn->callback = pref_upt_slider;
    btn->is_modal = 1;
    btn = btn_create("ui_pref_s_h_4", "r/UI/_pref/hitbox", 0, 3);
    btn_pos(btn, (v_size_t){0.5, 0.5, 15, -150});
    btn->callback = pref_upt_slider;
    btn->is_modal = 1;
    btn = btn_create("ui_pref_s_h_5", "r/UI/_pref/hitbox", 0, 3);
    btn_pos(btn, (v_size_t){0.5, 0.5, 15, -260});
    btn->callback = pref_upt_slider;
    btn->is_modal = 1;
}

/*
BGS
SFX
BGM
FPS
TEXT SPEED
*/
void ui_pause_req_sett6(btn_t *btn)
{
    btn = btn_create("ui_pref_s_f_5", "r/UI/_pref/slide_fill", 0, 3);
    btn_pos(btn, (v_size_t){0.5, 0.5, 68, -248});
    btn_scale(btn, 275.0, 1.0);
    btn->is_modal = 1;
    ui_pause_req_sett5(btn);
}

void ui_pause_req_sett4(void)
{
    btn_t *btn;

    btn = btn_create("ui_pref_s_f_1", "r/UI/_pref/slide_fill", 0, 3);
    btn_pos(btn, (v_size_t){0.5, 0.5, -320, -135});
    btn_scale(btn, 275.0, 1.0);
    btn->is_modal = 1;
    btn = btn_create("ui_pref_s_f_2", "r/UI/_pref/slide_fill", 0, 3);
    btn_pos(btn, (v_size_t){0.5, 0.5, -320, -23});
    btn_scale(btn, 275.0, 1.0);
    btn->is_modal = 1;
    btn = btn_create("ui_pref_s_f_3", "r/UI/_pref/slide_fill", 0, 3);
    btn_pos(btn, (v_size_t){0.5, 0.5, -320, -248});
    btn_scale(btn, 275.0, 1.0);
    btn->is_modal = 1;
    btn = btn_create("ui_pref_s_f_4", "r/UI/_pref/slide_fill", 0, 3);
    btn_pos(btn, (v_size_t){0.5, 0.5, 68, -135});
    btn_scale(btn, 275.0, 1.0);
    btn->is_modal = 1;
    ui_pause_req_sett6(btn);
}
