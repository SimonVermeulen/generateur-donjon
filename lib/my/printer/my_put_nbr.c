/*
** EPITECH PROJECT, 2021
** CPool day03
** File description:
** prints a given number
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

int my_put_nbr_base(FILE *fd, int nb, char *base)
{
    int base_len = my_strlen(base);
    long new_nb = nb;

    if (new_nb < 0) {
        my_putchar(fd, '-');
        new_nb = -new_nb;
    }
    if (new_nb >= base_len)
        my_put_nbr_base(fd, new_nb / base_len, base);
    my_putchar(fd, base[new_nb % base_len]);
    return (0);
}

int my_put_nbr_base_long(FILE *fd, long long nb, char *base)
{
    int base_len = my_strlen(base);

    if (nb < 0)
        nb = -nb;
    if (nb >= base_len)
        my_put_nbr_base_long(fd, nb / base_len, base);
    my_putchar(fd, base[nb % base_len]);
    return (0);
}

int my_put_unsigned_nbr(FILE *fd, unsigned int nb)
{
    long int new_nb = nb;

    if (new_nb < 0) {
        my_putstr(fd, "4294967295");
        return (1);
    }
    if (new_nb > 9) {
        my_put_nbr_base(fd, new_nb / 10, "0123456789");
    }
    my_putchar(fd, new_nb % 10 + 48);
    return (0);
}
