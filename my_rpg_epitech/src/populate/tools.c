/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

void ui_bp_populate(void)
{
    text_t *btn;
    text_t *txt = txt_create("bp_stats", 0, 20, "Stats go here");

    for (int i = 0; i < 4; i++) {
        btn = txt_create("slot", 0, 0, "slot");
        text_pos(btn, (v_size_t){.5, .5, -205 + (i * 100), 183});
    }
    text_pos(txt, (v_size_t){.5, .5, -225, 0});
    text_origin(txt, 0.5, 0.5);
    text_linked(txt);
}
