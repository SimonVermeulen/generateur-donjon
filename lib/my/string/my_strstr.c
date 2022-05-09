/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-younes1.bahri
** File description:
** my_strstr.c
*/

char *check_if_valid(char *str, char const *to_find, int c)
{
    int b = 0;

    while (str[c] == to_find[b]) {
        c++;
        b++;
        if (to_find[b] == 0)
            return (char *)(&str[c - b]);
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    char * result;

    if (to_find == 0)
        return str;
    for (int i = 0; str[i] != '\0'; i++) {
        result = check_if_valid(str, to_find, i);
        if (result != 0)
            return result;
    }
    return 0;
}
