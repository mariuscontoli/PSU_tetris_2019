/*
** EPITECH PROJECT, 2019
** sokaban window
** File description:
** The program will ees the space bar
*/

#include "../include/tetris.h"

void cloc(char **map)
{
    t_game *game = malloc(sizeof(t_game));
    time_t *start = NULL;
    game->min = 0;
    game->sec = 0;
    int c = 0;
    for (int compt_move = 1; c != 27; compt_move++, game->sec++) {
        type(map, game, start);
        c = getch();
    }
}

void print_map(t_game *game)
{
    int s_x = 20, s_y = 20;
    int x_temp = 0, y_temp = 0;
    mvprintw(1, 37, "+");
    mvprintw(1, s_x + 36, "+");
    mvprintw(s_y, 37, "+");
    mvprintw(s_y, s_x + 36, "+");
    for(; x_temp < s_x - 2; x_temp++) {
        mvprintw(1, 38 + x_temp, "-");
        mvprintw(s_y, 38 + x_temp, "-");
    }
    for(; y_temp < s_y - 2; y_temp++) {
        mvprintw(2 + y_temp, 37, "|");
        mvprintw(2 + y_temp, 38 + s_x - 2, "|");
    }
    if (game->sec > 9)
        mvprintw(17, 23, "%d : %d", game->min, game->sec);
    else
        mvprintw(17, 23, "%d : 0%d", game->min, game->sec);
}

void type(char **map, t_game *game, time_t *start)
{
    for (int b = 0, yess = 0; map[b] != NULL; b++, yess++) {
        mvprintw(yess, 0, map[b]);
        print_map(game);
        // print_board(game);
        refresh();
    }
}