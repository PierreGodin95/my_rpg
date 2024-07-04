/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

void index_loop_2(btn_t *temp, btn_t *cur, btn_t *prev)
{
    if (prev != NULL) {
        prev->next = cur->next;
    } else {
        temp = cur->next;
    }
}

void index_loop(btn_t *cur, btn_t *prev, btn_t *temp, int *swapped)
{
    btn_t *nextNode = NULL;

    while (cur->next != NULL) {
        if (cur->index > cur->next->index) {
            index_loop_2(temp, cur, prev);
            nextNode = cur->next->next;
            cur->next->next = cur;
            cur->next = nextNode;
            prev = cur->next;
            *swapped = 1;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

void z_index_sort(void)
{
    btn_t *temp = game.ui.btns;
    btn_t *prev = NULL;
    btn_t *cur = temp;
    int swapped;

    if (temp == NULL || temp->next == NULL)
        return;
    do {
        swapped = 0;
        prev = NULL;
        cur = temp;
        index_loop(cur, prev, temp, &swapped);
    } while (swapped);
    game.ui.btns = temp;
}
