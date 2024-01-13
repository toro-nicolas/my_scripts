/*
** EPITECH PROJECT, 2024
** template
** File description:
** Free an array of words (array)
*/

#include "my.h"

void my_free_word_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
