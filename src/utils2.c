/*
** EPITECH PROJECT, 2020
** utils2.c
** File description:
** utils2 source file
*/

#include "../include/tetris.h"

char *my_strdup(char const *src)
{
    char *str;
    int copy = 0;
    str = malloc(10000);
    while (src[copy] != '\0') {
        str[copy] = src[copy];
        copy++;
    }
    str[copy] = '\0';
    return (str);
}