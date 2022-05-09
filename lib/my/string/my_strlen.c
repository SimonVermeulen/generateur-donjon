/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday04-younes1.bahri
** File description:
** my_strlen.c
*/

int my_strlen(const char *p)
{
    int c = 0;

    while (*p != '\0') {
        c++;
        *p++;
    }
    return c;
}
