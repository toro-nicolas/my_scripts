/*
** EPITECH PROJECT, 2024
** hash
** File description:
** The functions for hash a word (key) with the len of the hashtable (len)
*/
/**
 * @file hash.c
 * @brief The file containing the hash functions
 * @author Nicolas TORO
 */

#include "myhashtable.h"

int hash_simple(char *key, int len)
{
    int hash = 0;

    for (int index = 0; key[index] != '\0'; index++)
        hash += key[index] * key[index];
    return hash;
}

int hash_djb2(char *key, int len)
{
    int hash = 5381;

    for (int index = 0; key[index] != '\0'; index++)
        hash = ((hash << 5) + hash) + key[index];
    return ABS(hash);
}

int hash_p256(char *key, int len)
{
    int hash = 0;
    int multiplier = 1;

    for (int index = 0; key[index] != '\0'; index++) {
        hash += key[index] * multiplier;
        multiplier *= 256;
    }
    hash += multiplier * len;
    return ABS(hash);
}

int hash(char *key, int len)
{
    int hash_value = 0;

    for (int i = 0; key[i] != '\0'; i++)
        hash_value = hash_value ^ key[i] * 3907;
    return ABS(hash_value);
}
