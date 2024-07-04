/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

rect_t *rect_create(int vis, int index)
{
    rect_t *tmp = (rect_t *)malloc(sizeof(rect_t));
    rect_t *temp = NULL;

    tmp->s = sfRectangleShape_create();
    tmp->is_vis = vis;
    tmp->index = index;
    tmp->next = NULL;
    if (game.ui.rects == NULL) {
        game.ui.rects = tmp;
    } else {
        temp = game.ui.rects;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = tmp;
    }
    return tmp;
}

void rect_pos(rect_t *s, float x, float y)
{
    sfVector2f pos = {x, y};

    if (s == NULL)
        return;
    sfRectangleShape_setPosition(s->s, pos);
}

void rect_size(rect_t *s, float x, float y)
{
    sfVector2f scale = {x, y};

    sfRectangleShape_setSize(s->s, scale);
}

void rect_origin(rect_t *s, float x, float y)
{
    sfVector2f anchor = {x, y};

    sfRectangleShape_setOrigin(s->s, anchor);
}

void rect_destroy(rect_t *s)
{
    rect_t *prev = NULL;

    if (s == NULL)
        return;
    sfRectangleShape_destroy(s->s);
    if (game.ui.rects == s) {
        game.ui.rects = game.ui.rects->next;
        free(s);
    } else {
        prev = game.ui.rects;
        while (prev != NULL && prev->next != s)
            prev = prev->next;
        if (prev != NULL) {
            prev->next = s->next;
            free(s);
        }
    }
}
