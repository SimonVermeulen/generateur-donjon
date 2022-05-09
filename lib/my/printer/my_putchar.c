/*
** EPITECH PROJECT, 2021
** C Pool Day 07
** File description:
** putchar
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(FILE *fd, char c)
{
    char array[1] = {0};

    array[0] = c; 
    fwrite(array, sizeof(char), 1, fd);
}
