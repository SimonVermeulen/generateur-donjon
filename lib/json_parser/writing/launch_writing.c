/*
** EPITECH PROJECT, 2022
** savve
** File description:
** launch_writing
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "json_parser.h"

static const char args[2][2] = {"w+", "a+"};

int launch_writing(list_t *list, char *path, int type)
{
    FILE *fd = NULL;

    if (!list)
        return (1);
    fd = fopen(path, args[type]);
    if (!fd)
        return (1);
    if (launch_loop(list, fd)) {
        fclose(fd);
        return (1);
    }
    fclose(fd);
    return (0);
}
