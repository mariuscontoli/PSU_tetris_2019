/*
** EPITECH PROJECT, 2020
** set_key.c
** File description:
** set key source file
*/

#include "../include/tetris.h"

void set_key_quit(tetris_t *tetris, char *buffer)
{
    char *key = malloc(sizeof(char) * 10);
    key = my_strncpy2(key, buffer, 11);
    tetris->key_quit = my_strdup(key);
}

void set_key_drop(tetris_t *tetris, char *buffer)
{
    char *key = malloc(sizeof(char) * 10);
    key = my_strncpy2(key, buffer, 11);
    tetris->key_drop = my_strdup(key);
}

void set_key_turn(tetris_t *tetris, char *buffer)
{
    char *key = malloc(sizeof(char) * 10);
    key = my_strncpy2(key, buffer, 11);
    tetris->key_turn = my_strdup(key);
}

void set_key_right(tetris_t *tetris, char *buffer)
{
    char *key = malloc(sizeof(char) * 10);
    key = my_strncpy2(key, buffer, 12);
    tetris->key_right = my_strdup(key);
}

void set_key_left(tetris_t *tetris, char *buffer)
{
    char *key = malloc(sizeof(char) * 10);
    key = my_strncpy2(key, buffer, 11);
    tetris->key_left = my_strdup(key);
}