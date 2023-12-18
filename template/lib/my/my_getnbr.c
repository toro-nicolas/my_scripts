/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** get str in number
*/

#include "my.h"

static int index_negative(char const *str, int index, int index_neg)
{
    if (str[index - 1] == '-')
        index_neg = (-1);
    return index_neg;
}

int my_getnbr(char const *str)
{
    int convert = 0;
    int index = 0;
    int index_neg = 1;
    int index_int = 0;

    if (my_strcmp(str, "-2147483648") == 0)
        return -2147483648;
    if ((str[0] < '0' || str[0] > '9') && str[0] != '-')
        return 0;
    while (str[index] < '0' || str[index] > '9')
        index++;
    index_neg = index_negative(str, index, index_neg);
    while (str[index] >= '0' && str[index] <= '9') {
        convert = convert * 10 + (str[index] - 48);
        index++;
        index_int++;
        if (index_int > 10)
            convert = 0;
    }
    return index_neg * convert;
}
