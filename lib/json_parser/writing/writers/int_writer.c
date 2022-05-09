/*
** EPITECH PROJECT, 2022
** savve
** File description:
** int_writer
*/

#include <stdio.h>
#include "linked_list.h"
#include "json_parser.h"
#include "my.h"

int integer_writer(FILE *fd, node_t *node)
{
    int *value = node->value;

    if (node->len == 0) {
        my_put_nbr_base(fd, value[0], "0123456789");
    } else {
        my_printf(fd, "[");
        for (int i = 0; i < node->len; i++) {
            my_put_nbr_base(fd, value[i], "0123456789");
            put_comma(i, node->len, fd);
        }
        my_printf(fd, "]");
    }
    return (0);
}
