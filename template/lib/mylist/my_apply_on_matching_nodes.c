/*
** EPITECH PROJECT, 2023
** my apply on matching nodes
** File description:
** applies a function to nodes on the list equal to the data ref given
*/

#include "mylist.h"

int my_apply_on_matching_nodes(linked_list_t *begin, int(*f)(),
    void const *data_ref, int (*cmp) ())
{
    linked_list_t *current = begin;

    for (; current != NULL; current = current->next) {
        if (cmp(current->data, data_ref) == 0)
            f(current->data);
    }
    return 1;
}
