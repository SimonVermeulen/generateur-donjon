/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** checks if the current buff contains an array
*/

int check_array(const char *buff)
{
    if (buff[0] && buff[0] == '[')
        return (1);
    return (0);
}
