/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

modal_t *modal_create(char *t_path, int vis, int index)
{
    modal_t *tmp = (modal_t *)malloc(sizeof(modal_t));
    modal_t *temp = NULL;

    tmp->t = sfTexture_createFromFile(t_path, NULL);
    tmp->s = sfSprite_create();
    sfSprite_setTexture(tmp->s, tmp->t, sfTrue);
    tmp->is_vis = vis;
    tmp->index = index;
    tmp->next = NULL;
    if (game.ui.modals == NULL) {
        game.ui.modals = tmp;
    } else {
        temp = game.ui.modals;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = tmp;
    }
    return tmp;
}

void modal_pos(modal_t *s, float x, float y)
{
    sfVector2f pos = {x, y};

    if (s == NULL)
        return;
    sfSprite_setPosition(s->s, pos);
}

void modal_size(modal_t *s, float x, float y)
{
    sfVector2f scale = {x / sfSprite_getGlobalBounds(s->s).width,
    y / sfSprite_getGlobalBounds(s->s).height};

    sfSprite_setScale(s->s, scale);
}

void modal_origin(modal_t *s, float x, float y)
{
    sfVector2f anchor = {x, y};

    sfSprite_setOrigin(s->s, anchor);
}

void modal_destroy(modal_t *s)
{
    modal_t *prev = NULL;

    if (s == NULL)
        return;
    sfTexture_destroy(s->t);
    sfSprite_destroy(s->s);
    if (game.ui.modals == s) {
        game.ui.modals = game.ui.modals->next;
        free(s);
    } else {
        prev = game.ui.modals;
        while (prev != NULL && prev->next != s)
            prev = prev->next;
        if (prev != NULL) {
            prev->next = s->next;
            free(s);
        }
    }
}
