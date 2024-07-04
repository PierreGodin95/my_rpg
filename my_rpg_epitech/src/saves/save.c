/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/

#include "../../h/main.h"

void save_hotbar(item_t current[7], char lines[][20], FILE* file)
{
    item_t temp = game.backpack.data.M4A1;

    temp.name = strdup("M4A1");
    fprintf(file, "%s\n", "#hotbar");
    fprintf(file, "weapon_1=%s\n", temp.name);
    temp = game.backpack.data.G17;
    temp.name = strdup("Glock17");
    fprintf(file, "weapon_2=%s\n", temp.name);
}

void save_stats(char_t *character, char lines[][20], FILE* file)
{
    fprintf(file, "%s\n", "#stats");
    sprintf(lines[0], "hp=%d", game.chars.plr->hp);
    sprintf(lines[1], "speed=%.2f", game.chars.speed);
    sprintf(lines[2], "defence=%.2f", game.chars.defence);
    sprintf(lines[3], "player damage=%.2f", game.playerdamage);
    for (int i = 0; i < STATS_NBR; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
}

void save_game_state(char_t *character, game_t *game_data,
    item_t *current, int save_id)
{
    char id[20];
    char *save_file;
    FILE* file;
    char lines[5][20];

    sprintf(id, "%d", save_id);
    save_file = malloc(strlen("Saves/save_") + strlen(id) + 1);
    strcpy(save_file, "Saves/save_");
    strcat(save_file, id);
    file = fopen(save_file, "w");
    if (!file) {
        printf("Failed to open save file for writing.\n");
        return;
    }
    save_stats(character, lines, file);
    save_hotbar(current, lines, file);
    fclose(file);
    free(save_file);
}
