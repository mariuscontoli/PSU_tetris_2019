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

int cases_keys(tetris_t *tetris, char **av, int index)
{
    if (my_strncmp(av[index], "--key-left=", 11) == 0) {
        set_key_left(tetris, av[index]);
        return 0;
    }
    if (my_strncmp(av[index], "--key-right=", 12) == 0) {
        set_key_right(tetris, av[index]);
        return 0;
    }
    if (my_strncmp(av[index], "--key-turn=", 11) == 0) {
        set_key_turn(tetris, av[index]);
        return 0;
    }
    if (my_strncmp(av[index], "--key-drop=", 11) == 0) {
        set_key_drop(tetris, av[index]);
        return 0;
    }
    if (my_strncmp(av[index], "--key-quit=", 11) == 0) {
        set_key_quit(tetris, av[index]);
        return 0;
    }
    return 1;
}

int cases2(tetris_t *tetris, char **av, int index)
{
    if (av[index][1] == 'w' || my_strncmp(av[index], "--without-next", 14)
        == 0) {
        tetris->next = my_strdup("No");
        return 0;
    }
    if (my_strncmp(av[index], "--map-size=", 11) == 0) {
        set_map_size(tetris, av[index]);
        return 0;
    }
    if (cases_keys(tetris, av, index) == 0 || cases_keys2(tetris, av,
        index) == 0) {
        return 0;
    }
    if (my_strncmp(av[index], "--level=", 8) == 0) {
        set_level(tetris, av[index]);
        return 0;
    }
    if (av[index][1] == 'D' || my_strncmp(av[index], "--debug", 7)
        == 0) {
        return 0;
    }
    return 1;
}