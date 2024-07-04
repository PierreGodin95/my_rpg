/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../h/main.h"
#include <string.h>
game_t game = {.scene = 0, .paused = 0, .elapsed_time = 0};

void render_window(void)
{
    sfVideoMode mode = {X, Y, BITS};
    sfImage* icon = sfImage_createFromFile("r/UI/icon.png");
    const sfUint8* pixels = sfImage_getPixelsPtr(icon);
    unsigned int width = sfImage_getSize(icon).x;
    unsigned int height = sfImage_getSize(icon).y;
    sfVector2i window_pos;

    window_pos.x = (sfVideoMode_getDesktopMode().width - mode.width) / 2;
    window_pos.y = (sfVideoMode_getDesktopMode().height - mode.height) / 2;
    game.pref.x = X;
    game.pref.y = Y;
    game.pref.fps = FPS;
    game.pref.win = WIN;
    game.w = sfRenderWindow_create(mode, "Final Guntasy",
    sfTitlebar | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game.w, FPS);
    sfRenderWindow_setPosition(game.w, window_pos);
    game.ui.ui_id = 0;
    sfRenderWindow_setIcon(game.w, width, height, pixels);
    sfImage_destroy(icon);
}

int main(int arg_c, char **arg_v)
{
    if (arg_c >= 2 && strcmp(arg_v[1], "-h") == 0) {
        printf("USAGE:\n./my_rpg\n");
        return 0;
    }
    render_window();
    populate_innit();
    ui_main_menu_load();
    game.spawn = '/';
    while (sfRenderWindow_isOpen(game.w))
        hb_main();
    destroy_all();
    return 0;
}
