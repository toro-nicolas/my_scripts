/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print %%
*/

#include "myformats.h"

int flag_percent(va_list liste, formating_t *formating)
{
    write(formating->fd, "%", 1);
    return 1;
}
