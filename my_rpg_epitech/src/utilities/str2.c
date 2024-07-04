/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

int m_strequ(const char *str1, const char *str2)
{
    while (*str1 != '\0' || *str2 != '\0') {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    return 1;
}

char *m_strdup(char *str)
{
    size_t len = m_strlen(str);
    char *new_str = (char *)malloc(len + 1);

    if (new_str == NULL)
        return NULL;
    m_strcpy(new_str, str);
    return new_str;
}
