/*
** EPITECH PROJECT, 2023
** Libmylist
** File description:
** The header file of the libmylist
*/

#include "my.h"

#ifndef MYLIST_H
    #define MYLIST_H

typedef enum type {
    SHORT_SHORT,
    SHORT,
    INT,
    LONG,
    LONG_LONG,
    UNSIGNED_SHORT,
    UNSIGNED_SHORT_SHORT,
    UNSIGNED_INT,
    UNSIGNED_LONG,
    UNSIGNED_LONG_LONG,
    SIZE_T,
    FLOAT,
    DOUBLE,
    CHAR,
    STRING,
    ARRAY_OF_STRING,
    VOID
} type_t;

typedef struct linked_list {
    struct linked_list *prev;
    void *data;
    type_t type;
    struct linked_list *next;
} linked_list_t;

void my_push_front(linked_list_t **begin, void *data, type_t type);
void my_push_back(linked_list_t **begin, void *data, type_t type);
linked_list_t *my_params_to_list(int ac, char *const *av);
void my_show_list(linked_list_t *liste);
int my_list_size(linked_list_t const *begin);
int my_delete_nodes(linked_list_t **begin,
    void const *data_ref, int (*cmp) ());
void my_delete_list(linked_list_t **begin);
void my_rev_list(linked_list_t **begin);
linked_list_t *my_find_node(linked_list_t const *begin,
    void const *data, int (*cmp) ());
void my_concat_list(linked_list_t **begin1, linked_list_t *begin2);
void my_sort_list(linked_list_t **begin, int (*cmp) ());
void my_add_in_sorted_list(linked_list_t **begin,
    void *data, int (*cmp) ());
void my_merge(linked_list_t **begin1,
    linked_list_t *begin2, int (*cmp) ());

#endif
