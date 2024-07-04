/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

char *get_file_date(int i, char *date)
{
    char *ret = malloc(strlen("Save 01\n") + strlen(date) + 1);
    char num[4];

    strcpy(ret, "Save ");
    strcat(ret, int_to_str(i));
    strcat(ret, "\n");
    strcat(ret, date);
    return ret;
}

void open_save_file(int num, char *path)
{
    FILE *fp = fopen(path, "r");
    struct stat file_stat;

    if (fp == NULL) {
        sfText_setString(game.saves[num].txt->t, "Empty Save");
        game.saves[num].is_empty = 1;
        return;
    }
    game.saves[num].fp = fp;
    if (stat(path, &file_stat) == 0) {
        game.saves[num].lm = ctime(&file_stat.st_mtime);
    }
    game.saves[num].is_empty = 0;
    sfText_setString(game.saves[num].txt->t,
    get_file_date(num + 1, game.saves[num].lm));
}

void load_save_list(int is_load)
{
    open_save_file(0, "Saves/save_1");
    open_save_file(1, "Saves/save_2");
    open_save_file(2, "Saves/save_3");
    open_save_file(3, "Saves/save_4");
    if (is_load) {
        for (int i = 0; i < 4; i++) {
            game.saves[i].btn->data_id = i + 1;
            game.saves[i].btn->callback = saves_load_file;
        }
    } else {
        for (int i = 0; i < 4; i++) {
            game.saves[i].btn->data_id = i + 1;
            game.saves[i].btn->callback = saves_save_file;
        }
    }
}

void ui_main_saveprompt(btn_t *btn)
{
    btn_set_vis("ui_pause_screen", 0, 1);
    game.ui.ui_id = 0;
    load_save_list(0);
    btns_unhover();
    btn_set_vis("ui_load_back", 1, 0);
    btn_set_vis("ui_load_close", 1, 0);
    sfSleep(sfMilliseconds(10));
    for (int i = 0; i < 4; i++)
        game.saves[i].btn->is_vis = 1;
    game.ui.ui_id = 1;
}

void ui_main_saveload(btn_t *btn)
{
    btn_set_vis("ui_pause_screen", 0, 1);
    game.ui.ui_id = 0;
    load_save_list(1);
    btns_unhover();
    btn_set_vis("ui_load_back", 1, 0);
    btn_set_vis("ui_load_close", 1, 0);
    sfSleep(sfMilliseconds(10));
    for (int i = 0; i < 4; i++)
        game.saves[i].btn->is_vis = 1;
    game.ui.ui_id = 1;
}
