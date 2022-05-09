/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday05-younes1.bahri
** File description:
** my_is_prime.c
*/

int get_valid_int(float nb, float i);

int my_is_prime(int nb)
{
    if (nb <= 0 || nb == 1)
        return 0;
    for (int i = 2; i < nb; i++) {
        if (i != nb && get_valid_int(nb, i) == 1)
            return 0;
    }
    return 1;
}
