/*
** EPITECH PROJECT, 2024
** my_calloc
** File description:
** The my_calloc.c
*/

#include "mymemory.h"

void *my_calloc(size_t element_count, size_t element_size, int type)
{
    static linked_list_t *list = NULL;
    void *ptr;

    if (type == 1 && element_count > 0 && element_size > 0) {
        ptr = malloc(element_count * element_size);
        if (ptr == NULL)
            return NULL;
        my_push_front(&list, ptr, VOID);
        my_memset(ptr, 0, element_count);
        return ptr;
    }
    if (type == 0)
        my_delete_list(&list);
    return NULL;
}
