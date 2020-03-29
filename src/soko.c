/*
** EPITECH PROJECT, 2019
** sokaban window
** File description:
** The program will ees the space bar
*/

#include "../include/tetris.h"

void cloc(char **map, tetris_t *tetris)
{
    t_game *game = malloc(sizeof(t_game));
    time_t *start = NULL;
    game->min = 0;
    game->sec = 0;
    int c = 0;
    for (int compt_move = 1; c != 27; compt_move++, game->sec++) {
        type(map, game, start, tetris);
        c = getch();
    }
}

void print_map(t_game *game,tetris_t *tetris)
{
    int x_temp = 0, y_temp = 0;
    mvprintw(1, 37, "+");
    mvprintw(1, tetris->size_x + 36, "+");
    mvprintw(tetris->size_y, 37, "+");
    mvprintw(tetris->size_y, tetris->size_x + 36, "+");
    for(; x_temp < tetris->size_x - 2; x_temp++) {
        mvprintw(1, 38 + x_temp, "-");
        mvprintw(tetris->size_y, 38 + x_temp, "-");
    }
    for(; y_temp < tetris->size_y - 2; y_temp++) {
        mvprintw(2 + y_temp, 37, "|");
        mvprintw(2 + y_temp, 38 + tetris->size_x - 2, "|");
    }
}

void print_board(t_game *game,tetris_t *tetris)
{
    if (my_strncmp(tetris->next, "Yes", 3) == 0)
        {
            mvprintw(0, tetris->size_x + 36 + 5 , "/------/");
            mvprintw(1, tetris->size_x + 36 + 5 , "|      |");
            mvprintw(2, tetris->size_x + 36 + 5 , "|      |");
            mvprintw(3, tetris->size_x + 36 + 5 , "|      |");
            mvprintw(4, tetris->size_x + 36 + 5 , "|      |");
            mvprintw(5, tetris->size_x + 36 + 5 , "/------/");
        }
    mvprintw(10, 23, "0");
    mvprintw(11, 23, "0");
    mvprintw(13, 23, "0");
    mvprintw(14, 23, "%s", tetris->level);
    if (game->sec > 9)
        mvprintw(16, 17, "%d :  %d", game->min, game->sec);
    else
        mvprintw(16, 20, "%d : 0%d", game->min, game->sec);
}

void type(char **map, t_game *game, time_t *start,tetris_t *tetris)
{
    for (int b = 0, yess = 0; map[b] != NULL; b++, yess++) {
        mvprintw(yess, 0, map[b]);
        print_map(game, tetris);
        print_board(game, tetris);
        refresh();
    }
}