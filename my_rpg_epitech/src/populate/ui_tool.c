/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/

#include "../../h/main.h"

void text_to_slot(text_t *tmp)
{
    text_t *temp = game.backpack.slot_txt;

    if (temp == NULL) {
        game.backpack.slot_txt = tmp;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = tmp;
    }
}

static btn_t *set_tmp(btn_t *tmp, char *name, char *t_path, int vis)
{
    tmp->s = sfSprite_create();
    tmp->is_vis = vis;
    tmp->name = strdup(name);
    tmp->is_hov = 0;
    tmp->is_modal = 0;
    tmp->next = NULL;
    tmp->callback = NULL;
    return tmp;
}

btn_t *slot_create(char *name, char *t_path, int vis)
{
    btn_t *tmp = (btn_t *)malloc(sizeof(btn_t));
    btn_t *temp = NULL;

    tmp = set_tmp(tmp, name, t_path, vis);
    btn_new_texture(tmp, t_path, -1);
    btn_origin(tmp, .5, .5);
    if (game.backpack.btn == NULL) {
        game.backpack.btn = tmp;
    } else {
        temp = game.backpack.btn;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = tmp;
    }
    return tmp;
}

void populate_backpack_ui3(void)
{
    text_t *txt = txt_create("backpack_ui", 0, 20, "No item selected");

    text_pos(txt, (v_size_t){.5, .5, -205, 183});
    text_origin(txt, 0.5, 0.5);
    txt->is_modal = 1;
    text_to_slot(txt);
    ui_bp_populate();
}

void populate_backpack_ui2(btn_t *btn)
{
    btn = slot_create("backpack_ui_item", "r/Guns/G17", 0);
    btn_pos(btn, (v_size_t){.5, .5, 200, -165});
    btn->is_modal = 1;
    btn->data_id = 1;
    btn->callback = NULL;
    btn_size(btn, 270, 270);
    populate_backpack_ui3();
}

void populate_backpack_ui(void)
{
    btn_t *btn;

    btn = btn_create("backpack_ui", "r/UI/_pack/back", 0, 3);
    btn_pos(btn, (v_size_t){.5, .5, 0, -50});
    btn_origin(btn, .5, .5);
    btn->is_modal = 1;
    btn = btn_create("backpack_ui", "r/UI/close", 0, 3);
    btn_pos(btn, (v_size_t){.5, .5, 300, 332});
    btn_origin(btn, .5, .5);
    btn->is_modal = 1;
    btn->callback = ui_main_closeall;
    btn = slot_create("backpack_ui_item", "r/Guns/M4A1", 0);
    btn_pos(btn, (v_size_t){.5, .5, -200, -165});
    btn->is_modal = 1;
    btn->data_id = 0;
    btn->callback = NULL;
    btn_size(btn, 320, 320);
    populate_backpack_ui2(btn);
}
