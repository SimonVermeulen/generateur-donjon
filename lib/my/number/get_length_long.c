/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** get_length_long.c
*/

int get_length_long(long nbr)
{
    int count = 0;

    if (nbr == 0)
        return 1;
    while (nbr != 0) {
        nbr = nbr / 10;
        count++;
    }
    return count;
}
