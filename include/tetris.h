/*
** EPITECH PROJECT, 2020
** tetris.h
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>
#include "../my_printf/include/my_printf.h"

typedef struct node_s
{
    char *data;
    struct node_s *next;
    struct node_s *prev;
} node_t;

typedef struct head_s
{
    int f_op;
    node_t *begin;
    node_t *end;
} head_t;

typedef struct tetris {
    char *nome;
    char *name;
    char **paths;
    int height;
    int weight;
    int color;
    int number;
    char *key_left;
    char *key_right;
    char *key_turn;
    char *key_drop;
    char *key_quit;
    char *key_pause;
    int level;
    char *next;
    int size_x;
    int size_y;
} tetris_t;

int my_getnbr(char *str);
char *my_strdup(char const *src);
int my_atoi(char c);
char *my_strnto_name(char *dest);
int my_strlen2(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int debug(tetris_t *tetris, int ac, char **av);
void init_tetris(tetris_t *tetris);
void disp_keys(tetris_t *tetris);
void print_debug(tetris_t *tetris);
void print_tetriminos(tetris_t *tetris, int index);
void get_name(tetris_t *tetris, int index);
void get_spec(tetris_t *tetris, char *buffer);
int how_many_tetri(void);
void sort_by_alpha(char **paths, int line);
char *my_strcat2(char *dest, char const *src);
void display_tetri(char *buffer);
void display_help(char *string);
int error_handling(char *buffer);
int binding_key(tetris_t *tetris, int ac, char **av);
int bind_key(tetris_t *tetris, char **av, int index);

#endif /* !NAVY_H_ */