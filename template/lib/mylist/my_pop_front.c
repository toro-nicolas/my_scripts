/*
** EPITECH PROJECT, 2024
** template
** File description:
** The my_pop_front.c
*/
/**
 * @file my_pop_front.c
 * @brief The my_pop_front.c
 * @author Nicolas TORO
 */

#include "mylist.h"

linked_list_t *my_pop_front(linked_list_t **begin)
{
    linked_list_t *tmp = *begin;

    if (*begin == NULL)
        return NULL;
    *begin = (*begin)->next;
    if (*begin != NULL)
        (*begin)->prev = NULL;
    return tmp;
}
