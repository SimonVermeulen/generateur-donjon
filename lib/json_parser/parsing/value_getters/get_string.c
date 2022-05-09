/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets a string from the given buff
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"
#include "my.h"

static int get_len(const char *buff)
{
    int len = 1;

    if (buff[0] && buff[0] != '"') {
        write(2, "Error: expected a '\"'\n", 23);
        return (-1);
    }
    for (int i = 1; buff[i] && buff[i] != '"'; i++, len++);
    return (len);
}

static void get_value(const char *buff, char *word, int len)
{
    int offset = 0;

    for (int i = 1; i + offset < len; i++) {
        if (!my_strncmp(&buff[i + offset], "\\n", 1)) {
            offset++;
            word[i - 1] = '\n';
        } else {
            word[i - 1] = buff[i + offset];
        }
    }
    word[len - 1 - offset] = '\0';
}

static int get_single_string(const char *buff, node_t *new_node)
{
    char *word = NULL;
    int len = 0;

    len = get_len(buff);
    if (len < 0)
        return (-1);
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return (-1);
    get_value(buff, word, len);
    new_node->value = word;
    return (len + 1);
}

static int get_string_array(const char *buff, node_t *new_node,
    int nb_elements)
{
    char **word_array = NULL;
    int len = 0;
    int stop = 0;

    word_array = malloc(sizeof(char *) * (nb_elements + 1));
    if (!word_array)
        return (-1);
    for (int i = 0; i < nb_elements && !stop; i++, len++) {
        len += get_single_string(&buff[len], new_node);
        stop = (len < 0) ? 1 : 0;
        word_array[i] = (char *)new_node->value;
        if (buff[len] && buff[len] != ',' && i != nb_elements - 1) {
            write(2, "Error: expected a ','\n", 23);
            return (-1);
        }
    }
    word_array[nb_elements] = NULL;
    new_node->value = word_array;
    return (len);
}

int get_string(const char *buff, node_t *new_node, int nb_elements)
{
    int len = 0;

    new_node->len = (nb_elements == 0) ? 1 : nb_elements;
    if (nb_elements == 0)
        len = get_single_string(buff, new_node);
    else
        len = get_string_array(buff, new_node, nb_elements);
    new_node->len = (nb_elements == 0) ? 0 : nb_elements;
    return (len);
}
