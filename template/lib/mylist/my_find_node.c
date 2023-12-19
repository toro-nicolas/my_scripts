/*
** EPITECH PROJECT, 2023
** template
** File description:
** The my_find_node.c
*/

#include "mylist.h"

linked_list_t *my_find_node(linked_list_t const *begin, void const *data_ref,
    int (*cmp) ())
{
    for (linked_list_t *tmp = (linked_list_t *)begin; tmp != NULL; tmp =
        tmp->next) {
        if (cmp(tmp->data, data_ref) == 0)
            return tmp;
    }
    return NULL;
}