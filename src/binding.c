/*
** EPITECH PROJECT, 2020
** biding.c
** File description:
** binding source file
*/

#include "../include/tetris.h"

void set_key_pause(tetris_t *tetris, char *buffer)
{
    char *key = malloc(sizeof(char) * 10);
    key = my_strncpy2(key, buffer, 12);
    tetris->key_pause = my_strdup(key);
}

void set_level(tetris_t *tetris, char *buffer)
{
    char *lev = malloc(sizeof(char) * 4);
    lev = my_strncpy(lev, buffer, 8);
    tetris->level = my_strdup(lev);
}

void set_map_size(tetris_t *tetris, char *buffer)
{
    char *x = malloc(sizeof(char) * 4 + 1);
    char *y = malloc(sizeof(char) * 4 + 1);
    x = my_strcpy(x, buffer);
    y = my_strcpy2(y, buffer);
    tetris->size_x = my_getnbr(y);
    tetris->size_y = my_getnbr(x);
}

int bind_key(tetris_t *tetris, char **av, int index)
{
    int condition = 0;
    condition = cases(tetris, av, index);
    if (condition == 1)
        return 1;
    if (condition == 2)
        return 0;
    if (condition == 84)
        return 84;
    return 666;
}

int binding_key(tetris_t *tetris, int ac, char **av)
{
    int index = 1;
    int condition = 0;
    while (index < ac) {
        if (av[index][0] == '-') {
            condition = bind_key(tetris, av, index);
            if (condition == 0)
                index += 2;
            if (condition == 1)
                index += 1;
            if (condition == 84)
                return 84;
        }
    }
    return (0);
}