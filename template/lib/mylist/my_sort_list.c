/*
** EPITECH PROJECT, 2023
** my_sort_list
** File description:
** Sorts a linked list
*/

#include "mylist.h"

static void check_swap(linked_list_t **list, int (*cmp) ())
{
    void *tmp;

    if ((*list)->prev != NULL && cmp((*list)->prev->data, (*list)->data) > 0) {
        tmp = (*list)->prev->data;
        (*list)->prev->data = (*list)->data;
        (*list)->data = tmp;
    }
}

void my_sort_list(linked_list_t **begin, int (*cmp) ())
{
    for (linked_list_t *list1 = *begin; list1 != NULL; list1 = list1->next) {
        for (linked_list_t *list2 = (*begin)->next;
        list2 != NULL; list2 = list2->next) {
            check_swap(&list2, cmp);
        }
    }
}
