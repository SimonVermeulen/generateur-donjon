/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** handles all the putnbr
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int handler_put_nbr_decimal(FILE *fd, va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_put_nbr_base(fd, va_arg(ap, int), "0123456789");
        return (1);
    } else {
        return (0);
    }
}

int handler_put_nbr_long(FILE *fd, va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putstr(fd, "0x");
        my_put_nbr_base_long(fd, va_arg(ap, long long), "0123456789abcdef");
        return (1);
    } else {
        return (0);
    }
}

int handler_put_unsigned_nbr(FILE *fd, va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_put_unsigned_nbr(fd, va_arg(ap, unsigned int));
        return (1);
    } else {
        return (0);
    }
}
