/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** checks if the current buff contains a double
*/

#include "json_parser.h"

int check_double(const char *buff)
{
    int i = 0;
    int dot = 0;
    int len = 0;
    int stop = 0;

    if (buff[0] && buff[0] == '-')
        i++;
    for (; buff[i] && (buff[i] != ',' && buff[i] != '\n') && !stop; i++) {
        if (buff[i] == '.')
            dot++;
        else if (!is_number(buff[i]))
            stop = 1;
        else
            len++;
    }
    if (dot != 1 || len < 1)
        return (-1);
    return (1);
}
