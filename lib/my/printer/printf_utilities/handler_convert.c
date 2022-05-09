/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** handles all the conversions
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int handler_convert_base_binary(FILE *fd, va_list ap, char *argument)
{
    if (ap && argument == NULL) {
        my_putstr(fd, my_convert_base(va_arg(ap, int), "01"));
        return (1);
    } else if (ap && argument[0] == '#') {
        my_putstr(fd, "0b");
        my_putstr(fd, my_convert_base(va_arg(ap, int), "01"));
        return (1);
    } else {
        return (0);
    }
}

int handler_convert_base_octal(FILE *fd, va_list ap, char *argument)
{
    if (ap && argument == NULL) {
        my_putstr(fd, my_convert_base(va_arg(ap, int), "01234567"));
        return (1);
    } else if (ap && argument[0] == '#') {
        my_putstr(fd, "0o");
        my_putstr(fd, my_convert_base(va_arg(ap, int), "01234567"));
        return (1);
    } else {
        return (0);
    }
}

int handler_convert_base_hexa(FILE *fd, va_list ap, char *argument)
{
    if (ap && argument == NULL) {
        my_putstr(fd, my_convert_base(va_arg(ap, int), "0123456789abcdef"));
        return (1);
    } else if (ap && argument[0] == '#') {
        my_putstr(fd, "0x");
        my_putstr(fd, my_convert_base(va_arg(ap, int), "0123456789abcdef"));
        return (1);
    } else {
        return (0);
    }
}

int handler_convert_base_maj_hexa(FILE *fd, va_list ap, char *argument)
{
    if (ap && argument == NULL) {
        my_putstr(fd, my_convert_base(va_arg(ap, int), "0123456789ABCDEF"));
        return (1);
    } else if (ap && argument[0] == '#') {
        my_putstr(fd, "0X");
        my_putstr(fd, my_convert_base(va_arg(ap, int), "0123456789ABCDEF"));
        return (1);
    } else {
        return (0);
    }
}
