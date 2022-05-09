/*
** EPITECH PROJECT, 2022
** savve
** File description:
** string_writer
*/

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "json_parser.h"
#include "my.h"

static char *set_string(char *string, char *dest)
{
    int offset = 0;
    int i = 0;

    for (; string[i]; i++) {
        if (string[i] == '\n') {
            dest[i + offset++] = '\\';
            dest[i + offset] = 'n';
        } else {
            dest[i + offset] = string[i];
        }
    }
    dest[i + offset] = '\0';
    return (dest);
}

static char *check_newline_string(char *string)
{
    int nb_newline = 0;
    char *tmp = NULL;
    int len = 0;

    for (; string[len]; len++)
        nb_newline += (string[len] == '\n') ? 1 : 0;
    if (nb_newline) {
        tmp = malloc(sizeof(char) * (len + nb_newline + 1));
        if (!tmp)
            return (NULL);
        tmp = set_string(string, tmp);
        free(string);
        return (tmp);
    }
    return (string);
}

static void check_newline_array(char **array)
{
    for (int i = 0; array[i]; i++)
        array[i] = check_newline_string(array[i]);
}

int string_writer(FILE *fd, node_t *node)
{
    char **array = NULL;
    char *string = NULL;

    if (node->len == 0) {
        string = check_newline_string(node->value);
        my_printf(fd, "\"%s\"", string);
    } else {
        array = node->value;
        check_newline_array(array);
        my_printf(fd, "[");
        for (int i = 0; i < node->len; i++) {
            my_printf(fd, "\"%s\"", array[i]);
            put_comma(i, node->len, fd);
        }
        my_printf(fd, "]");
    }
    return (0);
}
