/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday03-younes1.bahri
** File description:
** my_put_nbr.c
*/

void my_putchar(char c);

void print_number_long(long n)
{
    int i;

    if (n > 0) {
        i = n % 10;
        n = n / 10;
        print_number_long(n);
        my_putchar(48 + i);
    }
}

void print_min_long(void)
{
    long max = 223372036854775808;

    my_putchar('9');
    print_number_long(max);
}

int verify_min_long(long number)
{
    if (number == -9223372036854775808) {
        print_min_long();
        return 0;
    }
    return 1;
}

int my_put_long(long number)
{
    int min = verify_min_long(number);

    if (number < 0)
        number = number * -1;
    if (number == 0)
        my_putchar('0');
    if (min == 1)
        print_number_long(number);
    return 0;
}
