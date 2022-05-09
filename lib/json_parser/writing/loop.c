/*
** EPITECH PROJECT, 2022
** savve
** File description:
** loop
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "json_parser.h"
#include "my.h"

void put_comma(int index, int len, FILE *fd)
{
    if (index != len - 1)
        my_printf(fd, ",");
}

int launch_loop(list_t *list, FILE *fd)
{
    int (*writer_array[4])(FILE *fd, node_t *node) = {
        object_writer, double_writer, integer_writer, string_writer
    };
    node_t *node = list->head;
    int select = 0;
    int stop = 0;

    my_printf(fd, "{");
    for (int i = 0; i < list->nb_elements; i++) {
        if (node->key && !stop)
            my_printf(fd, "\"%s\":", node->key);
        else
            return (1);
        select = (node->type > 9) ? node->type / 10 : node->type;
        if (select <= 4)
            stop = writer_array[select - 1](fd, node);
        node = node->next;
        put_comma(i, list->nb_elements, fd);
    }
    my_printf(fd, "}");
    return (0);
}
