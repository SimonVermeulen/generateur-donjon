/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-younes1.bahri
** File description:
** my_strcmp.c
*/

int my_strlen(const char *p);

int calc_result_strcmp(int result)
{
    if (result > 0)
        return 1;
    if (result < 0)
        return -1;
    if (result == 0)
        return 0;
}

int check_size_strcmp(int a, int b)
{
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int nbr_1 = my_strlen(s1);
    int nbr_2 = my_strlen(s2);
    int calc;

    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        calc = calc_result_strcmp(s1[i] - s2[i]);
        if (calc != 0)
            return calc;
    }
    return check_size_strcmp(nbr_1, nbr_2);
}
