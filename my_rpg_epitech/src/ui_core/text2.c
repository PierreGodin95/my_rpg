/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

int text_set_text(char *name, char *text, int group)
{
    text_t *curr = game.ui.texts;
    int found = 0;

    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            sfText_setString(curr->t, text);
            found++;
        }
        if (group == 0 && found == 1)
            return 1;
        curr = curr->next;
    }
    return found;
}
