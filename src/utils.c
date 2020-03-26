/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utilitary fucntions source file
*/

#include "../include/tetris.h"

int my_strlen(char const *str)
{
    int i;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_strlen2(char const *str)
{
    int i;
    while (str[i] != '.') {
        i++;
    }
    return i;
}

int my_atoi(char c)
{
    int number;
    number = c - 48;
    return number;
}

char *my_strnto_name(char *dest)
{
    int len_new = my_strlen2(dest);
    char *new = malloc(sizeof(char) * len_new + 1);

    for (int copy = 0; dest[copy] != '.'; copy++) {
        if (copy < len_new) {
            new[copy] = dest[copy];
        }
    }
    return new;
}

int my_getnbr(char *str)
{
    int i = 0;
    int sign = 1;
    int	tmp = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; ++i) {
        tmp = tmp * 10 + str[i] - '0';
    }
    return (tmp * sign);
}