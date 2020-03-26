/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utilitary fucntions source file
*/

#include "../include/tetris.h"

void display_help(char *string)
{
    printf("Usage: %s [options]\n", string);
    printf("Options:\n");
    printf("  --help                Display this help\n");
    printf("  -L --level={num}      Start Tetris at level num (def: 1)\n");
    printf("  -l --key-left={K}     Move the tetrimino LEFT using the K key (def: left arrow)\n");
    printf("  -r --key-right={K}    Move the tetrimino RIGHT using the K key (def: right arrow)\n");
    printf("  -t --key-turn={K}     TURN the tetrimino clockwise 90d using the K key (def: top arrow)\n");
    printf("  -d --key-drop={K}     DROP the tetrimino using the K key (def: down arrow)\n");
    printf("  -q --key-quit={K}     QUIT the game using the K key (def: 'q' key)\n");
    printf("  -p --key-pause={K}    PAUSE the game using the K key (def: space bar)\n");
    printf("  --map-size={row, col} Set the numbers of rows and columns of the map (def: 20, 10)\n");
    printf("  -w --without-next     Hide next tetrimino (def: false)\n");
    printf("  -D --debug            Debug mode (def: false)\n");
}

int my_strlen(char const *str)
{
    int i;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_strlen2(char const *str)
{
    int i;
    while (str[i] != '.') {
        i++;
    }
    return i;
}

int my_atoi(char c)
{
    int number;
    number = c - 48;
    return number;
}

char *my_strnto_name(char *dest)
{
    int len_new = my_strlen2(dest);
    char *new = malloc(sizeof(char) * len_new + 1);

    for (int copy = 0; dest[copy] != '.'; copy++) {
        if (copy < len_new) {
            new[copy] = dest[copy];
        }
    }
    return new;
}

int my_getnbr(char *str)
{
    int i = 0;
    int sign = 1;
    int	tmp = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; ++i) {
        tmp = tmp * 10 + str[i] - '0';
    }
    return (tmp * sign);
}

char *my_strcat(char *dest, const char *src)
{
    char *ret = dest;
    while (*dest) {
        dest++;
    }
    while (*dest++ = *src++)
        ;
    return ret;
}

char *my_strdup(char const *src)
{
    char *str;
    int copy = 0;
    str = malloc(10000);
    while (src[copy] != '\0') {
        str[copy] = src[copy];
        copy++;
    }
    str[copy] = '\0';
    return (str);
}