/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** handles all the putstr and putchar
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int handler_putchar_basic(FILE *fd, va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putchar(fd, va_arg(ap, int));
        return (1);
    } else {
        return (0);
    }
}

int handler_putchar_percentage(FILE *fd, va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putchar(fd, '%');
        return (1);
    } else {
        return (0);
    }
}

int handler_putstr(FILE *fd, va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putstr(fd, va_arg(ap, char *));
        return (1);
    } else {
        return (0);
    }
}

int handler_showstr(FILE *fd, va_list ap, char *arguments)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_showstr(fd, va_arg(ap, char *));
        return (1);
    } else {
        return (0);
    }
}
