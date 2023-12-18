/*
** EPITECH PROJECT, 2023
** my_print_params
** File description:
** Prints all the arguments (argc and argv)
*/

#include "my.h"

void my_print_params(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putstr("\n");
    }
}
