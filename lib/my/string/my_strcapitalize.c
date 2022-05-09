/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-younes1.bahri
** File description:
** my_strcapitalize.c
*/

void check_uppercase(char *c, int *start)
{
    if (*start == 1) {
        *start = 0;
    } else {
        *c = *c + 32;
    }
}

void check_lowercase(char *c, int *start)
{
    if (*start == 1) {
        *c = *c - 32;
        *start = 0;
    }
}

void check_specific_char(char *c, int *start)
{
    if (*c >= '0' && *c <= '9') {
        *start = 0;
    } else {
        *start = 1;
    }
}

void check_char(char *c, int *start)
{
    if (*c >= 'A' && *c <= 'Z') {
        check_uppercase(c, start);
    } else if (*c >= 'a' && *c <= 'z') {
        check_lowercase(c, start);
    } else {
        check_specific_char(c, start);
    }
}

char *my_strcapitalize(char *str)
{
    int start = 1;

    for (int i = 0; str[i] != '\0'; i++)
        check_char(&str[i], &start);
}
