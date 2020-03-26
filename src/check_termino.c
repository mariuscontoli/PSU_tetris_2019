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

void get_name(tetris_t *tetris)
{
    char *temp = malloc(sizeof(char) * 20);
    int i = 0;
    int j = 11;
    for (; tetris->nome[j] != '.'; j++) {
        temp[i] = tetris->nome[j];
        i++;
    }
    temp[i] = '\0';
    tetris->name = temp; 
}

void assign_keys(tetris_t *tetris)
{
    my_printf("Key Left :  ^EOD\n");
    my_printf("Key Right :  ^EOC\n");
    my_printf("Key Turn :  (space)\n");
    my_printf("Key Drop :  x\n");
    my_printf("Key Quit :  q\n");
    my_printf("Key Pause :  p\n");
    my_printf("Next :  Yes\n");
    my_printf("Level :  1\n");
    my_printf("Size :  20*10\n");
}

void print_tetriminos(tetris_t *tetris, node_t *temp)
{
    int fd;
    char *tetri;
    struct stat off_t;
    if ((fd = open(tetris->nome, O_RDONLY)) < 0)
        return NULL;
    stat(tetris->nome, &off_t);
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

void print_debug(tetris_t *tetris)
{
    struct dirent *lecture;
    DIR *dir;
    struct stat st;
    head_t *l_b = NULL;
    char *test = "tetriminos/";
    dir = opendir(test);
    while ((lecture = readdir(dir))) {
        if (lecture->d_name[0] != '.')
            l_b = get_n_node(my_strcpy(lecture->d_name), l_b); }
    node_t *temp = l_b->begin;
    while (temp != NULL) {
        char* tempo = malloc(sizeof(char) * 1000);
        my_strcpy2(tempo, test);
        my_strcat2(tempo, temp->data);
        tetris->nome = tempo;
        temp->data = tempo;
        get_name(tetris);
        print_tetriminos(tetris, temp);
        temp = temp->next;
    }
}

void debug(tetris_t *tetris, int ac, char **av)
{
    my_printf("*** DEBUG MODE ***\n");
    assign_keys(tetris);
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