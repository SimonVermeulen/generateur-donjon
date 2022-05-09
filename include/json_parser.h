/*
** EPITECH PROJECT, 2021
** JSONPARSER
** File description:
** json include file
*/

#ifndef JSON_PARSER_H_
    #define JSON_PARSER_H_

    #include <stdio.h>
    #include "linked_list.h"

    #define is_number(c) (c >= '0' && c <= '9') ? 1 : 0

    #define is_printable(c) (c > 32 && c < 127) ? 1 : 0

/*****************PARSING*****************/

/**
* @brief launches the parsing of the file at the given path
*
* @param path the path to the file
* @return list_t * the list with all data parsed
*/
list_t *launch_parsing(char *path);

/**
* @brief Get the content of the JSON file at path
*
* @param path the path to the JSON file
* @return char * Content of the JSON file
*/
char *get_buffer(char *path);

/**
* @brief Stringifies the JSON content
*
* @param buffer the buffer to stringify
* @return int 1 if error 0 if no error
*/
int stringify(char **buffer);

/**
* @brief Extracts the data from the given stringify buffer
*
* @param buffer the stringified buffer you need to extract the data from
* @return list_t * the data extracted stocked in a linked list
*/
list_t *get_data(char *buffer);

/*----------TYPE_CHECKERS-----------*/

/**
* @brief gets the type of the current index of the buffer in the node tmp.
* @details
* - 1 if it's an object
* - 2 if it's a double
* - 3 if it's an int
* - 4 if it's a string
* type* 10 if it's an array
*
* @param buff the stringified buffer to check
*
* @param tmp the node to fill with the type
*/
void check_type(const char *buff, node_t *tmp);

/**
* @brief check if the data at the current index of buffer is an array in JSON
*
* @param buff the buffer to check
* @return int 1 if it's an array 0 if not
*/
int check_array(const char *buff);

/**
* @brief check if the data at the current index of buffer is an object in JSON
*
* @param buff the buffer to check
* @return int 1 if it's an object 0 if not
*/
int check_object(const char *buff);

/**
* @brief check if the data at the current index of buffer is a double in JSON
*
* @param buff the buffer to check
* @return int 1 if it's a double 0 if not
*/
int check_double(const char *buff);

/**
* @brief check if the data at the current index of buffer is an int in JSON
*
* @param buff the buffer to check
* @return int 1 if it's an int 0 if not
*/
int check_int(const char *buff);

/**
* @brief check if the data at the current index of buffer is a string in JSON
*
* @param buff the buffer to check
* @return int 1 if it's a string 0 if not
*/
int check_string(const char *buff);

/*----------VALUE_GETTERS-----------*/

/**
* @brief Gets the value contained at the given index of
* buffer and stocks it in tmp
*
* @param buffer the buffer to get the value from
* @param index the current index to get value from
* @param tmp the node to stock value in
* @return int the index after reading the value
*/
int get_value(const char *buffer, int index, node_t *tmp);

/**
* @brief Get the key of the current data in buffer
*
* @param buffer the buffer to get the key from
* @param index the current index to get key from
* @param tmp the node to stock value in
* @return int the index after reading the value
*/
int get_key(const char *buffer, int index, node_t *tmp);

/**
* @brief Get the array from the current index of buffer
*
* @param buffer the buffer to get the array values from
* @param index the current index to get the array values from
* @param tmp the node to stock the array in
* @return int the index after reading the array values
*/
int get_array(const char *buff, node_t *new_node, int nb_elements);

/**
* @brief Get the object from the current index of buffer
*
* @param buffer the buffer to get the object values from
* @param index the current index to get the object values from
* @param tmp the node to stock the object in
* @return int the index after reading the object
*/

int get_object(const char *buff, node_t *new_node, int nb_elements);

/**
* @brief Get the double from the current index of buffer
*
* @param buffer the buffer to get the double from
* @param index the current index to get the double from
* @param tmp the node to stock the double in
* @return int the index after reading the double
*/
int get_double(const char *buff, node_t *new_node, int nb_elements);

/**
* @brief Get the int from the current index of buffer
*
* @param buffer the buffer to get the int from
* @param index the current index to get the int from
* @param tmp the node to stock the int in
* @return int the index after reading the int
*/
int get_int(const char *buff, node_t *new_node, int nb_elements);

/**
* @brief Get the string from the current index of buffer
*
* @param buffer the buffer to get the string from
* @param index the current index to get the string from
* @param tmp the node to stock the string in
* @return int the index after reading the string
*/
int get_string(const char *buff, node_t *new_node, int nb_elements);

/*****************WRITING*****************/

/**
* @brief launches the save of the json object
* 
* @param list the json_object to save
* @param path the path you want the list to be saved to
* @param type the type of save you want (1 pour rajouter à la fin du fichier) (0 to replace file)
* @return int returns 1 if error or 0
*/
int launch_writing(list_t *list, char *path, int type);

int launch_loop(list_t *list, FILE *fd);

int double_writer(FILE *fd, node_t *node);

int integer_writer(FILE *fd, node_t *node);

int object_writer(FILE *fd, node_t *node);

int string_writer(FILE *fd, node_t *node);

void put_comma(int index, int len, FILE *fd);

/*****************UTILS*****************/

/**
* @brief frees a json object
*
* @param object the list_t containing the json object to free
* @param recursive 1 for recursive 0 elseway
* @return int 0 if no problems 1 if error
*/
int free_json_object(list_t *object);

/**
* @brief copies a json_object
*
* @param src the source json_object
* @return list_t * the copied json_object (NULL if error)
*/
list_t *copy_list(list_t *src);

/**
* @brief chooses the good copy_function to launch
*
* @param src the source value
* @param dest the dest value
* @return int 0 if no errors -1 if error
*/
int copy_value(node_t *src, node_t *dest);

/**
* @brief copies a double from src value to dest value
*
* @param src the source value
* @param dest the dest value
* @return int 0 if no errors -1 if error
*/
int copy_double(node_t *src, node_t *dest);

/**
* @brief copies an int from src value to dest value
*
* @param src the source value
* @param dest the dest value
* @return int 0 if no errors -1 if error
*/
int copy_int(node_t *src, node_t *dest);

/**
* @brief copies a string from src value to dest value
*
* @param src the source value
* @param dest the dest value
* @return int 0 if no errors -1 if error
*/
int copy_string(node_t *src, node_t *dest);



#endif
