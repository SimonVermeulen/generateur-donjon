/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** adds and deletes elements in a list_t
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"

static int check_error(list_t *list, int is_delete)
{
    if (!list) {
        write(2, "The given list is not initialized or allocated\n", 48);
        return (1);
    }
    if (is_delete && list->nb_elements == 0) {
        write(2, "The list is empty", 18);
        return (1);
    }

    return (0);
}

int push_element(list_t *list, node_t *data)
{
    node_t *tmp = NULL;

    if (data == NULL)
        return 0;
    if (check_error(list, 0))
        return (0);
    if (list->nb_elements == 0) {
        list->nb_elements++;
        list->head = data;
        data->next = data->prev = data;
        return (1);
    }
    list->nb_elements++;
    tmp = list->head->prev;
    data->prev = tmp;
    tmp->next = data;
    data->next = list->head;
    list->head->prev = data;
    return (1);
}

int unshift_element(list_t *list, node_t *data)
{
    node_t *tmp = NULL;

    if (data == NULL)
        return 0;
    if (check_error(list, 0))
        return (0);
    if (list->nb_elements == 0) {
        list->nb_elements++;
        list->head = data;
        data->next = data->prev = data;
        return (1);
    }
    list->nb_elements++;
    tmp = list->head;
    data->next = tmp;
    data->prev = tmp->prev;
    tmp->prev = data;
    return (1);
}

int pop_element(list_t *list)
{
    node_t *tmp = NULL;

    if (check_error(list, 1))
        return (0);
    if (list->nb_elements > 1) {
        tmp = list->head->prev->prev;
        tmp->next = list->head;
    }
    list->nb_elements--;
    free_node(list->head->prev);
    if (tmp)
        list->head->prev = tmp;
    return (1);
}

int shift_element(list_t *list)
{
    node_t *tmp = NULL;

    if (check_error(list, 1))
        return (-1);
    if (list->nb_elements > 1) {
        tmp = list->head->next;
        tmp->prev = list->head->prev;
    }
    list->nb_elements--;
    free_node(list->head);
    if (tmp)
        list->head = tmp;
    return (1);
}
