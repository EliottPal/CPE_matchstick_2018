/*
** EPITECH PROJECT, 2019
** board_interaction
** File description:
** update game_board
*/

#include <stdlib.h>
#include "../inc/matchstick.h"

char **update_board(char **board, int line, int nb_matches)
{
    int total_lines = 0;
    for (total_lines = 0; board[total_lines] != NULL; total_lines++);
    int line_len = (total_lines * 2) + 1;
    int matches_per_line;
    int j = 0;
    int count = 0;
    int check = 0;

    for (j = line_len; board[line][j] != '|'; j--);
    for (check = 0; board[line][check] != '|'; check++);
    matches_per_line = line_len - (check * 2) - 4;

    for (j = j; count < nb_matches; j--, count++)
            board[line][j] = ' ';
    return (board);
}