/*
** EPITECH PROJECT, 2021
** template
** File description:
** check_isalpha.c
*/

int check_isalpha(char c)
{
    if (c < 'A' || c > 'z')
        return 0;
    if (c > 'Z' && c < 'a')
        return 0;
    return 1;
}
