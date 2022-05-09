/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** main file for json_parsing
*/

#include <stdlib.h>
#include <stdio.h>
#include "json_parser.h"
#include "linked_list.h"

list_t *launch_parsing(char *path)
{
    char *buffer = NULL;
    list_t *list = NULL;

    if (!path)
        return (NULL);
    buffer = get_buffer(path);
    if (!buffer)
        return (NULL);
    if (stringify(&buffer))
        return (NULL);
    if (buffer)
        list = get_data(&buffer[1]);
    free(buffer);
    return (list);
}
