/*
** EPITECH PROJECT, 2023
** my concat list
** File description:
** concat list
*/

#include "mylist.h"

void sorting_l(linked_list_t **ref, linked_list_t **rest,
    char *temp, int(*cmp) ())
{
    if (cmp((*ref)->data, (*rest)->data) > 0) {
        temp = (*ref)->data;
        (*ref)->data = (*rest)->data;
        (*rest)->data = temp;
    }
}

void my_sort_list(linked_list_t **begin, int (*cmp) ())
{
    linked_list_t *ref = *begin;
    linked_list_t *rest = NULL;
    char *temp = " ";

    for (; ref->next != NULL; ref = ref->next) {
        for (rest = ref->next; rest != NULL; rest = rest->next) {
            sorting_l(&ref, &rest, temp, *cmp);
        }
    }
    for (; (*begin) != NULL; (*begin) = (*begin)->next)
        my_strput((*begin)->data);
}
