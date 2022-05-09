/*
** EPITECH PROJECT, 2021
** linked_list
** File description:
** includes all the prototypes of my linked lists
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

/*---------------STRUCT---------------*/

/**
* @brief The node who forms the linked list
* @details
* - prev : the previous node
* - next : the next node
* - type : the type of the current value contained in node
* - len : the nb of elements of the current value (if it's an array)
* - key : the key linked to the current node
* - value : the value of the current node
*/
typedef struct node_s {
    struct node_s *prev;
    struct node_s *next;
    int type;
    int len;
    char *key;
    void *value;
} node_t;

/**
* @brief The linked list composed by node_s structs
* @details
* circular double linked list
* - head : the head of the list
* - nb_elements : the nb_elements
*/
typedef struct list_s {
    node_t *head;
    int nb_elements;
} list_t;

/*----------------LIST----------------*/

/**
* @brief Create and allocate an empty linked_list
*
* @return list_t * the allocated empty list
*/
list_t *create_empty_list(void);

/**
* @brief Deletes and free each node of the linked_list
*
* @param list the list to delete
*/
void free_list(list_t *list);

/*---------------ELEMENT--------------*/

/**
* @brief Adds a node at the end of a given list
*
* @param list the list where to add a node
* @param data the node to add
* @return int 0 or -1 in case of error
*/
int push_element(list_t *list, node_t *data);

/**
* @brief Adds a node at the begining of a given list
*
* @param list the list where to add a node
* @param data the node to add
* @return int 0 or -1 in case of error
*/
int unshift_element(list_t *list, node_t *data);

/**
* @brief Deletes the last element of a given list
*
* @param list the list to delete an element from
* @return int 0 or -1 in case of error
*/
int pop_element(list_t *list);

/**
* @brief Deletes the first element of a given liven
*
* @param list the list to delete an element from
* @return int 0 or -1 in case of error
*/
int shift_element(list_t *list);

/**
* @brief Create an empty_node to fill
*
* @return node_t * the empty node created and allocated
*/
node_t *create_emptynode(void);

/**
* @brief Create a newnode object from value + type + len
*
* @param value the value of the node
* @param type the type of the node
* @param len the len of the node if it's an array
* @return node_t * the node created
*/
node_t *create_newnode(void *value, int type, int len);

/**
* @brief Deletes the node in list at the given index
*
* @param list the list where to destroy the node
* @param index the index where to destroy the node
*/
void splice(list_t *list, int index);

/**
* @brief Free the given node
*
* @param node the node to delete
*/
void free_node(node_t *node);

/**
* @brief searches a node from a given key
*
* @param list the list where to search the node
* @param key the key we need to find
* @return node_t * NULL if not found or the node we are looking for
*/
node_t *search_from_key(list_t *list, const char *key);

void *get_value_list(list_t *list, const char *name, int type);

int set_value_list(list_t *list, const char *name, void *value);

node_t *create_add_node(void *value, int type, const char *name, list_t *list, int len);

node_t *get_node_id(list_t *list, int id);

#endif
