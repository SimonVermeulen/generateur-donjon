/*
** EPITECH PROJECT, 2022
** generator
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "generator.h"
#include "linked_list.h"
#include "json_parser.h"
#include "my.h"

static char *my_allocated_strca(const char *src1, const char *src2)
{
    char *result = NULL;
    int i = 0;
    int j = 0;

    result = malloc(sizeof(char) * (my_strlen(src1) + my_strlen(src2) + 1));
    if (!result)
        return (NULL);
    for (; src1[i]; i++)
        result[i] = src1[i];
    for (; src2[j]; j++)
        result[i + j] = src2[j];
    result[i + j] = '\0';
    return (result);
}

generator_t *fill_generator(char **av)
{
    generator_t *generator = malloc(sizeof(generator_t));
    list_t *list = launch_parsing(av[1]);
    int *map_size = NULL;

    if (!generator)
        return (NULL);
    generator->rooms_size = get_value_list(list, "rooms_size", 30);
    map_size = get_value_list(list, "map_size", 3);
    generator->map_size = *map_size;
    map_size = get_value_list(list, "nb_rooms", 3);
    generator->nb_rooms = *map_size;
    map_size = get_value_list(list, "nb_floors", 3);
    generator->nb_floors = *map_size;
    generator->stair_is_set = 0;
    generator->map = NULL;

    return (generator);
}

static void set_items(list_t *list, generator_t *generator)
{
    node_t *current = list->head;
    room_t *room = NULL;

    
}

static void set_stairs(list_t *list, generator_t *generator, int max)
{
    node_t *current = list->head;
    room_t *room = NULL;
    int room_index = rand() % list->nb_elements;
    int stair_x = 0;
    int stair_y = 0;
    static int index = 0;

    for (int i = 0; i < room_index; i++)
        current = current->next;
    room = current->value;

    stair_x = room->x + 1 + (rand() % room->width - 1);
    stair_y = room->y + 1 + (rand() % room->height - 1);
    index++;
    if (index != max)
        generator->map[stair_y][stair_x] = 'R';
    else
        generator->map[stair_y][stair_x] = '0';
    generator->stair_is_set = room_index;
}

static void set_player(list_t *list, generator_t *generator)
{
    node_t *current = list->head;
    room_t *room = NULL;
    int room_index = rand() % list->nb_elements;
    int player_x = 0;
    int player_y = 0;

    while (room_index == generator->stair_is_set)
        room_index = rand() % list->nb_elements;
    for (int i = 0; i < room_index; i++)
        current = current->next;
    room = current->value;

    player_x = room->x + 1 + (rand() % room->width - 1);
    player_y = room->y + 1 + (rand() % room->height - 1);
    generator->map[player_y][player_x] = 'P';
    generator->map[player_y][player_x + 1] = 'A';
}

list_t *generate_floor(generator_t *generator)
{
    list_t *list = create_empty_list();
    list_t *result = create_empty_list();
    room_t *room = NULL;
    char *floor_name = NULL;
 
    for (int j = 0; j < generator->nb_floors; j++) {
        if (fill_default_map(generator))
            return (1);
        list = create_empty_list();
        floor_name = my_allocated_strca("floor_", my_convert_base(j, "0123456789"));
        if (j == 0)
            floor_name = "floor_0";
        for (int i = 0; i < generator->nb_rooms; i++) {
            room = malloc(sizeof(room_t));
            if (!room)
                return (1);
            set_room_size(room, generator);
            create_add_node(room, 1, "room", list, 1);
        }
        dig_room(list, generator);
        check_corridors(list, generator);
        set_stairs(list, generator, generator->nb_floors);
        set_player(list, generator);
        create_add_node(generator->map, 40, floor_name, result, generator->map_size);
    }
    printf("list->nb_elements = %d\n", list->nb_elements);
    return (result);
}

int main(int ac, char **av)
{
    generator_t *generator = fill_generator(av);

    srand(time(NULL));

    launch_writing(generate_floor(generator), "./result.json", 0);
    return (0);
}
