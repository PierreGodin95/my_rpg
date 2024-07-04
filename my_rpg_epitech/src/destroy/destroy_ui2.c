/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <stdlib.h>

void destroy_rect(rect_t *el)
{
    sfRectangleShape_destroy(el->s);
    free(el);
    free(game.backpack.data.M4A1.name);
    free(game.backpack.data.M4A1.texture);
    free(game.backpack.data.G17.name);
    free(game.backpack.data.G17.texture);
}

void destroy_txt(text_t *el)
{
    sfText_destroy(el->t);
    free(el);
}

void destroy_sounds(void)
{
    sound_t *cur = game.ui.sound;
    sound_t *temp = NULL;

    while (cur != NULL) {
        temp = cur;
        cur = cur->next;
        free(temp->name);
        sfSound_destroy(temp->s);
        sfSoundBuffer_destroy(temp->b);
        free(temp);
    }
}

void destroy_ui3_rects(rect_t *rects)
{
    rect_t *rect_curr = rects;
    rect_t *rect_temp = NULL;

    while (rect_curr != NULL) {
        rect_temp = rect_curr;
        rect_curr = rect_curr->next;
        destroy_rect(rect_temp);
    }
}

void destroy_ui3(void)
{
    text_t *txt_curr = game.ui.texts;
    text_t *txt_temp = NULL;

    while (txt_curr != NULL) {
        txt_temp = txt_curr;
        txt_curr = txt_curr->next;
        destroy_txt(txt_temp);
    }
    txt_curr = game.backpack.slot_txt;
    while (txt_curr != NULL) {
        txt_temp = txt_curr;
        txt_curr = txt_curr->next;
        destroy_txt(txt_temp);
    }
    sfFont_destroy(game.ui.font[0]);
    destroy_sounds();
}
