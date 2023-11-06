/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** find the first occurence of a char
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    if (my_strlen(to_find) == 0)
        return str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strncmp(&str[i], to_find, my_strlen(to_find)) == 0) {
            return &str[i];
        }
    }
        return NULL;
}
