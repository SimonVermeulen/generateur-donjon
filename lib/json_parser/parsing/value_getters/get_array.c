/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets an array from a buff
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"
#include "json_parser.h"

static int get_nb_elements_others(const char *buff)
{
    int is_quote = 0;
    int nb_elements = 0;
    int i = 0;

    for (; buff[i] && buff[i] != ']'; i++) {
        if (buff[i] == '"' && !is_quote)
            is_quote = 1;
        else if (buff[i] == '"' && is_quote)
            is_quote = 0;
        nb_elements += (buff[i] == ',' && !is_quote) ? 1 : 0;
    }
    nb_elements++;
    nb_elements = (i == 1) ? -1 : nb_elements;
    return (nb_elements);
}

static int check_stop(int array_level, char c)
{
    if (c == ']' && array_level == 1)
        return (1);
    return (0);
}

static int get_nb_elements_object(const char *buff)
{
    int level = 0;
    int array_level = 0;
    int nb_elements = 0;

    for (int i = 0; buff[i] && !check_stop(array_level, buff[i]); i++) {
        if (buff[i] == '{')
            level++;
        else if (buff[i] == '}')
            level--;
        nb_elements += (buff[i] == '}' && !level) ? 1 : 0;
        array_level += (buff[i] == '[') ? 1 : 0;
        array_level -= (buff[i] == ']' && array_level) ? 1 : 0;
    }
    nb_elements = (nb_elements == 0) ? -1 : nb_elements;
    return (nb_elements);
}

static int get_nb_elements(const char *buff, node_t *new_node)
{
    int nb_elements = 0;

    if (new_node->type == 0) {
        write(2, "Error: unexpected type (array in an array)\n", 44);
        return (-1);
    } else if (new_node->type == 1) {
        nb_elements = get_nb_elements_object(buff);
    } else {
        nb_elements = get_nb_elements_others(buff);
    }
    return (nb_elements);
}

int get_array(const char *buff, node_t *new_node, int useless)
{
    int (*getters[5])(const char *, node_t *, int) = {&get_array,
        &get_object, &get_double, &get_int, &get_string};
    int nb_elements = 0;
    int len = 0;

    useless++;
    check_type(&buff[1], new_node);
    nb_elements = get_nb_elements(buff, new_node);
    if (nb_elements < 0)
        return (-1);
    len = getters[new_node->type](&buff[1], new_node, nb_elements);
    if (len < 0)
        return (-1);
    if (buff[len] && buff[len] != ']') {
        write(2, "Error: expected a ']'\n", 23);
        return (-1);
    }
    new_node->type *= 10;
    return (len + 1);
}
