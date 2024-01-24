/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %i (an int)
*/

#include "myformats.h"

int flag_i(va_list list, formating_t *formating)
{
    size_t temp = va_arg(list, size_t);
    char *str_finale = specify_it_int(formating, temp);

    precise_it_int(str_finale, formating, temp);
    format_it_int(str_finale, formating, temp);
    return my_putstr_fd(str_finale, formating->fd);
}
