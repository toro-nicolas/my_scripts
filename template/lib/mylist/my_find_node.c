/*
** EPITECH PROJECT, 2023
** my find node*
** File description:
** find node that returns the adress of the frist node
*/

#include "mylist.h"

linked_list_t *my_find_node(linked_list_t const *begin,
    void const *data, int (*cmp) ())
{
    linked_list_t const *node_match = begin;

    while (node_match != NULL) {
        if (cmp(node_match->data, data) == 0)
            return (linked_list_t *)node_match;
        node_match = node_match->next;
    }
    return NULL;
}
