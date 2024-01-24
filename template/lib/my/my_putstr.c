/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Write a string (str) in stdout
** and returns the length of the printed string
*/

#include "my.h"

int my_putstr(char const *str)
{
    int len;

    if (str == NULL)
        return 0;
    len = my_strlen(str);
    write(1, str, len);
    return len;
}
