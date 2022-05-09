/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-younes1.bahri
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
