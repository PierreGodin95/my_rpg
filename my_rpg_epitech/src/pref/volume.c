/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

float pref_slider_val(float min, float max, float v)
{
    float ret;

    max -= min;
    ret = min + (v / 275.0) * max;
    return ret;
}

void update_sfx(void)
{
    sound_t *curr = game.ui.sound;

    while (curr != NULL) {
        if (strcmp(curr->name, "main_menu") == 0) {
            sfSound_setVolume(curr->s, game.pref.bgm);
            break;
        }
        curr = curr->next;
    }
}

void pref_slider_handler(float v, char i)
{
    if (i == '1')
        game.pref.bgs = pref_slider_val(0.0, 100.0, v);
    if (i == '2')
        game.pref.sfx = pref_slider_val(0.0, 100.0, v);
    if (i == '3')
        game.pref.bgm = pref_slider_val(0.0, 100.0, v);
    if (i == '4')
        game.pref.fps = pref_slider_val(30.0, 120.0, v);
    if (i == '5')
        game.pref.text = pref_slider_val(0.5, 2.5, v);
    update_sfx();
}

void pref_slider_move(btn_t *btn, char i)
{
    sfVector2f mousePos = {game.e.mouseButton.x, game.e.mouseButton.y};
    sfVector2f sliderBarPos = sfSprite_getPosition(btn->s);
    float value = mousePos.x - sliderBarPos.x;

    if (value < 0.0)
        value = 0.0;
    else if (value > 275.0)
        value = 275.0;
    btn_scale(btn, value, 1.0);
    pref_slider_handler(value, i);
}

void pref_upt_slider(btn_t *hitbox)
{
    char last = hitbox->name[strlen(hitbox->name) - 1];
    btn_t *curr = game.ui.btns;

    while (curr != NULL) {
        if (curr->name[strlen(hitbox->name) - 1] == last)
            return pref_slider_move(curr, last);
        curr = curr->next;
    }
}
