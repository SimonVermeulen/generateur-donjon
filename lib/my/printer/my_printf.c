/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** display given parameters
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int search_for_flags(char c)
{
    char flags[12] = "dipuboxXc%sS";

    for (int i = 0; flags[i] != '\0'; i++)
        if (flags[i] == c)
            return (i);
    return (-1);
}

int search_for_prefix(char c)
{
    char prefix[1] = "#";

    if (c == prefix[0])
        return (1);
    return (0);
}

void print_wrong_flag(FILE *fd, const char *format, int index)
{
    my_putchar(fd, '%');
    my_putchar(fd, format[index]);
}

int check_flags(FILE *fd, const char *format, va_list ap, int index)
{
    int (*my_printf_farray[12])(FILE *fd, va_list ap, char *arguments) =
    {handler_put_nbr_decimal, handler_put_nbr_decimal, handler_put_nbr_long,
    handler_put_unsigned_nbr, handler_convert_base_binary,
    handler_convert_base_octal, handler_convert_base_hexa,
    handler_convert_base_maj_hexa, handler_putchar_basic,
    handler_putchar_percentage, handler_putstr, handler_showstr};
    int flag_index = 0;
    int prefix = 0;

    for (; search_for_prefix(format[index]); index++, prefix++);
    flag_index = search_for_flags(format[index]);
    if (flag_index != -1) {
        if (!prefix)
            my_printf_farray[flag_index](fd, ap, NULL);
        else
            my_printf_farray[flag_index](fd, ap, my_strdup("#"));
    } else {
        print_wrong_flag(fd, format, index);
    }
    return (index);
}

int my_printf(FILE *fd, const char *format, ...)
{
    va_list ap;

    if (!format)
        return (84);
    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            i = check_flags(fd, format, ap, i);
        } else {
            my_putchar(fd, format[i]);
        }
    }
    va_end(ap);
    return (0);
}
