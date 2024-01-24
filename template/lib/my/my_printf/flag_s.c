/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %s (a string)
*/

#include "myformats.h"

int flag_s(va_list list, formating_t *formating)
{
    char *temp = va_arg(list, char *);
    char temp2[5000] = {0};

    my_strcat(temp2, temp);
    format_it_str(temp2, formating);
    return my_putstr_fd(temp2, formating->fd);
}
