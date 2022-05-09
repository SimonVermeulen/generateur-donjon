/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** check if the current buff contains a string
*/

int check_string(const char *buff)
{
    int is_quote = 0;
    int len = 0;

    for (; buff[len] && is_quote != 2; len++) {
        if (buff[len] == '"')
            is_quote++;
    }
    if (is_quote == 2)
        return (1);
    return (-1);
}
