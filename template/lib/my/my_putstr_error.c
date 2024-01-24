/*
** EPITECH PROJECT, 2023
** my_putstr_error
** File description:
** Prints a string (str) in stderr
*/

#include "my.h"

int my_putstr_error(char const *str)
{
    if (str == NULL)
        return 84;
    write(2, str, my_strlen(str));
    return 84;
}
