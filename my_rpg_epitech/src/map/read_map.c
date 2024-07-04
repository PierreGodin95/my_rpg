/*
** EPITECH PROJECT, 2023
** B-MUL-200-BAR-2-1-myrpg-aleix.ruiz-barba
** File description:
** read_map.c
*/

#include "../../h/main.h"

tile_t *create_tile(const char *filepath, int x, int y)
{
    tile_t *new_tile = malloc(sizeof(tile_t));
    sfVector2u textureSize = {0, 0};
    sfVector2f scale = {0, 0};

    new_tile->texture = sfTexture_createFromFile(filepath, NULL);
    new_tile->sprite = sfSprite_create();
    sfSprite_setTexture(new_tile->sprite, new_tile->texture, sfTrue);
    textureSize = sfTexture_getSize(new_tile->texture);
    scale = (sfVector2f){150.0f / textureSize.x, 150.0f / textureSize.y};
    sfSprite_setScale(new_tile->sprite, scale);
    new_tile->x = x;
    new_tile->y = y;
    new_tile->next = NULL;
    return new_tile;
}

tile_t *add_tile(tile_t *new_tile, tile_t *prev_tile, int i, int j)
{
    if (prev_tile == NULL) {
        game.spritemap.tiles = new_tile;
    } else {
        prev_tile->next = new_tile;
    }
    prev_tile = new_tile;
    return prev_tile;
}
