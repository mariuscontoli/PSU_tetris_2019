/*
** EPITECH PROJECT, 2020
** get.c
** File description:
** get source file
*/

#include "../include/tetris.h"

void get_spec(tetris_t *tetris, char *buffer)
{
    tetris->weight = my_atoi(buffer[0]);
    if (buffer[1] == ' ') {
        tetris->height = my_atoi(buffer[2]);
    }
    if (buffer[3] == ' ') {
        tetris->color = my_atoi(buffer[4]);
    }
}

void get_name(tetris_t *tetris, int index)
{
    char *temp = malloc(sizeof(char) * 20);
    int i = 0;
    int j = 11;
    for (; tetris->paths[index][j] != '.'; j++) {
        temp[i] = tetris->paths[index][j];
        i++;
    }
    temp[i] = '\0';
    tetris->name = temp; 
}

int error_handling(char *buffer)
{
    int i = 0;
    if (buffer[i] < 47 || buffer[i] > 57)
        return 84;
    if (buffer[i + 1] != ' ')
        return 84;
    if (buffer[i + 2] < 47 || buffer[i + 2] > 57)
        return 84;
    if (buffer[i + 3] != ' ')
        return 84;
    if (buffer[i + 4] < 47 || buffer[i + 4] > 57)
        return 84;
    for (int y = i + 5; buffer[y] != '\0'; y++) {
        if (buffer[y] != '*' && buffer[y] != ' ' && buffer[y] != '\n') {
            return 84;
        }
    }
    return 0;
}

int bind_key(tetris_t *tetris, char **av, int index)
{
    if (av[index][1] == 'd')
        tetris->key_drop = my_strdup(av[index + 1]);
    if (av[index][1] == 'r')
        tetris->key_right = my_strdup(av[index + 1]);
    if (av[index][1] == 'l')
        tetris->key_left = my_strdup(av[index + 1]);
    if (av[index][1] == 't')
        tetris->key_turn = my_strdup(av[index + 1]);
    if (av[index][1] == 'p')
        tetris->key_pause = my_strdup(av[index + 1]);
    return 0;
}

int binding_key(tetris_t *tetris, int ac, char **av)
{
    int index = 1;
    if (av[index][0 == '-'] && av[index][1] == 'D')
        index += 1;
    while (index < ac) {
        if (av[index][0 == '-'] && av[index][1] == 'D')
            index += 1;
        if (av[index][0] == '-') {
            bind_key(tetris, av, index);
            index += 2;
        }
    }
    return (0);
}