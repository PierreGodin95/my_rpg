/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <SFML/Window/Keyboard.h>

void event_mouse_moved(sfEvent event)
{
    return;
}

void event_mouse_click(sfEvent event)
{
    btns_click();
}

void event_mouse_up(sfEvent event)
{
    btns_unclick();
}

void event_mouse_rclick(sfEvent event)
{
    return;
}

//COMBAT TESTING, WAITING FOR UI AND WEAPONS
void event_key_pressed(sfEvent event)
{
    if (event.key.code == sfKeyEscape) {
        game_pause_toggle(0);
    }
    if (event.key.code == sfKeyB) {
        backpack_show(1);
    }
    if (event.key.code == sfKeyE) {
        interactdialogue();
    }
    return;
}
