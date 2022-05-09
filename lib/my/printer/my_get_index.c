/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** gets the index of a given char in a string
*/

int my_get_index(char converted_char, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (converted_char == str[i] || converted_char == '\0')
            return (i);
    return (-1);
}
