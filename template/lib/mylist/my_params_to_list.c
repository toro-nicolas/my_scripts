/*
** EPITECH PROJECT, 2023
** my_params_to_list
** File description:
** Creates a linked list from the arguments (argc and argv)
*/

#include "mylist.h"

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    list->prev = NULL;
    list->data = my_strdup(av[0]);
    list->type = STRING;
    list->next = NULL;
    for (int arg = 1; arg < ac; arg++)
        my_push_front(&list, my_strdup(av[arg]), STRING);
    return list;
}
