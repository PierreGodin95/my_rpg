/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/

#include "../../h/main.h"

void backpack_show_btn(btn_t *btn)
{
    ui_main_closeall(btn);
    backpack_show(1);
}

void backpack_show(int state)
{
    if (btn_set_vis("backpack_ui", state, 1) == 0 && state == 1) {
        populate_backpack_ui();
        btn_set_vis("backpack_ui", state, 1);
    }
    bp_update();
    text_set_vis("bp_stats", 1, 0);
    game.ui.ui_id = state;
    game.backpack.is_open = state;
    game.paused = state;
}

void bp_set_item_pos(btn_t *tmp)
{
    btn_t *temp = NULL;

    if (game.backpack.btn == NULL) {
        game.backpack.btn = tmp;
    } else {
        temp = game.backpack.btn;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = tmp;
    }
}

btn_t *bp_setslot(int slot, item_t data)
{
    btn_t *tmp = (btn_t *)malloc(sizeof(btn_t));

    tmp->t[0] =
    sfTexture_createFromFile(data.texture, NULL);
    sfSprite_setTexture(tmp->s, tmp->t[0], sfTrue);
    tmp->data_id = slot;
    bp_set_item_pos(tmp);
    return tmp;
}
