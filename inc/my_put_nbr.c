/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** put_nbr
*/

#include "matchstick.h"

void my_put_nbr(int nb)
{
    if (nb < -2147483647)
        my_putstr("-2147483648");
    else if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    else if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else
    my_putchar(nb + '0');
}