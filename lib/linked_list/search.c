/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** search functions
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"

static int cmp(char const *s1, char const *s2)
{
    int i = 0;
    int result = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    result = s1[i] - s2[i];
    return (result);
}

node_t *search_from_key(list_t *list, const char *key)
{
    node_t *current = NULL;

    if (!list)
        return (NULL);
    current = list->head;
    for (int i = 0; i < list->nb_elements; i++) {
        if (!cmp(key, current->key))
            return (current);
        current = current->next;
    }
    return (NULL);
}

void *get_value_list(list_t *list, const char *name, int type)
{
    node_t *node = NULL;

    if (list == NULL || name == NULL)
        return NULL;
    node = search_from_key(list, name);
    if (node == NULL || node->type != type)
        return NULL;
    return node->value;
}

int set_value_list(list_t *list, const char *name, void *value)
{
    node_t *node = NULL;

    if (list == NULL || name == NULL)
        return 0;
    node = search_from_key(list, name);
    if (node == NULL)
        node = create_add_node(value, 0, name, list, 1);
    if (node == NULL)
        return 0;
    node->value = value;
    return 1;
}
