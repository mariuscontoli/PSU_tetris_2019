/*
** EPITECH PROJECT, 2019
** sokaban window
** File description:
** The program willsses the space bar
*/

#include "../include/tetris.h"

char **display_map(char **map)
{
    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    noecho();
    change_term(1);
    cloc(map);
    endwin();
    return 0;
}

char **char_to_charr(char *file, int w, int nbtt)
{
    int i = 0, j = 0, z = 0;
    char **map = malloc(sizeof(char *) * (w + 1));
    for (z = 0; z < nbtt ; z++, j++) {
        if (file[z] == '\n') {
            map[i] = malloc(sizeof(char) * (j + 1));
            i++;
            j = 0;
        }
    }
    map[i] = malloc(sizeof(char) * (j + 1));
    for (int c = 0, i = 0, j = 0; c < z ; c++, j++) {
        if (file[c] == '\n') {
            map[i][j] = '\0';
            c++, i++, j = 0;
        }
        map[i][j] = file[c];
    }
    i++;
    map[i] = NULL;
    display_map(map);
}

char **create_map(tetris_t *tetris)
{
    int y = 0;
    int w = 1;
    struct stat sb;
    stat("map", &sb);
    int h = sb.st_size;
    char *file = malloc(sizeof(char) * (h + 1));
    int fd = open("map", O_RDONLY);
    if (fd == -1)
        exit (84);
    read(fd, file, h);
    file[h] = '\0';
    for (; file[y] != '\0'; y++) {
        if (file[y] == '\n')
            w++;
    }
    char_to_charr(file, w, y);
}