/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday04-younes1.bahri
** File description:
** my_sort_int_array.c
*/

void apply_sort(int *array, int i, int j)
{
    int temp;

    if (array[i] > array[j]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++)
            apply_sort(array, i, j);
    }
}
