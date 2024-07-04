/*
** EPITECH PROJECT, 2024
** B-MUL-200-BAR-2-1-myrpg-aleix.ruiz-barba
** File description:
** playermovement
*/

#include "../../h/main.h"

static void get_enemy(char path)
{
    char filepath[256];
    FILE *file = NULL;

    sprintf(filepath, "src/character/enemy/enemy_%c", path);
    file = fopen(filepath, "r");
    if (file == NULL)
        return;
    if (fscanf(file, "%d", &game.enemy.health) != 1) {
        fclose(file);
        return;
    }
    if (fscanf(file, "%d", &game.enemy.damage) != 1) {
        fclose(file);
        return;
    }
    game.enemy.maxhealth = game.enemy.health;
    game.enemy.id = path;
    fclose(file);
}

static void defeat_enemy(char enemy)
{
    defeated_enemies_t *def_enemy =
    (defeated_enemies_t *)malloc(sizeof(defeated_enemies_t));
    defeated_enemies_t *temp = NULL;

    def_enemy->enemy = enemy;
    def_enemy->next = NULL;
    if (game.defeated_enemies == NULL) {
        game.defeated_enemies = def_enemy;
    } else {
        temp = game.defeated_enemies;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = def_enemy;
    }
}

static void level_up(void)
{
    if (game.chars.exp >= 100) {
        game.chars.exp = 0;
        game.chars.level += 1;
        game.chars.damage += 0.05;
        game.chars.defence += 0.025;
        game.chars.speed += 0.01;
    }
}

void damage_enemy_secondary(btn_t *btn)
{
    if (game.turn != 0 || game.in_combat == 0)
        return;
    if (game.clks.combat_clock != NULL)
        sfClock_restart(game.clks.combat_clock);
    game.enemy.health -= (10 * game.chars.damage);
    game.turn = 1;
    assign_bars();
    if (game.enemy.health <= 0) {
        defeat_enemy(game.enemy.id);
        game.in_combat = 0;
        game.turn = 0;
        game.spawn = game.enemy.id;
        show_combat_ui(0);
        game.chars.exp += game.enemy.maxhealth;
        level_up();
        read_map(game.currmap, 1);
    }
}

void damage_enemy_primary(btn_t *btn)
{
    if (game.turn != 0 || game.in_combat == 0)
        return;
    if (game.clks.combat_clock != NULL)
        sfClock_restart(game.clks.combat_clock);
    game.enemy.health -= (25 * game.chars.damage);
    game.turn = 1;
    assign_bars();
    if (game.enemy.health <= 0) {
        defeat_enemy(game.enemy.id);
        game.in_combat = 0;
        game.turn = 0;
        game.spawn = game.enemy.id;
        show_combat_ui(0);
        read_map(game.currmap, 1);
    }
}

void defend(btn_t *btn)
{
    game.is_defending = 1;
    game.turn = 1;
}

void enemy_damage(void)
{
    if (game.is_defending) {
        game.chars.plr->hp -= (game.enemy.damage * game.chars.defence);
        game.is_defending = 0;
    } else
        game.chars.plr->hp -= (game.enemy.damage);
    game.turn = 0;
    if (game.chars.plr->hp <= 0)
        sfRenderWindow_close(game.w);
    assign_bars();
}

void check_combat(void)
{
    if (game.map[(int)((game.chars.plr->off_pos_y) / 150)]
    [(int)(game.chars.plr->off_pos_x / 150)] >= 'a' &&
    game.map[(int)((game.chars.plr->off_pos_y) / 150)]
    [(int)(game.chars.plr->off_pos_x / 150)] <= 'z') {
        if (!is_defeated(game.map[(int)((game.chars.plr->off_pos_y) / 150)]
        [(int)(game.chars.plr->off_pos_x / 150)])) {
            game.in_combat = 1;
            game.turn = 0;
            get_enemy(game.map[(int)((game.chars.plr->off_pos_y) / 150)]
            [(int)(game.chars.plr->off_pos_x / 150)]);
            show_combat_ui(1);
        }
    }
}
