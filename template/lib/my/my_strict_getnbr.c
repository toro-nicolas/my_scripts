/*
** EPITECH PROJECT, 2024
** template
** File description:
** Returns an int number starting from a string number (str) and -1 if the
** string is not an exact positive number
*/

#include "my.h"

int my_strict_getnbr(char const *number)
{
    int nb = 0;

    if (number[0] == '\0')
        return -1;
    for (int index = 0; number[index] != '\0'; index++) {
        if (number[index] < '0' || number[index] > '9')
            return -1;
        else
            nb = nb * 10 + (number[index] - 48);
    }
    return nb;
}
