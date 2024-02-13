/*
** EPITECH PROJECT, 2024
** Libmymemory
** File description:
** The header file of the libmymemory
*/

#include "mylist.h"

#ifndef MYMEMORY_H_
    #define MYMEMORY_H_

void *my_calloc(size_t element_count, size_t element_size, int type);
void my_free(void);
void *my_malloc(size_t size, int type);
char *my_malloc_strdup(char const *src);
char **my_malloc_strdup_word_array(char **array);
void *my_memchr(const void *memory_block, int searched_char, size_t size);
void *my_memcpy(void *destination, const void *source, size_t size);
int my_memcmp(const void *pointer1, const void *pointer2, size_t size);
void *my_memmove(void *destination, const void *source, size_t size);
void *my_memset(void *pointer, int value, size_t size);
void *my_realloc(void *pointer, size_t size, int type);

#endif /* MYMEMORY_H_ */
