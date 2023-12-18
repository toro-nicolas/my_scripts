/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Returns 0 if the strings (s1 and s2) are identical,
** otherwise it returns the difference
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}
