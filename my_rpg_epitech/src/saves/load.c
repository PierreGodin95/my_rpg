/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/

#include "../../h/main.h"

void load_save(char **array)
{
    char_t character = {0};
    game_t game_data = {0};
    item_t item = {0};

    for (int i = 0; array[i] != NULL; i++) {
        replace_stats(array, &character, &game_data, i);
        replace_inv(array, &item, i);
    }
}

char **read_file_to_array(const char *file_path)
{
    FILE *file = fopen(file_path, "r");
    char **lines = (char **)malloc(MAX_LINES * sizeof(char *));
    char buffer[MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL
    && line_count < MAX_LINES) {
        lines[line_count] = strdup(buffer);
        line_count++;
    }
    fclose(file);
    lines[line_count] = NULL;
    return lines;
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

int load_main(void)
{
    const char *file_path = "Saves/save_1";
    char **file_to_array = read_file_to_array(file_path);

    load_save(file_to_array);
    free_array(file_to_array);
    ui_main_closeall(NULL);
    return 0;
}
