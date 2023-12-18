/*
** EPITECH PROJECT, 2023
** my_putstr_error
** File description:
** Prints a string (str) in stderr
*/

#include "my.h"

int my_putstr_error(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 84;
    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i = i + 1;
    }
    return 84;
}
