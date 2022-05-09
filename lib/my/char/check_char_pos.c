/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** check_char_pos.c
*/

int check_char_pos(char const *string, char found)
{
    for (int i = 0; string[i] != '\0'; i++)
        if (string[i] == found)
            return i;
    return -1;
}
