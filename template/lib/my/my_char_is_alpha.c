/*
** EPITECH PROJECT, 2023
** my_char_is_alpha
** File description:
** Returns 1 if the characters (c) is alphabetical or 0 if not
*/

#include "my.h"

int my_char_is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}
