/*
** EPITECH PROJECT, 2023
** my_char_is_num
** File description:
** Returns 1 if the characters (c) is a number or 0 if not
*/

#include "my.h"

int my_char_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
