/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/

#include "../../h/main.h"
#include <SFML/Graphics/Types.h>

void bp_update(void)
{
    char new_text[1000];

    snprintf(new_text, 1000,
        "Level: %d (EXP: %d)\nHealth boost: %d\n"
            "Damage boost: %.2f\nDefence boost: %.2f\n"
            "Luck boost: %.2f\nSpeed boost: %.2f",
            game.chars.level, game.chars.exp,
            game.chars.hp, game.chars.damage,
            game.chars.defence, game.chars.luck, game.chars.speed);
    text_set_text("bp_stats", new_text, 0);
    text_set_vis("bp_stats", 1, 0);
    return;
}
