/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** inits a node
*/

#include <stdlib.h>
#include "linked_list.h"
#include "my.h"

node_t *create_emptynode(void)
{
    node_t *new_node = NULL;

    new_node = malloc(sizeof(node_t));
    if (!new_node)
        return (NULL);
    new_node->type = -1;
    new_node->len = 0;
    new_node->value = NULL;
    new_node->key = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;

    return (new_node);
}

node_t *create_newnode(void *value, int type, int len)
{
    node_t *new_node = NULL;

    new_node = create_emptynode();
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->type = type;
    new_node->len = len;
    return (new_node);
}

node_t *create_add_node(void *value, int type, const char *name, list_t *list, int len)
{
    node_t *new_node = create_newnode(value, type, len);

    if (new_node == NULL || list == NULL)
        return NULL;
    new_node->key = my_strdup(name);
    if (new_node->key == NULL) {
        free(new_node);
        return NULL;
    }
    if (push_element(list, new_node) > 1) {
        free(new_node);
        return NULL;
    }
    return new_node;
}

void splice(list_t *list, int index)
{
    node_t *current_node = NULL;

    if (index < 0 || index >= list->nb_elements)
        return;
    current_node = list->head;
    for (int i = 0; i < index; i++)
        current_node = current_node->next;
    if (current_node == list->head)
        list->head = current_node->next;
    current_node->prev->next = current_node->next;
    current_node->next->prev = current_node->prev;
    free_node(current_node);
    list->nb_elements--;
}

void free_node(node_t *node)
{
    void **value = NULL;

    if (node) {
        value = node->value;
        free(node->key);
        for (int i = 0; i < node->len && node->len != 0
            && node->type != 20 && node->type != 30; i++)
            free(value[i]);
        free(value);
        free(node);
    }
}
