/*
** EPITECH PROJECT, 2023
** template
** File description:
** The my_push_back.c
*/

#include "mylist.h"

void my_push_back(linked_list_t **begin, void *data, type_t type)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));
    linked_list_t *tmp = *begin;

    new->data = data;
    new->type = type;
    new->next = NULL;
    if (*begin == NULL) {
        new->prev = NULL;
        *begin = new;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
}