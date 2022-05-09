/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** main file for json_parsing
*/

#include <stdlib.h>
#include <unistd.h>
#include "json_parser.h"
#include "linked_list.h"

list_t *get_data(char *buffer)
{
    list_t *list = NULL;
    node_t *tmp = NULL;

    list = create_empty_list();
    for (int i = 0; buffer[i] && buffer[i] != '}';) {
        tmp = create_emptynode();
        i = get_key(buffer, i, tmp);
        if (i < 0)
            return (NULL);
        i = get_value(buffer, i, tmp);
        if (i < 0)
            return (NULL);
        push_element(list, tmp);
    }
    return (list);
}
