/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** player
*/

#include "../../h/main.h"

static void get_spawn_loop(int *x, int *y, char *row, int i)
{
    for (int j = 0; row[j] != '\0'; ++j) {
        if (row[j] == game.spawn) {
            *x = j;
            *y = i;
            break;
        }
    }
}

void get_spawn(void)
{
    int x = -1;
    int y = -1;
    char *row = NULL;
    sfVector2u window_size = sfRenderWindow_getSize(game.w);
    sfVector2f center = {window_size.x / 2, window_size.y / 2};

    for (int i = 0; game.map[i] != NULL; ++i) {
        row = game.map[i];
        get_spawn_loop(&x, &y, row, i);
        if (x != -1)
            break;
    }
    game.chars.plr->off_pos_x = x * 150;
    game.chars.plr->off_pos_y = y * 150;
    sfSprite_setPosition(game.chars.plr->s,
    (sfVector2f){center.x - 75, center.y / 1.5f});
}

static void set_stats(void)
{
    game.chars.plr->max_hp = 100;
    game.chars.damage = 1.0f;
    game.chars.defence = 0.5f;
    game.chars.speed = 0.25f;
    game.playerdamage = 10;
    game.chars.plr->hp = game.chars.plr->max_hp;
    game.chars.plr->speed = 0.25f;
}

void init_player(void)
{
    sfIntRect textureRect = {0, 0, 60, 60};
    sfVector2f scale = {2.5f, 2.5f};

    game.clks.movement_clock = sfClock_create();
    game.chars.plr = malloc(sizeof(char_t));
    set_stats();
    game.chars.plr->t =
    sfTexture_createFromFile("r/character/sheriff_sprite.png", NULL);
    game.chars.plr->s = sfSprite_create();
    sfSprite_setTexture(game.chars.plr->s, game.chars.plr->t, sfFalse);
    sfSprite_setTextureRect(game.chars.plr->s, textureRect);
    sfSprite_setScale(game.chars.plr->s, scale);
    game.chars.plr->off_pos_x = sfSprite_getPosition(game.chars.plr->s).x;
    game.chars.plr->off_pos_y = sfSprite_getPosition(game.chars.plr->s).y;
    get_spawn();
    combat_menu_load();
}

void animate_player(sfClock *animate)
{
    sfIntRect textureRect = {0, 60 * game.chars.plr->lastdir, 60, 60};
    float time = sfTime_asSeconds(
    sfClock_getElapsedTime(game.clks.movement_clock));

    if (game.chars.plr->is_moving) {
        if (time < game.chars.plr->speed / 2) {
            textureRect = (sfIntRect) {game.chars.plr->anim_state == 1
            ? 120 : 60, 60 * game.chars.plr->lastdir, 60, 60};
        } else
            textureRect = (sfIntRect){0, 60 * game.chars.plr->lastdir, 60, 60};
    }
    sfSprite_setTextureRect(game.chars.plr->s, textureRect);
}

void move_player(sfClock *lerp)
{
    sfVector2f currPos = sfSprite_getPosition(game.chars.plr->s);
    sfVector2f targetPos = {(float)(game.chars.plr->off_pos_x),
                            (float)(game.chars.plr->off_pos_y)};

    game.chars.plr->is_moving =
    currPos.x == targetPos.x && currPos.y == targetPos.y ? 0 : 1;
}
