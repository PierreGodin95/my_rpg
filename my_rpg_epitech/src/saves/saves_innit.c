/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <string.h>

btn_t *saves_new_btn(int i)
{
    btn_t *tmp = (btn_t *)malloc(sizeof(btn_t));

    tmp->s = sfSprite_create();
    btn_new_texture(tmp, "r/UI/_load/save", -1);
    tmp->is_vis = 0;
    tmp->name = strdup("Saves");
    tmp->is_hov = 0;
    tmp->next = NULL;
    tmp->callback = NULL;
    tmp->is_modal = 1;
    game.saves[i].btn = tmp;
    return tmp;
}

void saves_innit(void)
{
    btn_t *btn;
    text_t *txt;

    for (int i = 0; i < 4; i++) {
        btn = saves_new_btn(i);
        btn_origin(btn, .5, .5);
        txt = txt_create("save_txt", 0, 26, "");
        game.saves[i].txt = txt;
        text_pos(txt, (v_size_t){.5, .5, 100, 100});
    }
    btn_pos(game.saves[0].btn, (v_size_t){0.5, 0.5, 0, -230});
    text_pos(game.saves[0].txt, (v_size_t){0.5, 0.5, -330, -265});
    btn_pos(game.saves[1].btn, (v_size_t){0.5, 0.5, 0, -100});
    text_pos(game.saves[1].txt, (v_size_t){0.5, 0.5, -330, -135});
    btn_pos(game.saves[2].btn, (v_size_t){0.5, 0.5, 0, 30});
    text_pos(game.saves[2].txt, (v_size_t){0.5, 0.5, -330, -5});
    btn_pos(game.saves[3].btn, (v_size_t){0.5, 0.5, 0, 160});
    text_pos(game.saves[3].txt, (v_size_t){0.5, 0.5, -330, 125});
}
