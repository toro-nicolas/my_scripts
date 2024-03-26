/*
** EPITECH PROJECT, 2023
** my_str_nbr_base_long_long_int
** File description:
** Returns the strings conversion of
** an unsigned number (nbr) in specific base (base)
*/
/**
 * @file my_str_nbr_base_long_long_int.c
 * @brief The file containing the my_str_nbr_base_long_long_int function
 * @author Nicolas TORO
 */

#include "my.h"

static char *put_str_nb(long long int nb, int len_nb,
    char const *base, int base_len)
{
    char *nb_str = malloc(sizeof(char) * (len_nb + 1));
    long long int figure_temp = nb;

    for (int i = 0; i < len_nb; i++) {
        nb_str[len_nb - i - 1] = base[figure_temp % base_len];
        figure_temp = (figure_temp - (figure_temp % base_len)) / base_len;
    }
    nb_str[len_nb] = '\0';
    return nb_str;
}

char *my_str_nbr_base_long_long_int(long long int nbr, char const *base)
{
    int len_nb = 1;
    long long int temp_nb = nbr;
    int base_len = 0;

    while (base[base_len] != '\0') {
        base_len = base_len + 1;
    }
    while ((temp_nb / base_len) != 0) {
        len_nb = len_nb + 1;
        temp_nb = temp_nb / base_len;
    }
    return put_str_nb(nbr, len_nb, base, base_len);
}
