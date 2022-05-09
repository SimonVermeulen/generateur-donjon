/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** stringify json files
*/

#include <stdlib.h>
#include <unistd.h>
#include "json_parser.h"

static int get_len(char *buffer)
{
    int is_quote = 0;
    int nb_quotes = 0;
    int len = 0;

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] && buffer[i] == '"' && !is_quote) {
            is_quote = 1;
            nb_quotes++;
        } else if (buffer[i] && buffer[i] == '"' && is_quote) {
            is_quote = 0;
            nb_quotes++;
        }
        len += (is_printable(buffer[i]) || is_quote) ? 1 : 0;
    }
    if (nb_quotes % 2) {
        write(2, "Error: Invalid file, unexpected or missing '\"'\n", 48);
        return (-1);
    }
    return (len);
}

static int fill_stringified_buffer(char *buffer, char *new_buffer)
{
    char is_quote = 0;
    int index = 0;

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] && buffer[i] == '"' && !is_quote)
            is_quote = 1;
        else if (buffer[i] && buffer[i] == '"' && is_quote)
            is_quote = 0;
        if (buffer[i] && is_printable(buffer[i]) || is_quote) {
            new_buffer[index++] = buffer[i];
        }
    }
    new_buffer[index] = '\0';
    return (0);
}

static int check_array_errors(char *new_buffer)
{
    int nb_open_array = 0;
    int nb_closed_array = 0;

    for (int i = 0; new_buffer[i]; i++) {
        nb_open_array += (new_buffer[i] == '[') ? 1 : 0;
        nb_closed_array += (new_buffer[i] == ']') ? 1 : 0;
    }
    if (nb_closed_array != nb_open_array) {
        write(2, "Error: unexpected '[' or ']'\n", 30);
        return (1);
    }
    return (0);
}

static int check_hook_errors(char *new_buffer)
{
    int nb_open_hook = 0;
    int nb_closed_hook = 0;
    int index = 0;

    for (; new_buffer[index]; index++) {
        nb_open_hook += (new_buffer[index] == '{') ? 1 : 0;
        nb_closed_hook += (new_buffer[index] == '}') ? 1 : 0;
    }
    if (new_buffer[0] != '{' || new_buffer[index - 1] != '}') {
        write(2, "Error: Invalid start or end of the file\n", 41);
        return (1);
    }
    if (nb_closed_hook != nb_open_hook) {
        write(2, "Error: unexpected '{' or '}'\n", 30);
        return (1);
    }
    return (0);
}

int stringify(char **buffer)
{
    char *new_buffer = NULL;
    int len = get_len(*buffer);

    if (len < 0)
        return (1);
    new_buffer = malloc(sizeof(char) * (len + 1));
    if (!new_buffer || fill_stringified_buffer(*buffer, new_buffer))
        return (1);
    free(*buffer);
    *buffer = new_buffer;
    if (check_hook_errors(new_buffer) || check_array_errors(new_buffer))
        return (1);
    return (0);
}
