/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-younes1.bahri
** File description:
** my_strncpy.c
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
