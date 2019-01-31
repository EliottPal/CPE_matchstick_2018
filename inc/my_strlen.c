/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Counts and return the number of characters found in the string
*/

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
