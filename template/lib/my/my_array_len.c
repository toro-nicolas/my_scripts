/*
** EPITECH PROJECT, 2023
** my_array_len
** File description:
** Returns the lengths of an array which finish with a NULL value (array)
*/

#include "my.h"

int my_array_len(char **array)
{
    int len = 0;

    while (array[len] != NULL)
        len = len + 1;
    return len;
}
