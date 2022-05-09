/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday05-younes1.bahri
** File description:
** my_compute_power_rec.c
*/

int calc_power_rec(int nb, int p, int count, long *result)
{
    if (count < p) {
        *result = *result * nb;
        count++;
        calc_power_rec(nb, p, count, result);
    }
}

int my_compute_power_rec(int nb, int p)
{
    long result = nb;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    calc_power_rec(nb, p, 1, &result);
    if (result < -2147483648 || result > 2147483647)
        result = 0;
    return result;
}
