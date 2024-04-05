/*
** EPITECH PROJECT, 2024
** template
** File description:
** The my_pop_back.c
*/
/**
 * @file my_pop_back.c
 * @brief The my_pop_back.c
 * @author Nicolas TORO
 */

#include "mylist.h"

linked_list_t *my_pop_back(linked_list_t **begin)
{
    linked_list_t *tmp = *begin;

    if (*begin == NULL)
        return NULL;
    for (; tmp->next != NULL; tmp = tmp->next);
    if (tmp->prev != NULL)
        tmp->prev->next = NULL;
    else
        *begin = NULL;
    return tmp;
}
