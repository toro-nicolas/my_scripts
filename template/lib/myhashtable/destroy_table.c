/*
** EPITECH PROJECT, 2024
** delete_hashtable
** File description:
** Delete a hashtable (ht)
*/
/**
 * @file destroy_table.c
 * @brief The file containing the delete_hashtable function
 * @author Nicolas TORO
 */

#include "myhashtable.h"

static void delete_hashtable_entry(hashtable_entry_t **begin)
{
    hashtable_entry_t *tmp = *begin;
    hashtable_entry_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        FREE(tmp->value);
        FREE(tmp);
        tmp = next;
    }
    *begin = NULL;
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    for (int index = 0; index < ht->len; index++)
        delete_hashtable_entry(&ht->table[index]);
    FREE(ht->table);
    FREE(ht);
}
