/*
** EPITECH PROJECT, 2023
** template
** File description:
** The my_char_is_num.c
*/

#include "my.h"

int my_char_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
