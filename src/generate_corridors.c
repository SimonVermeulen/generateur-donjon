/*
** EPITECH PROJECT, 2022
** generator
** File description:
** generate_corridors
*/

#include <stdio.h>
#include "generator.h"

static int check_limit(generator_t *generator, int x, int y)
{
    if (y - OFFSET <= 0 || x - OFFSET <= 0 || y + OFFSET >= generator->map_size || x + OFFSET >= generator->map_size)
        return (1);
    return (0);
}

void dig_corridor(room_t *src, room_t *dest, generator_t *generator)
{
    int absolute_relat_y = 0;
    int absolute_relat_x = 0;
    int relative_x = src->x - dest->x;
    int relative_y = src->y - dest->y;
    int x = dest->x;
    int y = dest->y;

    if (relative_x > 0) {
        x += dest->width - 1;
        relative_x -= dest->width;
    }
    if (relative_y > 0) {
        y += dest->height - 1;
        relative_y -= dest->height;
    }
    absolute_relat_y = ABS(relative_y);
    absolute_relat_x = ABS(relative_x);
    for (int i = 0; i < absolute_relat_y && !check_limit(generator, x, y); i++) {
        y += SIGN(relative_y);
        if (generator->map[y][x] == 'X')
            generator->map[y][x] = ' ';
    }
    for (int i = 0; i < absolute_relat_x && !check_limit(generator, x, y); i++) {
        x += SIGN(relative_x);
        if (generator->map[y][x] == 'X')
            generator->map[y][x] = ' ';
    }
}

int check_corridors(list_t *list, generator_t *generator)
{
    node_t *node = list->head;
    room_t *room = node->value;
    room_t *next_room = node->next->value;

    for (int i = 0; i < list->nb_elements; i++) {
        room = node->value;
        next_room = node->next->value;
        dig_corridor(room, next_room, generator);
        node = node->next;
    }
    return (0);
}
