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