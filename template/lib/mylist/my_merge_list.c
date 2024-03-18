/*
** EPITECH PROJECT, 2023
** my_merge_list
** File description:
** Merges two linked lists
*/

#include "mylist.h"

void my_merge_list(linked_list_t **begin1, linked_list_t *begin2, int (*cmp)())
{
    if (*begin1 == NULL) {
        *begin1 = begin2;
        return;
    }
    for (linked_list_t *tmp = begin2; tmp != NULL; tmp = tmp->next) {
        if (my_find_node(*begin1, tmp->data, cmp) == NULL)
            my_push_back(begin1, tmp->data, tmp->type);
    }
}
