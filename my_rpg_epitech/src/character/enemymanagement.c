/*
** EPITECH PROJECT, 2024
** B-MUL-200-BAR-2-1-myrpg-aleix.ruiz-barba
** File description:
** playermovement
*/

#include "../../h/main.h"

int is_defeated(char enemy)
{
    defeated_enemies_t *temp = game.defeated_enemies;

    while (temp != NULL) {
        if (temp->enemy == enemy)
            return 1;
        temp = temp->next;
    }
    return 0;
}
