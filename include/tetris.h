/*
** EPITECH PROJECT, 2020
** tetris.h
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <curses.h>
#include <bits/types.h>
#include <sys/ioctl.h>

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
    char *level;
    char *next;
    int size_x;
    int size_y;
} tetris_t;

typedef struct	s_game
{
    int sec;
    int min;
} t_game;

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
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strcpy2(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strncpy2(char *dest, char const *src, int n);
int cases_keys(tetris_t *tetris, char **av, int index);
int cases2(tetris_t *tetris, char **av, int index);
int cases_keys2(tetris_t *tetris, char **av, int index);
void set_map_size(tetris_t *tetris, char *buffer);
void set_level(tetris_t *tetris, char *buffer);
void set_key_left(tetris_t *tetris, char *buffer);
void set_key_right(tetris_t *tetris, char *buffer);
void set_key_turn(tetris_t *tetris, char *buffer);
void set_key_drop(tetris_t *tetris, char *buffer);
void set_key_quit(tetris_t *tetris, char *buffer);
void set_key_pause(tetris_t *tetris, char *buffer);
void create_map(tetris_t *tetris);
void char_to_charr(char *file, int w, int nbtt);
int display_map(char **map);
void cloc(char **map);
void print_map(t_game *game);
void type(char **map, t_game *game, time_t *start);
int cases(tetris_t *tetris, char **av, int index);
void change_term(int i);
void getTime(t_game *game, time_t *start);

#endif /* !NAVY_H_ */