/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** copy_value
*/

#include <stdlib.h>
#include "linked_list.h"
#include "json_parser.h"

static int copy_object(node_t *dest, node_t *src)
{
    list_t **list_array = NULL;

    if (src->type == 1) {
        dest->value = copy_list(src->value);
    } else {
        list_array = malloc(sizeof(list_t *) * src->len);
        if (!list_array)
            return (-1);
        for (int i = 0; i < src->len; i++)
            list_array[i] = copy_list(((list_t **)src->value)[i]);
        dest->value = list_array;
    }
    return (0);
}

int copy_value(node_t *src, node_t *dest)
{
    int (*copy_func[3])(node_t *, node_t *) = {copy_double,
        copy_int, copy_string};
    int type = 0;

    if (src->type == 1 || src->type == 10) {
        if (copy_object(dest, src) < 0)
            return (-1);
    } else {
        type = (src->type > 10) ? src->type / 10 : src->type;
        type -= 2;
        copy_func[type](src, dest);
    }
    if (!dest->value)
        return (-1);
    return (0);
}
