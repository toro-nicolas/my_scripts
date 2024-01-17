/*
** EPITECH PROJECT, 2024
** my_memset
** File description:
** The my_memset.c
*/

#include "mymemory.h"

void *my_memset(void *pointer, int value, size_t size)
{
    if (pointer == NULL)
        return NULL;
    for (size_t i = 0; i < size; i++)
        ((char *)pointer)[i] = value;
    return pointer;
}
