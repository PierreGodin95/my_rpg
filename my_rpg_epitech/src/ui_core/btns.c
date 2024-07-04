/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <string.h>

static btn_t *set_tmp(btn_t *tmp, char *name, int vis, int index)
{
    tmp->s = sfSprite_create();
    tmp->is_vis = vis;
    tmp->name = strdup(name);
    tmp->index = index;
    tmp->is_hov = 0;
    tmp->is_modal = 0;
    tmp->next = NULL;
    tmp->callback = NULL;
    return tmp;
}

btn_t *btn_create(char *name, char *t_path, int vis, int index)
{
    btn_t *tmp = (btn_t *)malloc(sizeof(btn_t));
    btn_t *temp = NULL;

    tmp = set_tmp(tmp, name, vis, index);
    btn_new_texture(tmp, t_path, -1);
    if (game.ui.btns == NULL) {
        game.ui.btns = tmp;
    } else {
        temp = game.ui.btns;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = tmp;
    }
    z_index_sort();
    return tmp;
}

/*
Changes the position of a button instance

@ btn_t *s
Button element to change the position of

@v_size_t size
eg. (v_size_t){.5, .0, 100, -200}

    float s_x/s_y = Scale in the X/Y axis
                    from 0.0 to 1.0, tdlr %

    float x/y = offset position in px
*/
void btn_pos(btn_t *s, v_size_t size)
{
    sfVector2f pos;

    pos.x = (game.pref.x * size.s_x) + size.x;
    pos.y = (game.pref.y * size.s_y) + size.y;
    sfSprite_setPosition(s->s, pos);
}

void btn_size(btn_t *s, float x, float y)
{
    sfVector2f scale = {};

    scale.x = x / sfSprite_getGlobalBounds(s->s).width;
    scale.y = y / sfSprite_getGlobalBounds(s->s).height;
    sfSprite_setScale(s->s, scale);
}

void btn_scale(btn_t *s, float x, float y)
{
    sfSprite_setScale(s->s, (sfVector2f){x, y});
}

void btn_origin(btn_t *s, float x, float y)
{
    sfVector2f anchor = {
        x * sfSprite_getGlobalBounds(s->s).width,
        y * sfSprite_getGlobalBounds(s->s).height};

    sfSprite_setOrigin(s->s, anchor);
}
