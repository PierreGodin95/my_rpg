/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <SFML/Graphics/Types.h>

static void destroy_btn(btn_t *button)
{
    sfSprite_destroy(button->s);
    free(button->name);
    for (int i = 0; i < 3; i++) {
        if (button->t[i] != NULL)
            sfTexture_destroy(button->t[i]);
    }
    free(button);
}

static void destroy_sprite(sprite_t *sprite)
{
    sfSprite_destroy(sprite->s);
    sfTexture_destroy(sprite->t);
    free(sprite);
}

static void destroy_modal(modal_t *sprite)
{
    sfSprite_destroy(sprite->s);
    sfTexture_destroy(sprite->t);
    free(sprite);
}

static void destroy_game(void)
{
    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(game.saves[i].btn->t[0]);
        sfTexture_destroy(game.saves[i].btn->t[1]);
        sfSprite_destroy(game.saves[i].btn->s);
        sfText_destroy(game.saves[i].txt->t);
        free(game.saves[i].btn->name);
        free(game.saves[i].txt->name);
        free(game.saves[i].btn);
        free(game.saves[i].txt);
    }
}

void destroy_ui2(void)
{
    btn_t *btn_curr = game.ui.btns;
    btn_t *btn_curr2 = game.backpack.btn;
    btn_t *btn_temp = NULL;

    while (btn_curr != NULL) {
        btn_temp = btn_curr;
        btn_curr = btn_curr->next;
        destroy_btn(btn_temp);
    }
    while (btn_curr2 != NULL) {
        btn_temp = btn_curr2;
        btn_curr2 = btn_curr2->next;
        destroy_btn(btn_temp);
    }
    destroy_game();
    destroy_ui3();
}

void destroy_ui(void)
{
    sprite_t *sprite_curr = game.ui.sprites;
    sprite_t *sprite_temp = NULL;
    modal_t *modal_curr = game.ui.modals;
    modal_t *modal_temp = NULL;

    while (sprite_curr != NULL) {
        sprite_temp = sprite_curr;
        sprite_curr = sprite_curr->next;
        destroy_sprite(sprite_temp);
    }
    while (modal_curr != NULL) {
        modal_temp = modal_curr;
        modal_curr = modal_curr->next;
        destroy_modal(modal_temp);
    }
    destroy_ui2();
}
