/*
** EPITECH PROJECT, 2020
** debug.c
** File description:
** debug source file
*/

#include "../include/tetris.h"
#include <termios.h>

void print_tetriminos(tetris_t *tetris, int index)
{
    int fd;
    char *tetri;
    struct stat off_t;
    fd = open(tetris->paths[index], O_RDONLY); 
    stat(tetris->paths[index], &off_t);
    tetri = malloc(sizeof(char) * (off_t.st_size + 1));
    read(fd, tetri, off_t.st_size);
    get_spec(tetris, tetri);
    if (error_handling(tetri) == 84) {
        my_printf("Tetriminos : Name %s : Error\n", tetris->name);
    } else {
        my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n",
        tetris->name, tetris->weight, tetris->height, tetris->color);
        display_tetri(tetri);
    }
}

void print_debug(tetris_t *tetris)
{
    struct dirent *lecture;
    DIR *dir;
    int line = 0;
    char *test = "tetriminos/";
    dir = opendir(test);
    while ((lecture = readdir(dir))) {
        if (lecture->d_type == DT_REG) {
            tetris->paths[line] = my_strdup("tetriminos/");
            tetris->paths[line] = my_strcat2(tetris->paths[line], lecture->d_name);
            line++;
        }
    }
    sort_by_alpha(tetris->paths, line);
    for (int index = 0; index < tetris->number; index++) {
        get_name(tetris, index);
        print_tetriminos(tetris, index);
    }
}

void disp_keys(tetris_t *tetris)
{
    my_printf("Key Left :  %s\n", tetris->key_left);
    my_printf("Key Right :  %s\n", tetris->key_right);
    my_printf("Key Turn :  %s\n", tetris->key_turn);
    my_printf("Key Drop :  %s\n", tetris->key_drop);
    my_printf("Key Quit :  %s\n", tetris->key_quit);
    my_printf("Key Pause :  %s\n", tetris->key_pause);
    my_printf("Next :  %s\n", tetris->next);
    my_printf("Level :  %s\n", tetris->level);
    my_printf("Size :  %d*%d\n", tetris->size_y, tetris->size_x);
    my_printf("Tetriminos : %d\n", tetris->number);
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

void change_term(int a)
{
    static struct termios old;
    static struct termios nw;

    if (a == 0)
    {
        ioctl(0, TCGETS, &old);
        ioctl(0, TCGETS, &nw);
        nw.c_lflag &= ~ECHO;
        nw.c_lflag &= ~ICANON;
        nw.c_cc[VMIN] = 1;
        nw.c_cc[VTIME] = 0;
        ioctl(0, TCSETS, &nw);
    }
    else if (a == 1)
    {
        nw.c_cc[VMIN] = 0;
        nw.c_cc[VTIME] = 0;
        ioctl(0, TCSETS, &nw);
    }
    else
    ioctl(0, TCSETS, &old);
}

int debug(tetris_t *tetris, int ac, char **av)
{
    change_term(0);
    init_tetris(tetris);
    if (binding_key(tetris, ac, av) == 84)
        return 84;
    my_printf("*** DEBUG MODE ***\n");
    disp_keys(tetris);
    print_debug(tetris);
    my_printf("Press any key to start Tetris");
    getchar();
    change_term(2);
    create_map(tetris);
    return 0;
}