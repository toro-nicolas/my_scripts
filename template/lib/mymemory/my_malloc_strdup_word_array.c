/*
** EPITECH PROJECT, 2024
** template
** File description:
** The my_strdup_word_array.c
*/

#include "mymemory.h"

char **my_malloc_strdup_word_array(char **array)
{
    char **new_array;
    int i = 0;

    if (array == NULL)
        return (NULL);
    new_array = my_malloc(sizeof(char *) * (my_array_len(array) + 1), 1);
    for (; array[i] != NULL; i++)
        new_array[i] = my_malloc_strdup(array[i]);
    new_array[i] = NULL;
    return new_array;
}
