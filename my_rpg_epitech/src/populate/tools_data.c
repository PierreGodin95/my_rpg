/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <string.h>

void tool_populate_data2(item_t temp)
{
    temp.name = strdup("Glock 17");
    temp.texture = strdup("r/Guns/G17.png");
    temp.off_x = 0;
    temp.off_y = 0;
    temp.max_count = 1;
    temp.type = 1;
    temp.burst = 3;
    temp.dmg = 3;
    temp.ammo_type = 0;
    temp.accuracy = 70;
}

void tool_populate_data(void)
{
    item_t temp = game.backpack.data.M4A1;

    temp.name = strdup("M4A1");
    temp.texture = strdup("r/Guns/M4A1.png");
    temp.off_x = 0;
    temp.off_y = 0;
    temp.max_count = 1;
    temp.type = 1;
    temp.burst = 3;
    temp.dmg = 3;
    temp.ammo_type = 0;
    temp.accuracy = 70;
    temp = game.backpack.data.M4A1;
    tool_populate_data2(temp);
}
