/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

int m_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *m_strcpy(char *dest, const char *src)
{
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return dest;
}

char *m_strcat(char *dest, char const *src)
{
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return dest;
}

int m_strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' || *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return 0;
}

char *m_strrchr(const char *str, int ch)
{
    const char *last_occurrence = NULL;

    while (*str != '\0') {
        if (*str == ch) {
            last_occurrence = str;
        }
        str++;
    }
    return (char *)last_occurrence;
}
