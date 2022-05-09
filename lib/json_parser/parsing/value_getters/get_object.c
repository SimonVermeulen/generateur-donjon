/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets object from a given buff
*/

#include <unistd.h>
#include <stdlib.h>
#include "json_parser.h"
#include "linked_list.h"

static int get_buff_infos(const char *buff, node_t *tmp,
    int len)
{
    len = get_key(buff, len, tmp);
    if (len < 0)
        return (-1);
    len = get_value(buff, len, tmp);
    if (len < 0)
        return (-1);
    return (len);
}

static int get_single_object(const char *buff, node_t *new_node)
{
    node_t *tmp = NULL;
    list_t *list = NULL;
    int len = 1;
    int stop = 0;

    if (buff[0] && buff[0] != '{') {
        write(2, "Error: expected a '{'\n", 23);
        return (-1);
    }
    list = create_empty_list();
    if (!list)
        return (-1);
    for (; buff[len] && buff[len] != '}' && !stop;) {
        tmp = create_emptynode();
        len = get_buff_infos(buff, tmp, len);
        stop = (len < 0) ? 1 : 0;
        push_element(list, tmp);
    }
    new_node->value = list;
    return (len);
}

static int check_errors(const char *buff, int len, int nb_elements, int i)
{
    if (buff[len] && buff[len] != '}') {
        write(2, "Error: expected a '}'\n", 23);
        return (1);
    }
    len++;
    if (buff[len] && buff[len] != ',' && i != nb_elements - 1) {
        write(2, "Error: expected a ','\n", 23);
        return (1);
    }
    return (0);
}

static int get_object_array(const char *buff, node_t *new_node,
    int nb_elements, list_t **list_array)
{
    int len = 0;

    for (int i = 0; i < nb_elements; i++) {
        len += get_single_object(&buff[len], new_node);
        if (len < 0)
            return (-1);
        list_array[i] = (list_t *)new_node->value;
        if (check_errors(buff, len, nb_elements, i))
            return (-1);
        len += 2;
    }
    list_array[nb_elements] = NULL;
    return (len);
}

int get_object(const char *buff, node_t *new_node, int nb_elements)
{
    int len = 0;
    list_t **list_array = NULL;

    new_node->len = nb_elements;
    if (nb_elements == 0) {
        len = get_single_object(buff, new_node) + 1;
    } else {
        list_array = malloc(sizeof(list_t *) * (nb_elements + 1));
        if (!list_array)
            return (-1);
        len = get_object_array(&buff[0], new_node, nb_elements, list_array);
        new_node->value = list_array;
    }
    new_node->len = (nb_elements == 0) ? 0 : nb_elements;
    return (len);
}
