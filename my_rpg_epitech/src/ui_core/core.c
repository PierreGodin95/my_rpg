/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <SFML/System/Sleep.h>
#include <SFML/System/Time.h>

void ui_main_closeall2(btn_t *btn)
{
    text_set_vis("bp_stats", 0, 0);
    for (int i = 0; i < 4; i++)
        game.saves[i].btn->is_vis = 0;
    sfSleep(sfMilliseconds(10));
    game.ui.ui_id = 0;
}

void ui_main_closeall(btn_t *btn)
{
    btn_t *btn_curr = game.ui.btns;
    text_t *txt_curr = game.ui.texts;

    game.paused = 0;
    game.backpack.is_open = 0;
    btns_unhover();
    while (btn_curr != NULL) {
        if (btn_curr->is_modal > 0)
            btn_curr->is_vis = 0;
        btn_curr = btn_curr->next;
    }
    while (txt_curr != NULL) {
        if (txt_curr->is_modal > 0)
            txt_curr->is_vis = 0;
        txt_curr = txt_curr->next;
    }
    ui_main_closeall2(btn);
}
