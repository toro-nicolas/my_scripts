/*
** EPITECH PROJECT, 2024
** my_memcmp
** File description:
** The my_memcmp.c
*/

#include "mymemory.h"

int my_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
    if (pointer1 == NULL || pointer2 == NULL)
        return 0;
    for (size_t index = 0; index < size; index++) {
        if (((char *)pointer1)[index] != ((char *)pointer2)[index])
            return ((char *)pointer1)[index] - ((char *)pointer2)[index];
    }
    return 0;
}
