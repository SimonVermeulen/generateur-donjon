/*
** EPITECH PROJECT, 2022
** savve
** File description:
** double_writer
*/

#include <stdio.h>
#include "linked_list.h"
#include "json_parser.h"
#include "my.h"

static void write_value(FILE *fd, double value)
{
    int pre_decimal = (int) value;
    float decimal = 0;

    decimal = (value - pre_decimal) * 10;
    my_printf(fd, "%d.%d", pre_decimal, (int) decimal);
}

int double_writer(FILE *fd, node_t *node)
{
    double *value = node->value;

    if (node->len == 0) {
        write_value(fd, value[0]);
    } else {
        my_printf(fd, "[");
        for (int i = 0; i < node->len; i++) {
            write_value(fd, value[i]);
            put_comma(i, node->len, fd);
        }
        my_printf(fd, "]");
    }
    return (0);
}
