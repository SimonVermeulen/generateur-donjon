/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** copy_int
*/

#include <stdlib.h>
#include "my.h"
#include "linked_list.h"

static char **copy_string_array(char **src, int len)
{
    char **str_array = NULL;

    str_array = malloc(sizeof(char *) * (len + 1));
    if (!str_array)
        return (NULL);
    for (int i = 0; i < len; i++)
        str_array[i] = my_strdup(src[i]);
    str_array[len] = NULL;
    return (str_array);
}

int copy_string(node_t *src, node_t *dest)
{
    int len = (src->len == 0) ? 1 : src->len;

    if (src->len == 0)
        dest->value = my_strdup(src->value);
    else
        dest->value = copy_string_array(src->value, len);
    if (!dest->value)
        return (-1);
    return (0);
}
