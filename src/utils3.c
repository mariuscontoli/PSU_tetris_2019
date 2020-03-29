/*
** EPITECH PROJECT, 2020
** utils3.c
** File description:
** utils3 source file
*/

#include "../include/tetris.h"

char *my_strncpy2(char *dest, char const *src, int n)
{
    int copy, y = 0;
    copy = n;
    while(src[copy] != '\0') {
        dest[y] = src[copy];
        copy++;
        y++;
    }
    dest[y] = '\0';
    return dest;
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

int cases_keys2(tetris_t *tetris, char **av, int index)
{
    if (my_strncmp(av[index], "--key-pause=", 12) == 0) {
        set_key_pause(tetris, av[index]);
        return 0;
    }
    return 1;
}

void init_tetris(tetris_t *tetris)
{
    tetris->key_right = my_strdup("^EOC");
    tetris->key_left = my_strdup("^EOD");
    tetris->key_drop = my_strdup("^EOA");
    tetris->key_turn = my_strdup("^EOB");
    tetris->key_pause = my_strdup("p");
    tetris->key_quit = my_strdup("q");
    tetris->size_y = 20;
    tetris->size_x = 10;
    tetris->next = my_strdup("Yes");
    tetris->level = my_strdup("1");
    tetris->number = how_many_tetri();
    tetris->paths = malloc(sizeof(char * ) * tetris->number + 1);
}