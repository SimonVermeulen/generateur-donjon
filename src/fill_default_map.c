/*
** EPITECH PROJECT, 2022
** generator
** File description:
** fill_default_map
*/

#include "generator.h"
#include <stdlib.h>
#include <string.h>

static char *my_memset(char c, int len)
{
    char *string = NULL;

    string = malloc(sizeof(char) * (len + 1));
    if (!string)
        return (NULL);
    for (int i = 0; i < len; i++)
        string[i] = c;
    string[len] = '\0';
    return (string);
}

int fill_default_map(generator_t *generator)
{
    char **map = NULL;

    map = malloc(sizeof(char *) * (generator->map_size + 1));
    if (!map)
        return (1);
    for (int i = 0; i < generator->map_size; i++) {
        map[i] = my_memset('X', generator->map_size);
        if (!map[i])
            return (1);
    }
    map[generator->map_size] = NULL;
    generator->map = map;
    return (0);
}
