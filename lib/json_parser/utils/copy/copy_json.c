/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** copy_json
*/

#include <stdlib.h>
#include "my.h"
#include "linked_list.h"
#include "json_parser.h"

static node_t *copy_node(node_t *src)
{
    node_t *dest = NULL;

    dest = create_emptynode();
    if (!dest)
        return (NULL);
    if (copy_value(src, dest) < 0)
        return (NULL);
    dest->key = my_strdup(src->key);
    dest->len = src->len;
    dest->type = src->type;
    return (dest);
}

list_t *copy_list(list_t *src)
{
    list_t *dest = NULL;
    node_t *current = NULL;
    node_t *new_node = NULL;

    dest = create_empty_list();
    if (!dest)
        return (NULL);
    current = src->head;
    for (int i = 0; i < src->nb_elements; i++) {
        new_node = copy_node(current);
        if (!new_node)
            return (NULL);
        push_element(dest, new_node);
        current = current->next;
    }
    return (dest);
}
