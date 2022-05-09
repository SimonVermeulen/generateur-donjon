/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** free_json
*/

#include <stdlib.h>
#include "linked_list.h"
#include "json_parser.h"

static void free_json_recursive(list_t *object);

static void free_array(node_t *current)
{
    for (int i = 0; i < current->len; i++) {
        free_json_recursive(((list_t **) current->value)[i]);
        free(((list_t **) current->value)[i]);
    }
    free(current->value);
    current->value = NULL;
    current->len = 0;
}

static void free_json_recursive(list_t *object)
{
    node_t *current = NULL;

    while (object->nb_elements != 0) {
        current = object->head;
        if (current->type == 1) {
            free_json_recursive(current->value);
            free(current->value);
            current->value = NULL;
        }
        if (current->type == 10) {
            free_array(current);
        }
        shift_element(object);
    }
}

int free_json_object(list_t *object)
{
    int value = 0;

    if (object == NULL)
        return 84;
    free_json_recursive(object);
    free(object);
    return (value);
}
