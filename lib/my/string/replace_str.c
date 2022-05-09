/*
** EPITECH PROJECT, 2021
** template
** File description:
** replace_str.c
*/

#include <stdlib.h>
#include "my.h"

char *replace_str(char *str, char const *replace, int start, int end)
{
    char *tmp = my_strdup(str);
    int i;
    int o;

    for (i = 0; replace[i] != '\0'; i++)
        str[start + i] = replace[i];
    for (o = 0; tmp[o + end] != '\0'; o++)
        str[start + i + o] = tmp[o + end];
    str[start + i + o] = '\0';
    free(tmp);
    return str;
}
