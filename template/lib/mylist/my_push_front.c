/*
** EPITECH PROJECT, 2023
** template
** File description:
** The my_push_front.c
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