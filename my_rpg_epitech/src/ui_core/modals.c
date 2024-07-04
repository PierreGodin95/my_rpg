/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

sprite_t *sprite_create(char name[T_NAME], char *t_path, int vis, int index)
{
    sprite_t *tmp = (sprite_t *)malloc(sizeof(sprite_t));
    sprite_t *temp = NULL;

    tmp->t = sfTexture_createFromFile(t_path, NULL);
    tmp->s = sfSprite_create();
    sfSprite_setTexture(tmp->s, tmp->t, sfTrue);
    tmp->is_vis = vis;
    tmp->index = index;
    m_strcpy(tmp->name, name);
    tmp->next = NULL;
    if (game.ui.sprites == NULL) {
        game.ui.sprites = tmp;
    } else {
        temp = game.ui.sprites;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = tmp;
    }
    return tmp;
}

void sprite_pos(sprite_t *s, float x, float y)
{
    sfVector2f pos = {x, y};

    if (s == NULL)
        return;
    sfSprite_setPosition(s->s, pos);
}

void sprite_size(sprite_t *s, float x, float y)
{
    sfVector2f scale = {x / sfSprite_getGlobalBounds(s->s).width,
    y / sfSprite_getGlobalBounds(s->s).height};

    sfSprite_setScale(s->s, scale);
}

void sprite_origin(sprite_t *s, float x, float y)
{
    sfVector2f anchor = {x, y};

    sfSprite_setOrigin(s->s, anchor);
}

void sprite_destroy(sprite_t *s)
{
    sprite_t *prev = NULL;

    if (s == NULL)
        return;
    sfTexture_destroy(s->t);
    sfSprite_destroy(s->s);
    if (game.ui.sprites == s) {
        game.ui.sprites = game.ui.sprites->next;
        free(s);
    } else {
        prev = game.ui.sprites;
        while (prev != NULL && prev->next != s)
            prev = prev->next;
        if (prev != NULL) {
            prev->next = s->next;
            free(s);
        }
    }
}
