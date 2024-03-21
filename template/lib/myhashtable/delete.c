/*
** EPITECH PROJECT, 2024
** ht_delete
** File description:
** Delete an entry in the hashtable (ht) in function of the key (key)
*/

#include "myhashtable.h"

static void remove_hashtable_entry(hashtable_entry_t **begin,
    hashtable_entry_t *tmp)
{
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    else
        *begin = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    FREE(tmp->value);
    FREE(tmp);
}

int search_delete_in_hashtable_entry(hashtable_entry_t **entry, int key)
{
    hashtable_entry_t *tmp = *entry;
    hashtable_entry_t *next = NULL;
    int result = 0;

    if (*entry == NULL)
        return 0;
    while (tmp != NULL) {
        next = tmp->next;
        if (tmp->key == key) {
            remove_hashtable_entry(entry, tmp);
            result = 1;
        }
        tmp = next;
    }
    return result;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int result = 84;
    int key_code;
    int index;

    if (ht == NULL || key == NULL)
        return 84;
    key_code = ht->hash(key, ht->len);
    index = key_code % ht->len;
    if (search_delete_in_hashtable_entry(&ht->table[index], key_code))
        result = 0;
    return result;
}
