/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** Prints a number (nb) in stdout
*/

#include "mylist.h"

static void put_str_nb(int nb, int len_nb)
{
    char nb_str[len_nb];
    int figure_temp = nb;

    for (int i = 0; i < len_nb; i++) {
        nb_str[len_nb - i - 1] = 48 + (figure_temp % 10);
        figure_temp = (figure_temp - (figure_temp % 10)) / 10;
    }
    nb_str[len_nb] = '\0';
    my_strput(nb_str);
}

int my_nbr_put(int nb)
{
    int len_nb = 1;
    int temp_nb = nb;

    if (nb < 0) {
        my_charput('-');
        nb = -nb;
    }
    while ((temp_nb / 10) != 0) {
        len_nb = len_nb + 1;
        temp_nb = temp_nb / 10;
    }
    put_str_nb(nb, len_nb);
    return 0;
}
