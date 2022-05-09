/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday04-younes1.bahri
** File description:
** my_getnbr.c
*/

int my_compute_power_rec(int nb, int p);

int my_strlen(const char *p);

int set_result(char str, int count, int *step, long *result)
{
    if (count == 0 || *step == 2) {
        *result = str - 48;
        *step = 1;
    } else {
        *result = *result + ((str - 48) * my_compute_power_rec(10, count));
    }
    return 0;
}

int check_result(char str, int *count, int *step, long *result)
{
    if (*count <= 11) {
        set_result(str, *count, step, result);
        *count++;
    } else {
        *result = 0;
    }
    return 0;
}

int change_stat(char str, long *result, int *count, int *step)
{
    if (str == '-')
        *result = *result * -1;
    if (*step == 1) {
        *step = 2;
        *count = 0;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int size = my_strlen(str);
    int count = 0;
    long result = 0;
    int step = 0;

    for (int i = size; i >= 0; i--) {
        if (str[i] >= '0' && str[i] <= '9') {
            check_result(str[i], &count, &step, &result);
            count++;
        } else {
            change_stat(str[i], &result, &count, &step);
        }
    }
    if (result < -2147483648 || result > 2147483647)
        result = 0;
    return result;
}
