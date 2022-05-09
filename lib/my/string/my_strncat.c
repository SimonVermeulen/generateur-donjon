/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday07-younes1.bahri
** File description:
** my_strncat.c
*/

int my_strlen(const char *p);

char *my_strncat(char *dest, char const *src, int nb)
{
    int size = my_strlen(dest);

    for (int i = 0; i < nb && src[i] != '\0'; i++, size++)
        dest[size] = src[i];
    dest[size] = '\0';
    return dest;
}
