/*
** EPITECH PROJECT, 2024
** my_str_contains
** File description:
** Returns 1 if the string (str) contains at least one character from the
** char list (char_list), 0 otherwise
*/

#include "my.h"

int my_str_contains(char *str, char *char_list)
{
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; char_list[j] != '\0'; j++) {
            if (str[i] == char_list[j])
                return 1;
        }
    }
    return 0;
}
