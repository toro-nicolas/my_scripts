/*
** EPITECH PROJECT, 2024
** my_memchr
** File description:
** The my_memchr.c
*/

#include "mymemory.h"

void *my_memchr(const void *memory_block, int searched_char, size_t size)
{
    if (memory_block == NULL)
        return NULL;
    for (size_t index = 0; index < size; index++) {
        if (((char *)memory_block)[index] == searched_char)
            return (void *)&((char *)memory_block)[index];
    }
    return NULL;
}
