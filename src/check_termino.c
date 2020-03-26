/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main source file
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

void display_tetri(char *buffer)
{
    int i, j = 0;
    for (i = 0; buffer[i] != '\n'; i++);
    for (j = i + 1; buffer[j] != '\0'; j++) {
        my_printf("%c", buffer[j]);
    }
}

char *my_strcpy2(char *dest, char const *src)
{
    int i = 0;
    while (src[i]  != '\0') {
        dest[i] = src[i];
        i++;
            }
    dest[i] = '\0';
    return (dest);
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
char *my_strcpy(char const *src)
{
    char *dest = malloc(sizeof(char*) * (my_strlen(src) + 1));
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
        }
    dest[i] = '\0';
    return (dest);
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

void disp_keys(tetris_t *tetris)
{
    my_printf("Key Left :  %s\n", tetris->key_left);
    my_printf("Key Right :  %S\n", tetris->key_right);
    my_printf("Key Turn :  %s\n", tetris->key_turn);
    my_printf("Key Drop :  %s\n", tetris->key_drop);
    my_printf("Key Quit :  %s\n", tetris->key_quit);
    my_printf("Key Pause :  %s\n", tetris->key_pause);
    my_printf("Next :  %s\n", tetris->next);
    my_printf("Level :  %d\n", tetris->level);
    my_printf("Size :  %d*%d\n", tetris->size_y, tetris->size_x);
    my_printf("Tetriminos : %d\n", tetris->number);
}

void print_tetriminos(tetris_t *tetris, int index)
{
    int fd;
    char *tetri;
    struct stat off_t;
    if ((fd = open(tetris->paths[index], O_RDONLY)) < 0)
        return NULL;
    stat(tetris->paths[index], &off_t);
    tetri = malloc(sizeof(char) * (off_t.st_size + 1));
    read(fd, tetri, off_t.st_size);
    get_spec(tetris, tetri);
    if (tetri[0] <= 122 && tetri[0] >= 97) {
        my_printf("Tetriminos : Name %s : Error\n", tetris->name);
    } else {
        my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n", tetris->name, tetris->weight, tetris->height, tetris->color);
        display_tetri(tetri);
    }
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

void print_debug(tetris_t *tetris)
{
    struct dirent *lecture;
    DIR *dir;
    struct stat st;
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
    tetris->level = 1;
    tetris->number = how_many_tetri();
    tetris->paths = malloc(sizeof(char * ) * tetris->number + 1);
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

void debug(tetris_t *tetris, int ac, char **av)
{
    DIR *dir;
    struct dirent *lecture;
    char **names;
    init_tetris(tetris);
    my_printf("*** DEBUG MODE ***\n");
    disp_keys(tetris);
    print_debug(tetris);
    my_printf("Press any key to start Tetris\n");
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