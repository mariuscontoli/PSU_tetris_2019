/*
** EPITECH PROJECT, 2020
** utils2.c
** File description:
** utils2 source file
*/

#include "../include/tetris.h"

char *my_strcpy(char *dest, char const *src)
{
    int copy, i, y = 0;
    for(; src[i] != '='; i++);
    copy = i + 1;
    while(src[copy] != ',') {
        dest[y] = src[copy];
        copy++;
        y++;
    }
    dest[y] = '\0';
    return dest;
}

char *my_strcpy2(char *dest, char const *src)
{
    int copy, i, y = 0;
    for(; src[i] != ','; i++);
    copy = i + 1;
    while(src[copy] != '\0') {
        dest[y] = src[copy];
        copy++;
        y++;
    }
    dest[y] = '\0';
    return dest;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    const char *c1 = s1;
    const char *c2 = s2;
    
    while (*c1 != n) {
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