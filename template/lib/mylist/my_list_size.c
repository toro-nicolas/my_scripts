/*
** EPITECH PROJECT, 2023
** template
** File description:
** The my_list_size.c
*/

#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int nb = 0;

    for (; begin != NULL; nb++)
        begin = begin->next;
    return nb;
}