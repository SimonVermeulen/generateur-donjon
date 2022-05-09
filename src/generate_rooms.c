/*
** EPITECH PROJECT, 2022
** generator
** File description:
** generate_rooms
*/

#include <stdio.h>
#include "generator.h"
#include "linked_list.h"

static void choose_size(room_t *room, generator_t *generator)
{
    int room_type = rand() % 3;
    int min_width = generator->rooms_size[room_type * 4];
    int max_width = generator->rooms_size[room_type * 4 + 1];
    int min_height = generator->rooms_size[room_type * 4 + 2];
    int max_height = generator->rooms_size[room_type * 4 + 3];

    room->height = (rand() % (max_height - min_height + 1)) + min_height;
    room->width = (rand() % (max_width - min_width + 1)) + min_width;
}

void set_room_size(room_t *room, generator_t *generator)
{
    int max_map = generator->map_size - OFFSET;
    int min_map = 0 + OFFSET;

    choose_size(room, generator);
    room->x = (rand() % (max_map - min_map + 1) + min_map);
    room->y = (rand() % (max_map - min_map + 1) + min_map);
    if (room->y + room->height > max_map || room->x + room->width > max_map)
        set_room_size(room, generator);
}

void dig_room(list_t *list, generator_t *generator)
{
    node_t *node = list->head;
    room_t *room = node->value;

    for (int i = 0; i < list->nb_elements; i++) {
        room = node->value;        
        for (int j = room->y; j < room->y + room->height; j++) {
            for (int k = room->x; k < room->x + room->width; k++) {
                generator->map[j][k] = ' ';
            }
        }
        node = node->next;
    }
}
