/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** en gros ça devient une string
*/

#include "mylist.h"

int my_strput(char const *str)
{
    if (str == NULL) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        my_charput(str[i]);
    }
    return 0;
}
