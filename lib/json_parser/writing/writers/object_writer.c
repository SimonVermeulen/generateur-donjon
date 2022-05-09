/*
** EPITECH PROJECT, 2022
** savve
** File description:
** object_writer
*/

#include <stdio.h>
#include "linked_list.h"
#include "json_parser.h"
#include "my.h"

int object_writer(FILE *fd, node_t *node)
{
    list_t **list_array = NULL;
    int stop = 0;

    if (node->len == 0)
        stop = launch_loop(node->value, fd);
    else {
        list_array = node->value;
        my_printf(fd, "[");
        for (int i = 0; i < node->len && !stop; i++) {
            stop = launch_loop(list_array[i], fd);
            put_comma(i, node->len, fd);            
        }
        my_printf(fd, "]");
    }
    return (stop);
}
