/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday09-younes1.bahri
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #define is_printable(c) (c > 32 && c < 127) ? 1 : 0

void my_putchar(FILE *fd, char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(FILE *fd, char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
double my_atof(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
void my_showstr(FILE *fd, const char *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int calc_power_rec(int nb, int p, int count, long *result);
int calc_quare_root(int nbr);
int get_prime(int nb);
int get_valid_int(float nb, float i);
int set_result(char str, int count, int *step, long *result);
int check_result(char str, int *count, int *step, long *result);
int change_stat(char str, long *result, int *count, int *step);
int calc_length_for_nbr(char const *p);
int calc_pow(int exp, int base);
int get_valid_integer(float nb, float i);
void print_number(int n);
void print_min_int(void);
int verify_min_int(int number);
int calc_size(const char *p);
int get_length(char *str);
void apply_sort(int *array, int i, int j, int *temp);
int check_alpha(char c);
void check_uppercase(char * c, int * start);
void check_lowercase(char * c, int * start);
void check_specific_char(char * c, int * start);
void check_char(char * c, int * start);
int calc_result(int result);
char *check_if_valid(char *str, char const *to_find, int c);
int check_isalpha(char c);
int get_valid_int(float nb, float i);
int my_put_long(long number);
int my_put_unsigned_nbr(FILE *fd, unsigned int nb);
int my_put_nbr_base_long(FILE *fd, long long nb, char *base);
int my_put_nbr_base(FILE *fd, int nb, char *base);
int check_char_pos(char const *string, char found);
int get_length_long(long nbr);
char *my_strdup(char const *src);
int handler_put_nbr_decimal(FILE *fd, va_list ap, char *arguments);
int handler_put_unsigned_nbr(FILE *fd, va_list ap, char *arguments);
int handler_put_nbr_long(FILE *fd, va_list ap, char *arguments);
int handler_convert_base_binary(FILE *fd, va_list ap, char *argument);
int handler_convert_base_octal(FILE *fd, va_list ap, char *argument);
int handler_convert_base_hexa(FILE *fd, va_list ap, char *argument);
int handler_convert_base_maj_hexa(FILE *fd, va_list ap, char *argument);
int handler_putchar_basic(FILE *fd, va_list ap, char *arguments);
int handler_putchar_percentage(FILE *fd, va_list ap, char *arguments);
int handler_putstr(FILE *fd, va_list ap, char *arguments);
int handler_showstr(FILE *fd, va_list ap, char *arguments);
int my_get_index(char converted_char, char *str);
char *my_convert_base(int nb, char *base);
int my_printf(FILE *fd, const char *format, ...);

#endif
