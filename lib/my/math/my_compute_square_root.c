/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday05-younes1.bahri
** File description:
** my_compute_square_root.c
*/

int calc_quare_root(int nbr)
{
    if (nbr > 2147395600)
        return 0;
    for (int i = 0; i <= nbr; i++) {
        if (nbr == i * i)
            return i;
    }
    return 0;
}

int my_compute_square_root(int nb)
{
    int result = calc_quare_root(nb);

    return result;
}
