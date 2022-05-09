/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-younes1.bahri
** File description:
** my_putnbr_base.c
*/

void my_putchar(char c);

void convert_base_value(int hex, char const * base)
{
    my_putchar(base[hex]);
}

void print_to_base(unsigned long nbr, char const * base, int length)
{
    int hex = 0;
    long i = 1;

    if (nbr != 0) {
        hex = (nbr % length);
        nbr = nbr / length;
        print_to_base(nbr, base, length);
        convert_base_value(hex, base);
    }
}

int my_putnbr_base(unsigned long nbr, char const *base)
{
    long i;

    for (i = 0; base[i] != '\0'; i++);
    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * -1;
    }
    print_to_base(nbr, base, i);
    return 0;
}
