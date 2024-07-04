/*
** EPITECH PROJECT, 2023
** B-MUL-200-BAR-2-1-myrpg-aleix.ruiz-barba
** File description:
** read_map.c
*/

#include "../../h/main.h"

void set_filepath(char *filepath, int i, int j)
{
    if (is_defeated(game.map[i][j])) {
        strcpy(filepath, "r/level/tile017.png");
    } else {
        sprintf(filepath, "r/mobs/mob%c.png", game.map[i][j]);
    }
}

static tile_t *get_tile(tile_t *prev_tile, tile_t *new_tile, int i, int j)
{
    int found = 0;
    char filepath[256];

    for (int k = 0; game.tilepath[k].character != '\0'; k++) {
        if (game.map[i][j] == game.tilepath[k].character) {
            new_tile = create_tile(game.tilepath[k].filepath, j *
            game.spritemap.tile_size, i * game.spritemap.tile_size);
            prev_tile = add_tile(new_tile, prev_tile, i, j);
            found = 1;
            break;
        }
    }
    if (!found && ((game.map[i][j] >= 'a' && game.map[i][j] <= 'z')
    || (game.map[i][j] >= 'A' && game.map[i][j] <= 'Z'))) {
        set_filepath(filepath, i, j);
        new_tile = create_tile(filepath, j *
        game.spritemap.tile_size, i * game.spritemap.tile_size);
        prev_tile = add_tile(new_tile, prev_tile, i, j);
    }
    return prev_tile;
}

static void add_sprites_to_map(void)
{
    tile_t *new_tile = NULL;
    tile_t *prev_tile = NULL;

    for (int i = 0; game.map[i] != NULL; i++) {
        for (int j = 0; game.map[i][j] != '\0'; j++) {
            prev_tile = get_tile(prev_tile, new_tile, i, j);
        }
    }
}

void draw_sprites(int offset_x, int offset_y)
{
    tile_t *current_tile = game.spritemap.tiles;
    sfVector2f position = {0, 0};
    sfVector2u window_size = sfRenderWindow_getSize(game.w);
    sfVector2f center = {window_size.x / 2, window_size.y / 2};

    while (current_tile != NULL) {
        position.x = current_tile->x + offset_x + center.x - 75;
        position.y = current_tile->y + offset_y + center.y / 1.5f;
        sfSprite_setPosition(current_tile->sprite, position);
        sfRenderWindow_drawSprite(game.w, current_tile->sprite, NULL);
        current_tile = current_tile->next;
    }
}

static void set_spritepaths(void)
{
    char_filepath_t char_filepath[] = {
        {' ', "r/level/tile017.png"},
        {'/', "r/level/tile017.png"},
        {'#', "r/level/tile001.png"},
        {'!', "r/level/tile016.png"},
        {'"', "r/level/tile000.png"},
        {'$', "r/level/tile025.png"},
        {'%', "r/level/tile003.png"},
        {'&', "r/level/tile065.png"},
        {'(', "r/level/tile064.png"},
        {')', "r/level/tile067.png"},
        {'*', "r/level/tile030.png"},
        {'+', "r/level/tile049.png"},
        {',', "r/level/tile021.png"},
        {'-', "r/level/tile019.png"},
        {'.', "r/level/tile014.png"},
        {'\0', NULL}
    };

    memcpy(game.tilepath, char_filepath, sizeof(char_filepath));
}

static void assign_values(FILE *file)
{
    set_spritepaths();
    game.map = malloc(sizeof(char *) * 100);
    game.spritemap.tile_size = 150;
    if (file == NULL)
        exit(84);
}

void destroy_map(void)
{
    tile_t *current_tile = game.spritemap.tiles;
    tile_t *temp = NULL;

    if (game.map == NULL) {
        return;
    }
    while (current_tile != NULL) {
        sfTexture_destroy(current_tile->texture);
        sfSprite_destroy(current_tile->sprite);
        temp = current_tile;
        current_tile = current_tile->next;
        free(temp);
    }
    free(game.map);
}

void set_map(FILE *file)
{
    ssize_t read;
    size_t len;
    char *line = NULL;
    int counter = 0;

    for (read = getline(&line, &len, file); read != -1;
        read = getline(&line, &len, file)) {
            if (line[read - 1] == '\n')
                line[read - 1] = '\0';
            game.map[counter] = strdup(line);
            counter++;
    }
    game.map[counter] = NULL;
    fclose(file);
    free(line);
}

void read_map(char path, int travel)
{
    char filepath[256];
    FILE *file = NULL;

    game.currmap = path;
    sprintf(filepath, "src/map/game_maps/map%c", path);
    file = fopen(filepath, "r");
    destroy_map();
    assign_values(file);
    set_map(file);
    add_sprites_to_map();
    if (game.chars.plr == NULL) {
        init_player();
    } else {
        get_spawn();
    }
    if (travel >= 1) {
        game.spawn = path;
    }
    toggle_main_menu(0);
}
