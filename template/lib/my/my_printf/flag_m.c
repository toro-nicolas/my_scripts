/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %m (an errno) | Disable
*/

#include "myformats.h"

/* Old flag_m */
/*int flag_m(va_list list, formating_t *formating)
{
    my_putstr(strerror(errno));
    return my_strlen(strerror(errno));
}*/
int flag_m(va_list list, formating_t *formating)
{
    return my_putstr_fd(my_strerror(errno), formating->fd);
}
