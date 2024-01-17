/*
** EPITECH PROJECT, 2024
** my_malloc
** File description:
** The my_malloc.c
*/

#include "mymemory.h"

void *my_malloc(size_t size, int type)
{
    static linked_list_t *list = NULL;
    void *ptr;

    if (type == 1 && size > 0) {
        ptr = malloc(size);
        if (ptr == NULL)
            return NULL;
        my_push_front(&list, ptr, VOID);
        return ptr;
    }
    if (type == 0)
        my_delete_list(&list);
    return NULL;
}
