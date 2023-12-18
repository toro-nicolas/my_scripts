/*
** EPITECH PROJECT, 2023
** rev list
** File description:
** reverse order of list elements
*/

#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *current = *begin;
    linked_list_t *rev = NULL;

    while (current != NULL) {
        push_front(&rev, current->data);
        current = current->next;
    }
    *begin = rev;
}
