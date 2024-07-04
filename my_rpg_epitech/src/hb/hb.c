/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <SFML/Window/Event.h>

void print_dialogues(void)
{
    if (game.ui.dialogue->is_vis == 1) {
        game.ui.dialogue->is_vis = 1;
        sfRenderWindow_drawText(game.w, game.ui.dialogue->t, NULL);
    }
    if (game.dialogueline == 0)
        game.ui.dialogue->is_vis = 0;
}

void hb_event(sfEvent event)
{
    game.e = event;
    if (event.type == sfEvtMouseMoved)
        event_mouse_moved(event);
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft)
        event_mouse_click(event);
    if (event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseLeft)
        event_mouse_up(event);
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseRight)
        event_mouse_rclick(event);
    if (event.type == sfEvtKeyPressed)
        event_key_pressed(event);
    btns_hover();
}

void hb_movement(void)
{
    float time = sfTime_asSeconds(
        sfClock_getElapsedTime(game.clks.movement_clock));

    if (game.main != 0)
        return;
    if (time >= game.chars.plr->speed) {
        if (sfKeyboard_isKeyPressed(sfKeyW))
            step(3);
        if (sfKeyboard_isKeyPressed(sfKeyA))
            step(1);
        if (sfKeyboard_isKeyPressed(sfKeyS))
            step(0);
        if (sfKeyboard_isKeyPressed(sfKeyD))
            step(2);
    }
}

void combat(void)
{
    sfTime elapsed;
    float seconds;

    if (game.turn == 1 && game.in_combat == 1) {
        if (game.clks.combat_clock == NULL) {
            game.clks.combat_clock = sfClock_create();
        }
        elapsed = sfClock_getElapsedTime(game.clks.combat_clock);
        seconds = sfTime_asSeconds(elapsed);
        if (seconds >= 1) {
            enemy_damage();
            sfClock_restart(game.clks.combat_clock);
        }
    }
}

void hb_main()
{
    sfEvent event;
    sfClock *lerp = sfClock_create();

    while (sfRenderWindow_pollEvent(game.w, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game.w);
        hb_event(event);
    }
    sfRenderWindow_clear(game.w, sfColor_fromRGB(24, 20, 37));
    if (game.map != NULL) {
        hb_movement();
        animate_player(lerp);
        move_player(lerp);
        combat();
        draw_sprites(-game.chars.plr->off_pos_x, -game.chars.plr->off_pos_y);
        sfRenderWindow_drawSprite(game.w, game.chars.plr->s, NULL);
    }
    hb_ui_elements();
    print_dialogues();
    sfRenderWindow_display(game.w);
}
