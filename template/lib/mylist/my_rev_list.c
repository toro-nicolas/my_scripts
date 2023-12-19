/*
** EPITECH PROJECT, 2023
** my_rev_list
** File description:
** Reverses a linked list
*/

#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *previous_list = NULL;
    linked_list_t *current_list = *begin;
    linked_list_t *next_list = NULL;

    while (current_list != NULL) {
        next_list = current_list->next;
        current_list->next = previous_list;
        current_list->prev = next_list;
        previous_list = current_list;
        current_list = next_list;
    }
    *begin = previous_list;
}
