/*
** EPITECH PROJECT, 2023
** my concat list
** File description:
** concat list
*/

#include "mylist.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *node = *begin1;

    while (node->next != NULL) {
        node = node->next;
    }
    node->next = begin2;
}
