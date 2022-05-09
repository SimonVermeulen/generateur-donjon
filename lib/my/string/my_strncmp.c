/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-younes1.bahri
** File description:
** my_strncmp.c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int result = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
        i++;
    result = s1[i] - s2[i];
    return (result);
}
