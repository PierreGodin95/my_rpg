/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <stdio.h>

void btn_click(btn_t *tmp, int ishov)
{
    if (ishov != 1)
        return;
    if (tmp->t[2] != NULL)
            sfSprite_setTexture(tmp->s, tmp->t[2], sfTrue);
    tmp->callback(tmp);
}

void btns_click(void)
{
    btn_t *curr = game.ui.btns;
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(game.w);
    sfFloatRect bounds;

    while (curr != NULL) {
        if (curr->callback != NULL && game.ui.ui_id == curr->is_modal
        && curr->is_vis == 1) {
            bounds = sfSprite_getGlobalBounds(curr->s);
            btn_click(curr, sfFloatRect_contains(&bounds,
        m_pos.x, m_pos.y));
        }
        curr = curr->next;
    }
    for (int i = 0; i < 4; i++) {
        if (game.saves[i].btn == NULL || game.saves[i].btn->is_vis == 0)
            continue;
        bounds = sfSprite_getGlobalBounds(game.saves[i].btn->s);
        btn_click(game.saves[i].btn, sfFloatRect_contains(&bounds,
        m_pos.x, m_pos.y));
    }
}

void btns_unclick(void)
{
    btn_t *curr = game.ui.btns;

    while (curr != NULL) {
        if (curr->callback != NULL && curr->is_hov != 1
        && curr->t[2] != NULL) {
            sfSprite_setTexture(curr->s, curr->t[0], sfTrue);
        }
        curr = curr->next;
    }
}
