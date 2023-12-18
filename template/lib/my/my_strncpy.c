/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** Copy a string (src) and paste it on another string (dest)
** with a defined size (n)
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = my_strlen(src);

    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    if (len < n) {
        dest[len] = '\0';
    }
    return dest;
}
