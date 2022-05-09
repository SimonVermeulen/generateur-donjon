/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday04-younes1.bahri
** File description:
** my_swap.c
*/

void my_swap(int *a, int *b)
{
    int lasta = *a;
    int lastb = *b;

    *a = lastb;
    *b = lasta;
}
