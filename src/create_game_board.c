/*
** EPITECH PROJECT, 2018
** game_board
** File description:
** create game_board
*/

#include <stdlib.h>
#include "../inc/matchstick.h"

char **fill_lines(char **game_board, int nb_line)
{
    int spaces = nb_line - 1;
    int line_len = 1;
    int i = 0;
    int j = 0;

    for (i = 1; i < (nb_line + 1); i++) {
        game_board[i][0] = '*';
        for (j = 1; j < (spaces + 1); j++)
            game_board[i][j] = ' ';
        for (j = spaces + 1; j < ((spaces+ 1) + line_len); j++)
            game_board[i][j] = '|';
        for (j = (spaces + 1 + line_len); j < (nb_line * 2); j++)
            game_board[i][j] = ' ';
        game_board[i][nb_line * 2] = '*';
        spaces--;
        line_len += 2;
    }
    return (game_board);
}

char **create_board(int lines)
{
    int line_len = (lines * 2) + 1;
    int i = 0;

    char **game_board = malloc(sizeof(char *) * (lines + 2));
    for (int k = 0; k != (lines + 2); k++)
        game_board[k] = malloc(sizeof(char) * line_len);

    for (i = 0; i != line_len; i++)
        game_board[0][i] = '*';

    for (i = 0; i != line_len; i++)
        game_board[lines + 1][i] = '*';

    fill_lines(game_board, lines);

    return (game_board);

}

void print_game_board(char **game_board, int total_lines)
{
    int i = 0;

    for (i = 0; i != total_lines + 2; i++) {
        my_putstr(game_board[i]);
        my_putchar('\n');
    }
}