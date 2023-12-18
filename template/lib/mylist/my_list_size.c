/*
** EPITECH PROJECT, 2023
** my list size
** File description:
** taille de liste*
*/

#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int size = 0;

    while (begin != NULL) {
        size++;
        begin = begin->next;
    }
    return size;
}
