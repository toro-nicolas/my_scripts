/*
** EPITECH PROJECT, 2023
** my_find_nbr
** File description:
** Find the first number (nb) in a string
*/

#include "my.h"

static int add_number(int *error, int *signe, int result, char c)
{
    if ((*signe == 1 && (size_t)((result * 10) + (c - 48)) >= 2147483648) ||
    (*signe == -1 && (size_t)((result * 10) + (c - 48)) >= 2147483649)) {
        *error = 1;
        return 0;
    }
    if (result != 0)
        result = (result * 10) + (c - 48);
    else
        result = c - 48;
    return result;
}

static void char_to_int(int *letter_detected, char c, int *signe)
{
    if (c == '-')
        *signe = - *signe;
    else if (c == '+')
        return;
    else
        *letter_detected = 1;
}

static int check_result(int result, int *error, int *signe)
{
    if (*error == 1)
        result = 0;
    else
        result = result * *signe;
    return result;
}

int my_find_nbr(char const *str)
{
    int result = 0;
    int len = my_strlen(str);
    int i = 0;
    int signe = 1;
    int letter_detected = 0;
    int error = 0;

    while (letter_detected == 0 && error == 0 && i < len) {
        if (str[i] >= '0' && str[i] <= '9')
            result = add_number(&error, &signe, result, str[i]);
        else
            char_to_int(&letter_detected, str[i], &signe);
        i++;
    }
    return check_result(result, &error, &signe);
}
