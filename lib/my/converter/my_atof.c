/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-younes1.bahri
** File description:
** my_atoF
*/

#include "my.h"

static int get_decimal_size(const char *line)
{
    int size = 0;

    for (; line[size] && (line[size] >= '0' && line[size] <= '9'); size++);
    return (size);
}

static double get_dividend(int index)
{
    double result = 10;

    for (int i = 1; i < index; i++)
        result *= 10;
    return (result);
}

static double get_decimal_value(const char *line, int sign)
{
    double result = 0;
    int siz = 0;
    int j = 0;

    siz = get_decimal_size(line);
    for (int i = 0; i < siz; i++, j++)
        result += (line[j] - 48.0) / get_dividend(i + 1);
    result = (sign == 1) ? -result : result;
    return (result);
}

double my_atof(const char *line)
{
    int preDecimal = 0;
    double result = 0;
    int sign = 0;
    int i = 0;

    result += (double) my_getnbr(line);
    for (; line[i] && line[i] != '.'; i++);
    if (result < 0)
        sign = 1;
    result += get_decimal_value(&line[i + 1], sign);
    return (result);
}
