/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** check if the current buff contains an int
*/

#include "json_parser.h"

int check_int(const char *buff)
{
    int i = 0;
    int len = 0;
    int stop = 0;

    if (buff[0] && buff[0] == '-')
        i++;
    for (; buff[i] && (buff[i] != ',' && buff[i] != '\n') && !stop; i++) {
        if (!is_number(buff[i]))
            stop = 1;
        else
            len++;
    }
    if (len == 0)
        return (-1);
    return (1);
}
