/*
** EPITECH PROJECT, 2024
** B-MUL-200-BAR-2-1-myrpg-aleix.ruiz-barba
** File description:
** replace
*/

#include "../../h/main.h"

void replace_stats(char **array, char_t *character, game_t *game_data, int i)
{
    if (strncmp(array[i], "hp=", 3) == 0)
        sscanf(array[i], "hp=%d", &character->hp);
    if (strncmp(array[i], "max_hp=", 7) == 0)
        sscanf(array[i], "max_hp=%d", &character->max_hp);
    if (strncmp(array[i], "speed=", 6) == 0)
        sscanf(array[i], "speed=%d", &character->speed);
    if (strncmp(array[i], "defence=", 8) == 0)
        sscanf(array[i], "defence=%d", &character->defence);
    if (strncmp(array[i], "scene=", 6) == 0)
        sscanf(array[i], "scene=%d", &game_data->scene);
}

void replace_inv(char **array, item_t *item, int i)
{
    if (strncmp(array[i], "weapon_1=", 9) == 0) {
        sscanf(array[i], "weapon_1=%d", &item->name);
        printf(array[i]);
    }
    if (strncmp(array[i], "weapon_2=", 9) == 0)
        sscanf(array[i], "weapon_2=%d", &item->name);
    if (strncmp(array[i], "backpack_1=", 11) == 0)
        sscanf(array[i], "backpack_1=%d", &item->name);
    if (strncmp(array[i], "backpack_2=", 11) == 0)
        sscanf(array[i], "backpack_2=%d", &item->name);
    if (strncmp(array[i], "backpack_3=", 11) == 0)
        sscanf(array[i], "backpack_3=%d", &item->name);
    if (strncmp(array[i], "backpack_4=", 11) == 0) {
        sscanf(array[i], "backpack_4=%d", &item->name);
        printf(array[i]);
    }
    if (strncmp(array[i], "backpack_5=", 11) == 0)
        sscanf(array[i], "backpack_5=%d", &item->name);
    if (strncmp(array[i], "backpack_6=", 11) == 0)
        sscanf(array[i], "backpack_6=%d", &item->name);
}
