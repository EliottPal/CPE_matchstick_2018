/*
** EPITECH PROJECT, 2019
** engine
** File description:
** manage the game
*/

#include <stdlib.h>
#include "../inc/matchstick.h"

int count_matches(char **board, int total_lines)
{
    int line_len = (total_lines * 2) + 1;
    int counter = 0;

    for (int i = 0; i < total_lines + 2; i++)
        for (int j = 0; j < line_len; j++)
            if (board[i][j] == '|')
                counter++;

    return (counter);
}

int my_engine(int total_lines, int max_matches)
{
    int total_matches = total_lines * total_lines;
    char **board = board_beginning(total_lines);
    int count = count_matches(board, total_lines);
    int check = 0;

    while (count > 0) {
        count = count_matches(board, total_lines);
        check = get_keyboard_input(board, total_lines, max_matches);
        if (check == 1) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        else if (check == 0)
            return (0);
        if (ai_engine(board, total_lines, max_matches) == 2) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
}
