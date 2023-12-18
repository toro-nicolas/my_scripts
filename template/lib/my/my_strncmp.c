/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** Returns 0 if the strings (s1 and s2) are identical,
** otherwise it returns the difference
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] < s2[i])
            return s1[i] - s2[i];
        if (s1[i] > s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}
