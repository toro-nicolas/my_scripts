/*
** EPITECH PROJECT, 2023
** my_concat_list
** File description:
** Concatenates two linked lists
*/

#include "mylist.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *tmp = *begin1;

    if (*begin1 == NULL) {
        *begin1 = begin2;
        return;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = begin2;
    begin2->prev = tmp;
}
