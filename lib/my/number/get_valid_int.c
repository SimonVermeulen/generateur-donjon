/*
** EPITECH PROJECT, 2021
** template
** File description:
** get_valid_int.c
*/

int get_valid_int(float nb, float i)
{
    int nb_int = nb / i;
    float nb_float = nb / i;
    float calc = nb_float - nb_int;

    if (calc > 0)
        return 0;
    return 1;
}
