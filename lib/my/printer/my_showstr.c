/*
** EPITECH PROJECT, 2021
** C Pool Day 07
** File description:
** showstr
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static char *my_fill_str(char *str)
{
    int len = my_strlen(str);
    char dup[4] = {str[0], str[1], str[2], str[3]};

    for (int i = 0; i != 3; i++) {
        if (dup[i] != '\0')
            str[i + 1] = dup[i];
        else
            str[i + 1] = '0';
    }
    str[4] = '\0';
    if (len != 3)
        my_revstr(&str[1]);
    str[0] = '\\';
    return (str);
}

void my_showstr(FILE *fd, const char *str)
{
    char *converted_non_printabl = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_printable(str[i])) {
            converted_non_printabl = my_convert_base((int) str[i], "01234567");
            converted_non_printabl = my_fill_str(converted_non_printabl);
            my_putstr(fd, converted_non_printabl);
        } else {
            my_putchar(fd, str[i]);
        }
    }
}
