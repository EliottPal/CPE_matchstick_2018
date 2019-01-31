/*
** EPITECH PROJECT, 2019
** get_keyboard_input
** File description:
** manage player's inputs
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../inc/matchstick.h"

char **board_beginning(int lines)
{
    char **board = create_board(lines);
    print_game_board(board, lines);

    return (board);
}

int get_line_to_change(int total_lines)
{
    char *buffer = NULL;
    size_t len = 0;

    my_putstr("Line: ");
    if (getline(&buffer, &len, stdin) == -1)
        return (0);

    if ( my_getnbr(buffer) == 0)
        return (84);

    else {
        int line = my_getnbr(buffer);
        while (line > total_lines || line < 0) {
            my_putstr("Error: this line is out of range\n");
            line = get_line_to_change(total_lines);
        }
        return (line);
    }
}

int get_matches_to_remove(char **board, int total_lines,
                            int max_matches, int line)
{
    char *buffer = NULL;
    size_t len = 0;
    my_putstr("Matches: ");
    if (getline(&buffer, &len, stdin) == -1)
        return (0);
    if (my_getnbr(buffer) == 0)
        return (84);
    else {
        int matches = my_getnbr(buffer);
        while (matches > check_matches_per_line(board, total_lines, line)) {
            my_putstr("Error: not enough matches on this line\n");
            matches = get_matches_to_remove(board,
                total_lines, max_matches, line);
        }
        while (matches > max_matches) {
            my_putstr("Error: you cannot remove more than ");
            my_put_nbr(max_matches);
            my_putstr(" matches per turn\n");
            matches = get_matches_to_remove(board,
                total_lines, max_matches, line);
        }
        return (matches);
    }
}

int player_engine(char **board, int matches, int line, int total_lines)
{
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    board = update_board(board, line, matches);
    print_game_board(board, total_lines);
        if (count_matches(board, total_lines) == 0)
        return (1);
    return (2);
}

int get_keyboard_input(char **board, int total_lines, int max_matches)
{
    my_putstr("\nYour turn:\n");
    int line = get_line_to_change(total_lines);
        if (line == 0)
            return (0);
    while (line == 84) {
        my_putstr("Error: invalid input (positive number expected)\n");
        line = get_line_to_change(total_lines);
    }
    int matches =  get_matches_to_remove(board, total_lines, max_matches, line);
        if (matches == 0)
        return (0);
    while (matches == 84) {
        my_putstr("Error: invalid input (positive number expected)\n");
        matches = get_matches_to_remove(board, total_lines, max_matches, line);
    }
    player_engine(board, matches, line, total_lines);
}