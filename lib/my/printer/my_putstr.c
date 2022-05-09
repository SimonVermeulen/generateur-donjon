/*
** EPITECH PROJECT, 2021
** C Pool Day 04
** File description:
** displays a given string
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

int my_putstr(FILE *fd, char const *str)
{
    int i = 0;

    for (; str[i]; i++)
        my_putchar(fd, str[i]);
    return (i);
}
