/*
** EPITECH PROJECT, 2024
** create_table
** File description:
** Create and return a new hashtable with the hash function (hash)
** and the length (len) given in parameters
*/
/**
 * @file create_table.c
 * @brief The file containing the create_table function
 * @author Nicolas TORO
 */

#include "myhashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hashtable;

    if (hash == NULL || len < 1) {
        my_putstr_error("Error: invalid hashtable.\n");
        return NULL;
    }
    hashtable = malloc(sizeof(hashtable_t));
    hashtable->hash = hash;
    hashtable->len = len;
    hashtable->table = malloc(sizeof(hashtable_entry_t *) * len);
    for (int i = 0; i < len; i++)
        hashtable->table[i] = NULL;
    return hashtable;
}
