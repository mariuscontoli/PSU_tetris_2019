/*
** EPITECH PROJECT, 2020
** biding.c
** File description:
** binding source file
*/

#include "../include/tetris.h"

void set_map_size(tetris_t *tetris, char *buffer)
{
    char *x = malloc(sizeof(char) * 3);
    char *y = malloc(sizeof(char) * 3);
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