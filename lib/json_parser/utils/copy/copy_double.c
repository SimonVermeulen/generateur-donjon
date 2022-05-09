/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** copy_double
*/

#include <stdlib.h>
#include "linked_list.h"

static void copy_double_array(double *dest, double *src, int len)
{
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
}

int copy_double(node_t *src, node_t *dest)
{
    double *copy_value = NULL;
    double *to_copy_value = src->value;
    int len = (src->len == 0) ? 1 : src->len;

    copy_value = malloc(sizeof(double) * len);
    if (!copy_value)
        return (-1);
    if (src->len == 0)
        copy_value[0] = to_copy_value[0];
    else
        copy_double_array(copy_value, to_copy_value, len);
    dest->value = copy_value;
    return (0);
}
