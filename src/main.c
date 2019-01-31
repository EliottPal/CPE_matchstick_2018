/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../inc/matchstick.h"

void help(void)
{
my_putstr("GAME:\n\n");
my_putstr("This game is based on a very famous game based on matchsticks.\n");
my_putstr("Each turn the 2 players can take a certain ");
my_putstr("number of matches on a chosen line\n\n");
my_putstr("The player who takes the last matchstik loses the game.\n");
my_putstr("USAGE:\n\n");
my_putstr("./matchstick x y\n");
my_putstr("x  ->  lines of the board\n");
my_putstr("y  ->  max number of matches the player can remove each turn\n");
}

int main(int ac, char **av)
{
    if (ac < 2) {
        my_putstr("Not enough arguments\n");
        return (84);
    }
    if (ac > 3) {
        my_putstr("Too much arguments\n");
        return (84);
    }
    if (ac == 2 && av[0][0] == '-' && av[0][1]) {
        help();
        return (0);
    }
    else {
        int total_lines = my_getnbr(av[1]);
        int max_matches = my_getnbr(av[2]);
        my_engine(total_lines, max_matches);
        return (0);
    }

}
