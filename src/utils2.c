/*
** EPITECH PROJECT, 2020
** utils2.c
** File description:
** utils2 source file
*/

#include "../include/tetris.h"

int my_strcmp(char const *s1, char const *s2)
{
    const char *c1 = s1;
    const char *c2 = s2;
    
    while (*c1 != '\0') {
        if (*c2 == '\0') {
            return 0;
        } else if (*c2 > *c1) {
            return 1;
        }
        else if (*c1 < *c2) {
            return -1;
        }
        c1++;
        c2++;
    }
    if (*c2 != '\0') {
        return -1;
    }
    return 0;
}

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