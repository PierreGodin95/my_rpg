/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** combat_menu
*/

#include "../../h/main.h"

void set_bars(char *name, int len)
{
    btn_t *curr = game.ui.btns;
    int found = 0;

    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0)
            sfSprite_setScale(curr->s, (sfVector2f){(float)len, 1.0f});
        curr = curr->next;
    }
}

static void health(void)
{
    btn_t *btn;

    btn = btn_create("enemyhealth", "r/UI/_pref/slide_fill", 0, 1);
    btn_origin(btn, 1.0f, 0.5f);
    btn_pos(btn, (v_size_t){0.5f, 0.5f,
    game.pref.x / 4 + 360, game.pref.y / 3 + 50});
    btn = btn_create("playerhealth", "r/UI/_pref/slide_fill", 0, 1);
    btn_origin(btn, 0.0f, 0.5f);
    btn_pos(btn, (v_size_t){0.0f, 0.5f, 125, game.pref.y / 3 + 50});
}

static void combat_menu_load2(void)
{
    btn_t *btn;

    btn = btn_create("combat_ui", "r/UI/_comb/def", 0, 1);
    btn_origin(btn, 1.5f, 0.5f);
    btn_pos(btn, (v_size_t){0.5f, 0.5f,
    game.pref.x / 4 + 140, game.pref.y / 3 - 91});
    btn->callback = defend;
    btn = btn_create("combat_ui", "r/UI/_comb/items", 0, 1);
    btn_origin(btn, 1.5f, 0.5f);
    btn_pos(btn, (v_size_t){0.5f, 0.5f,
    game.pref.x / 4 + 140, game.pref.y / 3});
    btn->callback = backpack_show_btn;
    btn = btn_create("combat_ui", "r/UI/_comb/hp_foe", 0, 1);
    btn_origin(btn, 0.0f, 0.5f);
    btn_pos(btn, (v_size_t){0.5f, 0.5f,
    game.pref.x / 4, game.pref.y / 3});
    btn = btn_create("combat_ui", "r/UI/_comb/hp_plr", 0, 1);
    btn_origin(btn, 0.0f, 0.5f);
    btn_pos(btn, (v_size_t){0.0f, 0.5f, 40, game.pref.y / 3});
    health();
}

void combat_menu_load(void)
{
    btn_t *btn;

    btn = btn_create("combat_ui", "r/UI/_menu/title", 0, 1);
    btn = btn_create("combat_ui", "r/UI/_comb/prim", 0, 1);
    btn_origin(btn, 2.5f, 0.5f);
    btn_pos(btn, (v_size_t){0.5f, 0.5f,
    game.pref.x / 4 - 25, game.pref.y / 3 - 91});
    btn->callback = damage_enemy_primary;
    btn = btn_create("combat_ui", "r/UI/_comb/sec", 0, 1);
    btn_origin(btn, 2.5f, 0.5f);
    btn_pos(btn, (v_size_t){0.5f, 0.5f,
    game.pref.x / 4 - 25, game.pref.y / 3});
    btn->callback = damage_enemy_secondary;
    combat_menu_load2();
}

void show_combat_ui(int show)
{
    assign_bars();
    btn_set_vis("combat_ui", show, 1);
    btn_set_vis("enemyhealth", show, 1);
    btn_set_vis("playerhealth", show, 1);
}

void assign_bars(void)
{
    btn_t *btn;
    int enemy = (int)((float)game.enemy.health /
    (float)game.enemy.maxhealth * 200);
    int player = (int)((float)game.chars.plr->hp /
    (float)game.chars.plr->max_hp * 200);

    set_bars("enemyhealth", enemy);
    set_bars("playerhealth", player);
}
