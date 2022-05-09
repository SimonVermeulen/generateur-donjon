/*
** EPITECH PROJECT, 2022
** generator
** File description:
** generator
*/

#include "linked_list.h"

#ifndef GENERATOR_H_
    #define GENERATOR_H_
    #define OFFSET  5
    #define ABS(c) (c < 0) ? -c : c
    #define SIGN(c) (c < 0) ? -1 : 1

    typedef struct generator_s {
        int map_size;
        int nb_rooms;
        int stair_is_set;
        int *rooms_size;
        char **map;
        int nb_floors;
    } generator_t;

    typedef struct room_s {
        int x;
        int y;
        int width;
        int height;
    } room_t;

void set_room_size(room_t *room, generator_t *generator);

void dig_room(list_t *list, generator_t *generator);

int check_corridors(list_t *list, generator_t *generator);

int fill_default_map(generator_t *generator);

#endif /* !GENERATOR_H_ */
