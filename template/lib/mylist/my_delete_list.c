/*
** EPITECH PROJECT, 2023
** template
** File description:
** The my_delete_list.c
*/

#include "mylist.h"

void my_delete_list(linked_list_t **begin)
{
    linked_list_t *tmp = *begin;
    linked_list_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        free(tmp->data);
        free(tmp);
        tmp = next;
    }
    *begin = NULL;
}