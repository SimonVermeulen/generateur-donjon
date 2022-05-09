/*
** EPITECH PROJECT, 2021
** lib_my
** File description:
** converts and print a decimal int to a given base
*/

#include <stdlib.h>
#include "my.h"

static int my_get_len(int nb, char *base)
{
    int base_len = my_strlen(base);
    int converted_len = 0;

    for (;nb != 0; converted_len++)
        nb /= base_len;
    return (converted_len);
}

static void convert_decimal_to_base(int nb, char *base, char *result, int i)
{
    int base_len = my_strlen(base);

    if (nb < 0)
        nb = -nb;
    i++;
    if (nb / base_len != 0)
        convert_decimal_to_base((nb / base_len), base, result, i);
    result[i] = base[nb % base_len];
}

static void apply_char(char *str, char *base, int i)
{
    if (i + 1 >= 7 && (my_get_index(str[i - 1], base) - 1) >= 0)
        str[i + 1] = base[my_get_index(str[i + 1], base) - 1];
}

static char *two_complements(char *str, char *base)
{
    int base_len = my_strlen(base);
    int index_char = 0;

    my_revstr(str);
    for (int i = 0; i < 8; i++)
        str[i] = base[(my_strlen(base) - 1) - my_get_index(str[i], base)];
    for (int j = 7; j >= 0; j--) {
        index_char = my_get_index(str[j], base);
        if (index_char + 1 < base_len) {
            str[j] = base[index_char + 1];
            apply_char(str, base, j);
            str[8] = '\0';
            return (str);
        }
    }
    str[8] = '\0';
    return (str);
}

char *my_convert_base(int nb, char *base)
{
    char *converted_str = NULL;
    int len = my_get_len(nb, base);

    converted_str = malloc(sizeof(char) * 9);
    if (converted_str == NULL)
        return (NULL);
    converted_str = my_strdup("00000000\0");

    convert_decimal_to_base(nb, base, converted_str, -1);
    if (nb >= 0) {
        converted_str[len] = '\0';
        my_revstr(converted_str);
    } else if (nb < 0) {
        two_complements(converted_str, base);
    }
    return (converted_str);
}
