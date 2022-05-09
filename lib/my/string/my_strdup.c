/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday08-younes1.bahri
** File description:
** my_strdup.c
*/
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *result;
    int size;

    if (!src)
        return NULL;
    for (size = 0; src[size] != '\0'; size++);
    result = malloc(sizeof(char) * (size + 1));
    if (result == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
        result[i] = src[i];
    result[size] = '\0';
    return result;
}
