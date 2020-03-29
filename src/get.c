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

int cases(tetris_t *tetris, char **av, int index)
{
    int o = 0;
    if (cases2(tetris, av, index) == 0)
        return 1;
    if (av[index + 1] != NULL) {
        for(o = 0; av[index + 1][o]; o++);
        if (o != 1)
            return 84;
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
        if (av[index][1] == 'L')
            tetris->level = my_strdup(av[index + 1]);
    } else {
        return 84;
    }
    return 2;
}

int cases2(tetris_t *tetris, char **av, int index)
{
    if (av[index][1] == 'w' || my_strncmp(av[index], "--without-next", 14) == 0) {
        tetris->next = my_strdup("No");
        return 0;
    }
    if (my_strncmp(av[index], "--map-size=", 11) == 0) {
        set_map_size(tetris, av[index]);
        return 0;
    }
    if (my_strncmp(av[index], "--level=", 8) == 0) {
        set_level(tetris, av[index]);
        return 0;
    }
    if (av[index][1] == 'D' || my_strncmp(av[index], "--debug", 7) == 0) {
        return 0;
    }
    return 1;
}