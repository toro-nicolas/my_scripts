/*
** EPITECH PROJECT, 2024
** template
** File description:
** The my_free_ptr.c
*/

#include "my.h"

void my_free_ptr(void *ptr)
{
    if (ptr == NULL)
        return;
    free(ptr);
    ptr = NULL;
}
