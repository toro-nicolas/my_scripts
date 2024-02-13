/*
** EPITECH PROJECT, 2024
** template
** File description:
** The my_strdup_word_array.c
*/

#include "my.h"

char **my_strdup_word_array(char **array)
{
    char **new_array;
    int i = 0;

    if (array == NULL)
        return (NULL);
    new_array = malloc(sizeof(char *) * (my_array_len(array) + 1));
    for (; array[i] != NULL; i++)
        new_array[i] = my_strdup(array[i]);
    new_array[i] = NULL;
    return new_array;
}
