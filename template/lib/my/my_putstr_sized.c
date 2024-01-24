/*
** EPITECH PROJECT, 2023
** my_putstr_limited
** File description:
** Prints a string (str) in stdout
** with a defined size (size)
*/

#include "my.h"

int my_putstr_sized(char const *str, int size)
{
    if (str == NULL || size < 1)
        return 84;
    write(1, str, size);
    return size;
}
