/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"
#include <string.h>

/*
BUTTON TEXTURES

@ btn_t *btn
Button instance to modify

@ char *t_path
Texture file location

0 -> Default Texture (btn.png)
1 -> Hover Texture (btn_hov.png)
2 -> Selected Texture (btn_sel.png)

@ int type
-1 -> Modify all textures
0 -> Default Texture
1 -> Hover Texture
2 -> Selected Texture

*/
void texture_tmp(btn_t *btn, char *t_path, char *new_path)
{
    for (int i = 0; i < 3; i++)
        btn->t[i] = NULL;
    strcat(new_path, ".png");
    if (access(new_path, F_OK) == 0)
        btn->t[0] = sfTexture_createFromFile(new_path, NULL);
    strcpy(new_path, t_path);
    strcat(new_path, "_hov.png");
    if (access(new_path, F_OK) == 0)
        btn->t[1] = sfTexture_createFromFile(new_path, NULL);
    strcpy(new_path, t_path);
    strcat(new_path, "_sel.png");
    if (access(new_path, F_OK) == 0)
        btn->t[2] = sfTexture_createFromFile(new_path, NULL);
}

void btn_new_texture(btn_t *btn, char *t_path, int type)
{
    char *new_path = malloc(strlen(t_path) + 10);

    strcpy(new_path, t_path);
    if (type == -1) {
        texture_tmp(btn, t_path, new_path);
    } else {
        btn->t[type] = sfTexture_createFromFile(t_path, NULL);
    }
    sfSprite_setTexture(btn->s, btn->t[0], sfTrue);
    free(new_path);
}

void btn_destroy(btn_t *s)
{
    btn_t *prev = NULL;

    if (s == NULL)
        return;
    for (int i = 0; i < 3; i++)
        if (s->t[i] != NULL)
            sfTexture_destroy(s->t[i]);
    sfSprite_destroy(s->s);
    if (game.ui.btns == s) {
        game.ui.btns = game.ui.btns->next;
        free(s);
    } else {
        prev = game.ui.btns;
        while (prev != NULL && prev->next != s)
            prev = prev->next;
        if (prev != NULL) {
            prev->next = s->next;
            free(s);
        }
    }
}

int btn_set_vis(char *name, int is_vis, int group)
{
    btn_t *curr = game.ui.btns;
    int found = 0;

    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            curr->is_vis = is_vis;
            found++;
        }
        if (group == 0 && found == 1)
            return 1;
        curr = curr->next;
    }
    return found;
}

int btn_set_nvis(char *name, int is_vis)
{
    btn_t *curr = game.ui.btns;

    while (curr != NULL) {
        if (strncmp(curr->name, name, strlen(name)) == 0)
            curr->is_vis = is_vis;
        curr = curr->next;
    }
    return 1;
}
