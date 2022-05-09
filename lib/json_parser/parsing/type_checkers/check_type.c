/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** checks the type of the next value
*/

#include "json_parser.h"

void check_type(const char *buff, node_t *tmp)
{
    int (*checkers[5])(const char *) = {&check_array, &check_object,
        &check_double, &check_int, &check_string};

    for (int i = 0; i < 5; i++) {
        if (checkers[i](buff) > 0) {
            tmp->type = i;
            return;
        }
    }
    tmp->type = -1;
}
