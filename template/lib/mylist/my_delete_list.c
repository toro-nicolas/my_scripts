/*
** EPITECH PROJECT, 2023
** delete_list
** File description:
** Deletes a linked list
*/

#include "mylist.h"

void my_delete_list(linked_list_t **begin)
{
    linked_list_t *tmp = *begin;
    linked_list_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        if (tmp->data != NULL && tmp->type != UNKNOWN)
            FREE(tmp->data);
        FREE(tmp);
        tmp = next;
    }
    *begin = NULL;
}
