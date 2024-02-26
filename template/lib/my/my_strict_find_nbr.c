/*
** EPITECH PROJECT, 2024
** my_strict_find_nbr
** File description:
** Returns an int number starting from a string number (number) and -1 if the
** string is not an exact positive number
*/

#include "my.h"

int my_strict_getnbr(char const *number)
{
    int nb = 0;
    int start = 0;

    if (number[0] == '\0')
        return -1;
    for (int index = 0; number[index] != '\0'; index++) {
        if (number[index] != '0')
            start = index;
        if (nb < 0 || number[index] < '0' || number[index] > '9' ||
        (index > start + 8 && number[start] != '1' && number[start] != '2'))
            return nb;
        nb = nb * 10 + (number[index] - 48);
    }
    return nb;
}

