/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %c (a char)
*/

#include "myformats.h"

int flag_c(va_list list, formating_t *formating)
{
    char temp = va_arg(list, int);
    char str[2] = {0};
    char str_finale[100] = {0};

    str[0] = temp;
    my_strcat(str_finale, str);
    format_it_char(str_finale, formating, temp);
    return my_putstr_fd(str_finale, formating->fd);
}
