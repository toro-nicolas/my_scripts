/*
** EPITECH PROJECT, 2023
** my show list
** File description:
** print a list
*/

#include "mylist.h"

int my_show_list(linked_list_t *liste)
{
    linked_list_t *copy = liste;
    int compteur = 0;
    int end = 0;

    while (end == 0) {
        my_strput((char *)copy->data);
        if (copy->next == NULL)
            end = 1;
        copy = copy->next;
        compteur++;
    }
    return compteur;
}
