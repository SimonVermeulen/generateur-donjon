/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** checks if the current buff contains an object
*/

int check_object(const char *buff)
{
    if (buff[0] && buff[0] == '{')
        return (1);
    return (0);
}
