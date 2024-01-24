/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Prints a string (str) in stdout
*/

#include "my.h"

int my_putstr(char const *str)
{
    int len;

    if (str == NULL)
        return 84;
    len = my_strlen(str);
    write(1, str, len);
    return len;
}
