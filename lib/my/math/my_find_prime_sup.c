/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday05-younes1.bahri
** File description:
** my_find_prime_sup.c
*/

int get_valid_int(float nb, float i);

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int result = 0;
    long count = nb;

    if (count < 0)
        count = 0;
    while (1) {
        if (count >= 2147483647)
            return 0;
        if (my_is_prime(count) == 1)
            return count;
        count++;
    }
}
