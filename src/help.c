/*
** EPITECH PROJECT, 2020
** help.c
** File description:
** help source file
*/

#include "../include/tetris.h"

void display_help(char *string)
{
    my_printf("Usage: %s [options]\n", string);
    my_printf("Options:\n");
    my_printf("  --help                Display this help\n");
    my_printf("  -L --level={num}      Start Tetris at level num (def: 1)\n");
    my_printf("  -l --key-left={K}     Move the tetrimino LEFT using the K "
    "key (def: left arrow)\n");
    my_printf("  -r --key-right={K}    Move the tetrimino RIGHT using the K "
    "key (def: right arrow)\n");
    my_printf("  -t --key-turn={K}     TURN the tetrimino clockwise 90d using "
    "the K key (def: top arrow)\n");
    my_printf("  -d --key-drop={K}     DROP the tetrimino using the K key "
    "(def: down arrow)\n");
    my_printf("  -q --key-quit={K}     QUIT the game using the K key (def: "
    "'q' key)\n");
    my_printf("  -p --key-pause={K}    PAUSE the game using the K key (def: "
    "space bar)\n");
    my_printf("  --map-size={row, col} Set the numbers of rows and columns of "
    "the map (def: 20, 10)\n");
    my_printf("  -w --without-next     Hide next tetrimino (def: false)\n");
    my_printf("  -D --debug            Debug mode (def: false)\n");
}