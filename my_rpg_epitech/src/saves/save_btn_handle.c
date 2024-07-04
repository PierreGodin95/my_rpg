/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

// LOAD the game from file number "i"
void saves_load_file(btn_t *btn)
{
    int save_id = btn->data_id;

    printf("Load file\n");
    load_main();
}

// SAVE the game to file number "i"
void saves_save_file(btn_t *btn)
{
    char_t *player = game.chars.plr;
    game_t game_data = {0};
    item_t item = {0};
    int save_id = btn->data_id;

    save_game_state(player, &game_data, &item, save_id);
}
