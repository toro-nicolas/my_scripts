/*
** EPITECH PROJECT, 2023
** [project-name]
** File description:
** The main file of the project
*/

#include "../include/mylist.h"

int main(int argc, char **argv)
{
    linked_list_t *list = my_params_to_list(argc, argv);
    my_show_list(list);
    my_printf("List size: %d\n", my_list_size(list));
    my_rev_list(&list);
    my_sort_list(&list, &my_strcmp);
    my_show_list(list);
    my_delete_list(&list);
    return 0;
}
