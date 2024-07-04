/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>

void hb_ui_backpack(void)
{
    btn_t *temp = game.backpack.btn;
    text_t *txt = game.backpack.slot_txt;

    if (game.backpack.btn != NULL && game.backpack.is_open == 1) {
        while (temp != NULL) {
            sfRenderWindow_drawSprite(game.w, temp->s, NULL);
            temp = temp->next;
        }
    }
}

void hb_ui_saves(void)
{
    if (game.saves[0].btn != NULL && game.saves[0].btn->is_vis == 1)
        for (int i = 0; i < 4; i++) {
            sfRenderWindow_drawSprite(game.w, game.saves[i].btn->s, NULL);
            sfRenderWindow_drawText(game.w, game.saves[i].txt->t, NULL);
        }
}

void hb_ui_elements()
{
    btn_t *temp = game.ui.btns;
    text_t *txt_tmp = game.ui.texts;

    while (temp != NULL) {
        if (temp->is_vis == 1)
            sfRenderWindow_drawSprite(game.w, temp->s, NULL);
        temp = temp->next;
    }
    while (txt_tmp != NULL) {
        if (txt_tmp->is_vis == 1)
            sfRenderWindow_drawText(game.w, txt_tmp->t, NULL);
        txt_tmp = txt_tmp->next;
    }
    hb_ui_saves();
    hb_ui_backpack();
}
