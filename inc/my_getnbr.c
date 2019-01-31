/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** get nbr
*/

int	my_getnbr(char *str)
{
    int	n = 0;
    int	isneg = 1;
    int i = 0;

    for (i = 0; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            isneg = isneg * -1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            n = n * 10;
            n = n + str[i] - '0';
            i++;
        }
        else
            return (n * isneg);
    }
    return (n * isneg);
}