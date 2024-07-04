/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <string.h>

void populate_ui_sounds(void)
{
    sound_t *curr = NULL;

    game.ui.sound = NULL;
    game.ui.btns = NULL;
    game.ui.texts = NULL;
    add_ui_sound("r/s/gen/btn_hov.wav", "btn_hov");
    curr = add_ui_sound("r/BGM/menu.ogg", "main_menu");
    sfSound_play(curr->s);
    sfSound_setLoop(curr->s, sfTrue);
}

void populate_innit(void)
{
    game.ui.font[0] = sfFont_createFromFile("r/UI/retro_font.ttf");
    populate_ui_sounds();
    saves_innit();
}
