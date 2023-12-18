/*
** EPITECH PROJECT, 2023
** my apply on nodes
** File description:
** applies a function to the data of each node
*/

#include "mylist.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    for (linked_list_t *temp = begin; temp != NULL; temp = temp->next)
        f(temp->data);
    return 1;
}
