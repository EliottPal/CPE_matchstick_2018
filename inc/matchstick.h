/*
** EPITECH PROJECT, 2019
** matchstick.h
** File description:
** protos
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

void my_putchar(char c);
void my_putstr(char *str);
void my_put_nbr(int nb);
int	my_getnbr(char *str);
char **fill_lines(char **board, int lines);
char **create_board(int lines);
void print_game_board(char **game_board, int total_lines);
char **update_board(char **board, int line, int nb_matches);
int get_keyboard_input(char **board, int total_lines, int max_matches);
char **board_beginning(int lines);
int get_line_to_change(int total_lines);
int get_matches_to_remove(char **board, int total_lines,
                            int max_matches, int line);
int count_matches(char **board, int total_lines);
int my_engine(int total_lines, int max_matches);
int ai_line_to_change(char **board, int total_lines);
int ai_matches_to_remove(char **board, int line,
                            int total_lines, int max_matches);
int ai_engine(char **board, int total_lines, int max_matches);
int check_matches_per_line(char **board, int total_lines, int line);
int player_engine(char **board, int matches, int line, int total_lines);

#endif /* !MATCHSTICK_H_ */
