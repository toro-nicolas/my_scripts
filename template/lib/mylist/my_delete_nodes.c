/*
** EPITECH PROJECT, 2023
** my_delete_nodes
** File description:
** Deletes nodes from a linked list
*/

#include "mylist.h"

static void remove_node(linked_list_t **begin, linked_list_t *tmp)
{
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    else
        *begin = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    free(tmp->data);
    free(tmp);
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp) ())
{
    linked_list_t *tmp = *begin;
    linked_list_t *next = NULL;
    int nodes_deleted = 0;

    while (tmp != NULL) {
        next = tmp->next;
        if (cmp(tmp->data, data_ref) == 0) {
            remove_node(begin, tmp);
            nodes_deleted++;
        }
        tmp = next;
    }
    return nodes_deleted;
}
