/*
** EPITECH PROJECT, 2023
** my_list_size
** File description:
** Returns the size of a linked list
*/

#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int nb = 0;

    for (; begin != NULL; nb++)
        begin = begin->next;
    return nb;
}
