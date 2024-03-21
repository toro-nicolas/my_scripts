/*
** EPITECH PROJECT, 2024
** my_free_ptr
** File description:
** Free a pointer (ptr) and set it to NULL
*/

#include "my.h"

void my_free_ptr(void *ptr)
{
    if (ptr == NULL)
        return;
    free(ptr);
    ptr = NULL;
}
