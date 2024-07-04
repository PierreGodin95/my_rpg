/*
** EPITECH PROJECT, 2024
** B-MUL-200-BAR-2-1-myrpg-aleix.ruiz-barba
** File description:
** playermovement
*/

#include "../../h/main.h"

static sfVector2f get_direction(void)
{
    sfVector2f result = {0, 0};

    switch (game.chars.plr->lastdir) {
        case 0:
            result.y = 1;
            break;
        case 1:
            result.x = -1;
            break;
        case 2:
            result.x = 1;
            break;
        case 3:
            result.y = -1;
            break;
        default:
            break;
    }
    return result;
}

static void check_doors(void)
{
    if (game.map[(int)((game.chars.plr->off_pos_y) / 150)]
    [(int)(game.chars.plr->off_pos_x / 150)] >= '0' &&
    game.map[(int)((game.chars.plr->off_pos_y) / 150)]
    [(int)(game.chars.plr->off_pos_x / 150)] <= '9') {
        read_map(game.map[(int)((game.chars.plr->off_pos_y) / 150)]
        [(int)(game.chars.plr->off_pos_x / 150)], 1);
    }
}

static void move(void)
{
    if ((game.map[(int)((game.chars.plr->off_pos_y +
    (get_direction().y * 150)) / 150)]
                [(int)((game.chars.plr->off_pos_x +
                (get_direction().x * 150)) / 150)] < '!' ||
        game.map[(int)((game.chars.plr->off_pos_y +
        (get_direction().y * 150)) / 150)]
                [(int)((game.chars.plr->off_pos_x +
                (get_direction().x * 150)) / 150)] > '.') &&
        (game.map[(int)((game.chars.plr->off_pos_y +
        (get_direction().y * 150)) / 150)]
                [(int)((game.chars.plr->off_pos_x +
                (get_direction().x * 150)) / 150)] < 'A' ||
        game.map[(int)((game.chars.plr->off_pos_y +
        (get_direction().y * 150)) / 150)]
                [(int)((game.chars.plr->off_pos_x +
                (get_direction().x * 150)) / 150)] > 'Z')) {
        game.chars.plr->off_pos_y += (get_direction().y * 150);
        game.chars.plr->off_pos_x += (get_direction().x * 150);
    }
}

static void get_dialogue(char path, char **filepath, FILE **file)
{
    if (*file != NULL) {
        fclose(*file);
        *file = NULL;
    }
    if (path != game.dialogueid)
        game.dialogueline = 0;
    game.dialogueid = path;
    if (*file == NULL) {
        *filepath = malloc(256 * sizeof(char));
        sprintf(*filepath, "src/character/dialogs/dialog_%c", path);
        *file = fopen(*filepath, "r");
        if (*file == NULL)
            return;
    }
}

void read_dialogue_line(FILE *file, char *line, int *current_line)
{
    while (fgets(line, 256, file)) {
        if (*current_line == game.dialogueline) {
            write(1, line, strlen(line));
            sfText_setString(game.ui.dialogue->t, line);
            game.ui.dialogue->is_vis = 1;
            game.dialogueline++;
            break;
        }
        (*current_line)++;
    }
}

static void talk(char path)
{
    static FILE *file = NULL;
    static char line[256];
    char *filepath = NULL;
    int current_line = 0;

    get_dialogue(path, &filepath, &file);
    if (file) {
        read_dialogue_line(file, line, &current_line);
        if (feof(file)) {
            game.dialogueline = 0;
            fclose(file);
            file = NULL;
        }
    }
    free(filepath);
}

void interactdialogue(void)
{
    if (game.map[(int)((game.chars.plr->off_pos_y +
    (get_direction().y * 150)) / 150)]
                [(int)((game.chars.plr->off_pos_x +
                (get_direction().x * 150)) / 150)] >= 'A' &&
        game.map[(int)((game.chars.plr->off_pos_y +
        (get_direction().y * 150)) / 150)]
                [(int)((game.chars.plr->off_pos_x +
                (get_direction().x * 150)) / 150)] <= 'Z') {
        talk(game.map[(int)((game.chars.plr->off_pos_y +
        (get_direction().y * 150)) / 150)]
                [(int)((game.chars.plr->off_pos_x +
                (get_direction().x * 150)) / 150)]);
    }
}

void step(int lastdir)
{
    if (game.dialogueline != 0 || game.paused == 1 || game.in_combat == 1)
        return;
    sfClock_restart(game.clks.movement_clock);
    game.chars.plr->lastdir = lastdir;
    move();
    check_doors();
    check_combat();
    if (game.chars.plr->anim_state == 0) {
        game.chars.plr->anim_state = 1;
    } else {
        game.chars.plr->anim_state = 0;
    }
}
