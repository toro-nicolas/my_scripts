/*
** EPITECH PROJECT, 2023
** my_putstr_fd
** File description:
** Prints a string (str) in a file descriptor (fd)
*/

#include "my.h"

int my_putstr_fd(char const *str, int fd)
{
    int len;

    if (str == NULL || fd < 0)
        return -84;
    len = my_strlen(str);
    write(fd, str, len);
    return len;
}
