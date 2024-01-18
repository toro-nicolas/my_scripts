/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** Returns the previous prime number starting form a number (nb)
*/

#include "my.h"

int my_find_prime_inf(int nb)
{
    int i = 0;

    if (nb <= 1)
        return -1;
    while (my_is_prime(nb - i) == 0)
        i++;
    return nb - i;
}
