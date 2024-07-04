/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

void text_linked(text_t *tmp)
{
    text_t *temp = game.ui.texts;

    if (temp == NULL) {
        game.ui.texts = tmp;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = tmp;
    }
}

text_t *txt_create(char *name, int font, int font_size, char *txt)
{
    text_t *tmp = (text_t *)malloc(sizeof(text_t));

    tmp->t = sfText_create();
    tmp->name = strdup(name);
    tmp->next = NULL;
    tmp->is_modal = 0;
    sfText_setFont(tmp->t, game.ui.font[font]);
    sfText_setCharacterSize(tmp->t, font_size);
    sfText_setString(tmp->t, txt);
    return tmp;
}

void text_pos(text_t *txt, v_size_t pos)
{
    float x = (game.pref.x * pos.s_x) + pos.x;
    float y = (game.pref.y * pos.s_y) + pos.y;

    sfText_setPosition(txt->t, (sfVector2f){x, y});
}

void text_origin(text_t *txt, float x, float y)
{
    sfVector2f anchor = {
        x * sfText_getGlobalBounds(txt->t).width,
        y * sfText_getGlobalBounds(txt->t).height};

    sfText_setOrigin(txt->t, anchor);
}

int text_set_vis(char *name, int is_vis, int group)
{
    text_t *curr = game.ui.texts;
    int found = 0;

    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            curr->is_vis = is_vis;
            found++;
        }
        if (group == 0 && found == 1)
            return 1;
        curr = curr->next;
    }
    return found;
}
