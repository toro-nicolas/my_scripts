/*
** EPITECH PROJECT, 2024
** my_free
** File description:
** The my_free.c
*/

#include "mymemory.h"

void my_free(void)
{
    my_malloc(0, 0);
    my_calloc(0, 0, 0);
    my_realloc(NULL, 0, 0);
}
