/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Prints a string (str) in stdout
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 84;
    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i = i + 1;
    }
    return 0;
}
