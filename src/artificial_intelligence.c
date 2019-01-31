/*
** EPITECH PROJECT, 2019
** artificial intelligence
** File description:
** manage my AI
*/

#include <stdlib.h>
#include "../inc/matchstick.h"

int random_line(int total_lines)
{
    int nb = total_lines;
    nb = rand() % nb;
    nb++;

    return (nb);
}

int check_matches_per_line(char **board, int total_lines, int line)
{
    int check = 0;
    int counter = 0;
    int line_len = (total_lines * 2) + 1;

    for (check = 1; check != line_len; check++) {
        if (board[line][check] == '|')
            counter++;
    }
    return (counter);
}

int ai_line_to_change(char **board, int total_lines)
{
    int line = random_line(total_lines);

    while (check_matches_per_line(board, total_lines, line) == 0)
        line = random_line(total_lines);

    return (line);
}

int ai_matches_to_remove(char **board, int line,
                            int total_lines, int max_matches)
{
    int matches = 3;
    int line_len = (total_lines * 2) + 1;
    int count = check_matches_per_line(board, total_lines, line);

    if (max_matches == 1)
        matches = 1;

    if (count == 1 || count == 2)
        matches = 1;

    return (matches);
}

int ai_engine(char **board, int total_lines, int max_matches)
{
    int line = ai_line_to_change(board, total_lines);
    int matches = ai_matches_to_remove(board, line, total_lines, max_matches);

    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');

    board = update_board(board, line, matches);
    print_game_board(board, total_lines);

    if (count_matches(board, total_lines) == 0)
        return (2);
    return (0);
}