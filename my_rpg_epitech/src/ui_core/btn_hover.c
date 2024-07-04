/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <stdio.h>

void btn_unhover(btn_t *tmp)
{
    if (tmp->t[0] != NULL)
        sfSprite_setTexture(tmp->s, tmp->t[0], sfTrue);
    tmp->is_hov = 0;
}

void btns_unhover(void)
{
    btn_t *curr = game.ui.btns;

    while (curr != NULL) {
        curr->is_hov = 0;
        curr = curr->next;
    }
}

void btn_hover_sound(btn_t *tmp)
{
    sound_t *curr = game.ui.sound;

    tmp->is_hov = 1;
    while (curr != NULL) {
        if (strcmp(curr->name, "btn_hov") == 0) {
            sfSound_play(curr->s);
            break;
        }
        curr = curr->next;
    }
}

void btn_hover(btn_t *tmp, int ishov)
{
    if (ishov == 1) {
        sfSprite_setTexture(tmp->s, tmp->t[1], sfTrue);
        if (tmp->is_hov == 0)
            btn_hover_sound(tmp);
    } else if (ishov == 0 && tmp->is_hov == 1)
        btn_unhover(tmp);
}

void btns_hover(void)
{
    btn_t *curr = game.ui.btns;
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(game.w);
    sfFloatRect bounds;

    while (curr != NULL) {
        if (curr->t[1] != NULL && game.ui.ui_id == curr->is_modal) {
            bounds = sfSprite_getGlobalBounds(curr->s);
            btn_hover(curr, sfFloatRect_contains(&bounds,
        m_pos.x, m_pos.y));
        }
        curr = curr->next;
    }
}
