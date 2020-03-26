/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main source file
*/

#include "../include/tetris.h"

void display_tetri(char *buffer)
{
    int i, j = 0;
    for (i = 0; buffer[i] != '\n'; i++);
    for (j = i + 1; buffer[j] != '\0'; j++) {
        my_printf("%c", buffer[j]);
    }
}

char *my_strcat2(char *dest, char const *src)
{
    int a = 0;
    int b = 0;
    for (; dest[a] != '\0';)
        a++;
    while (src[b] != '\0') {
        dest[a + b] = src[b];
        b++;
    }
    dest[a + b] = '\0';
    return (dest);
}

void sort_by_alpha(char **paths, int line)
{
  for (int i = 0; i < line; i++) {
        for (int j = 0; j < line; j++) {
            if (paths[j][11] > paths[i][11]) {
                char *temp = paths[i];
                paths[i] = paths[j];
                paths[j] = temp;
            }
        }
    }
}

int how_many_tetri(void)
{
    DIR *dir;
    struct dirent *lecture;
    int i = 0;

    dir = opendir("tetriminos/");
    while ((lecture = readdir(dir)) != NULL) {
        if (lecture->d_type == DT_REG) {
            i++;
        }
    }
    return i;
}

int main(int ac, char *argv[])
{
    tetris_t *tetris = malloc(sizeof(*tetris));
    if (ac == 2 && argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2] == 'h') {
            display_help(argv[0]);
    } else if (ac > 1) {
        debug(tetris, ac, argv);
    }
    return (0);
}