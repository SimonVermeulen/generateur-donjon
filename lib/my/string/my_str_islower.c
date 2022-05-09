/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-younes1.bahri
** File description:
** my_str_islower.c
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z')
            return 0;
    }
    return 1;
}
