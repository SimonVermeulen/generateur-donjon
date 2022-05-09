/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** Gets the key of a given line
*/

#include <stdlib.h>
#include <unistd.h>
#include "json_parser.h"
#include "linked_list.h"

static int get_len(const char *buffer)
{
    int len = 0;

    for (; buffer[len] && buffer[len] != '"'; len++);
    return (len);
}

static int fill_key(const char *buffer, node_t *tmp, int len, int index)
{
    tmp->key = malloc(sizeof(char) * (len + 1));
    if (!tmp->key)
        return (-1);
    for (int i = 0; buffer[index] && buffer[index] != '"'; index++, i++)
        tmp->key[i] = buffer[index];
    tmp->key[len] = '\0';
    return (index + 1);
}

int get_key(const char *buffer, int index, node_t *tmp)
{
    int len = 0;

    if (buffer[index] && buffer[index] != '"') {
        write(2, "Error: Invalid key\n", 20);
        return (-1);
    }
    index++;
    len = get_len(&buffer[index]);
    index = fill_key(buffer, tmp, len, index);
    if (index < 0)
        return (-1);
    if (buffer[index] && buffer[index] != ':') {
        write(2, "Error: expected a ':'\n", 23);
        return (-1);
    }
    index++;
    return (index);
}
