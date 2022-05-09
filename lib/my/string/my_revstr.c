/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-younes1.bahri
** File description:
** my_revstr.c
*/

int my_strlen(const char *p);

char *my_revstr(char *str)
{
    int size = my_strlen(str) - 1;
    char result[size];

    result[size + 1] = '\0';
    for (int i = 0; i < size + 1; i++)
        result[i] = str[size - i];
    for (int i = 0; i < size + 1; i++)
        str[i] = result[i];
    return str;
}
