/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets the buffer
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "json_parser.h"

static size_t get_size(char *path)
{
    FILE *fd = fopen(path, "r");
    size_t total_size = 0;
    size_t size = 0;
    size_t len = 0;
    char *line = NULL;

    while ((len = getline(&line, &size, fd)) != (size_t) -1)
        total_size += len;
    free(line);
    fclose(fd);
    return (total_size);
}

char *get_buffer(char *path)
{
    char *buffer = NULL;
    size_t size = 0;
    int fd = 0;

    if (!path)
        return (NULL);
    fd = open(path, O_RDONLY);
    if (fd < 0) {
        write(2, "Error: can't find file\n", 24);
        return (NULL);
    }
    size = get_size(path) + 1;
    buffer = malloc(sizeof(char) * size);
    if (!buffer)
        return (NULL);
    read(fd, buffer, size);
    buffer[size - 1] = '\0';
    close(fd);
    return (buffer);
}
