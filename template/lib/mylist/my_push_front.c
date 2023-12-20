/*
** EPITECH PROJECT, 2023
** my_push_front
** File description:
** Adds a node at the beginning of a linked list
*/

#include "mylist.h"

void my_push_front(linked_list_t **begin, void *data, type_t type)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));

    new->prev = NULL;
    new->data = data;
    new->type = type;
    new->next = *begin;
    if (*begin != NULL)
        (*begin)->prev = new;
    *begin = new;
}
