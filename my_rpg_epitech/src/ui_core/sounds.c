/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

void sound_loop(sound_t *curr)
{
    while (curr->next != NULL) {
        curr = curr->next;
    }
}

sound_t *add_ui_sound(char *s_path, char *name)
{
    sound_t *new_node = (sound_t *)malloc(sizeof(sound_t));
    sound_t *curr = NULL;

    if (new_node != NULL) {
        new_node->name = strdup(name);
        new_node->b = sfSoundBuffer_createFromFile(s_path);
        new_node->s = sfSound_create();
        sfSound_setBuffer(new_node->s, new_node->b);
        new_node->next = NULL;
        if (game.ui.sound == NULL) {
            game.ui.sound = new_node;
        } else {
            curr = game.ui.sound;
            sound_loop(curr);
            curr->next = new_node;
        }
    }
    return new_node;
}
