/*
** EPITECH PROJECT, 2024
** my_strict_find_nbr
** File description:
** Returns an int number starting from a string number (number) and -1 if the
** string is not an exact positive number
*/

#include "my.h"

int my_strict_find_nbr(char const *number)
{
    int nb = -1;
    int start = -1;

    if (number[0] == '\0')
        return -1;
    for (int index = 0; number[index] != '\0'; index++) {
        if (start == -1 && number[index] >= '1' && number[index] <= '9') {
            start = index;
            nb = 0;
        }
        if (nb < -1 || number[index] < '0' || number[index] > '9' ||
        (index > start + 8 && number[start] != '1' && number[start] != '2'))
            return nb;
        nb = nb * 10 + (number[index] - 48);
    }
    return nb;
}
