/*
** EPITECH PROJECT, 2023
** my delete nodes
** File description:
** delete node when matching on data_ref
*/

#include "mylist.h"

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int(*cmp)())
{
    linked_list_t *current = *begin;
    linked_list_t *prev = NULL;

    if (cmp((*begin)->data, data_ref) == 0)
        *begin = (*begin)->next;
    else {
        while (current != NULL && (cmp((current)->data, data_ref) != 0)) {
            prev = current;
            (current) = (current)->next;
        }
        if (current == NULL) {
            return 1;
        } else {
            (prev)->next = (current)->next;
            free(current);
        }
    }
    return 0;
}
