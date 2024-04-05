/*
** EPITECH PROJECT, 2024
** my_pop_list
** File description:
** Return the last node of a linked list and remove it from the list
*/

#include "mylist.h"

static void change_list(linked_list_t **begin, linked_list_t *tmp)
{
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    else
        *begin = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
}

linked_list_t *my_pop_node(linked_list_t **begin,
    void const *data_ref, int (*cmp) ())
{
    linked_list_t *tmp = *begin;
    linked_list_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        if ((cmp == NULL && tmp->data == data_ref)
        || (cmp != NULL && cmp(tmp->data, data_ref) == 0)) {
            change_list(begin, tmp);
            return tmp;
        }
        tmp = next;
    }
    return NULL;
}
