/*
** EPITECH PROJECT, 2023
** my_rpg main.c
** File description:
** <desc>
*/
#include "../../h/main.h"

int get_int_len(int num)
{
    int length = 0;

    while (num != 0) {
        num = num / 10;
        length++;
    }
    return length;
}

char *int_to_str(int num)
{
    int length = get_int_len(num);
    char *str = malloc((length + 1) * sizeof(char));

    str[length] = '\0';
    for (int i = length - 1; i >= 0; i--) {
        str[i] = (num % 10) + '0';
        num = num / 10;
    }
    return str;
}

int to_num(char const *str)
{
    int len = m_strlen(str);
    long long int ret = 0;
    int neg = 1;

    for (int i = 0; i < len; i++) {
        if (str[i] == '-')
            neg = -1;
        if (str[i] == '+')
            neg = 1;
        if (str[i] < '0' || str[i] > '9')
            return neg * ret;
        if (str[i] >= '0' && str[i] <= '9') {
            ret *= 10;
            ret += (str[i] - '0');
        }
        if (ret > 2147483647)
            return 0;
    }
    return (int)(neg * ret);
}
