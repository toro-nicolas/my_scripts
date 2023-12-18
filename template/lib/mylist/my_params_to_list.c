/*
** EPITECH PROJECT, 2023
** my params to linked list
** File description:
** my params to linked list
*/

#include "mylist.h"

int push_front(linked_list_t **cabine, void *data)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = data;
    element->next = *cabine;
    *cabine = element;
    return 1;
}

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *cabine = NULL;

    for (int i = 0; i < ac; i++)
        push_front(&cabine, av[i]);
    return cabine;
}
