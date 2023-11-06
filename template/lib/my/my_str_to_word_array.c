/*
** EPITECH PROJECT, 2023
** str to word array
** File description:
** splits str into words in a array
*/

#include <stdlib.h>
#include "my.h"

int my_char_isalpha(char c)
{
    if ((c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

static void check_words_and_num(char const *str, int *sep, int *word)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((my_char_isalpha(str[i]) == 1 || my_char_isnum(str[i]) == 1)
            && *sep == 1) {
            *word = *word + 1;
            *sep = 0;
        }
        if ((my_char_isalpha(str[i]) == 0 && my_char_isnum(str[i]) == 0))
            *sep = 1;
    }
    return;
}

static void count_letter(char const *str, int which_lettre, int *nbr_lettre)
{
    for (int i = which_lettre; str[i] != '\0'
        && (my_char_isalpha(str[i]) != 0
        || my_char_isnum(str[i]) != 0); i++)
        *nbr_lettre = *nbr_lettre + 1;
}

static void reset_nbr_letter(char const *str,
    int *which_lettre, int *nbr_lettre)
{
    for (; str[*which_lettre] != '\0'
        && my_char_isalpha(str[*which_lettre]) != 1
        && my_char_isnum(str[*which_lettre]) != 1;
        *which_lettre = *which_lettre + 1);
    *nbr_lettre = 0;
}

static char *nbr_sep(char *str)
{
    int nbr_sep = 0;

    for (int i = 0; my_char_isalpha(str[i]) != 1
        && my_char_isnum(str[i]) != 1; i++)
        nbr_sep++;
    return &str[nbr_sep];
}

char **my_str_to_word_array(char const *str)
{
    int word = 0;
    int sep = 1;
    int nbr_lettre = 0;
    int which_lettre = 0;
    char **array_of_word;
    char *string = my_strdup(str);

    string = nbr_sep(string);
    check_words_and_num(str, &sep, &word);
    array_of_word = malloc(sizeof(char *) * (word + 1));
    for (int elem = 0; elem < word; elem++) {
        count_letter(string, which_lettre, &nbr_lettre);
        array_of_word[elem] = malloc(sizeof(char) * (nbr_lettre + 1));
        for (int chara = 0; chara < nbr_lettre; chara++)
            array_of_word[elem][chara] = string[which_lettre++];
        array_of_word[elem][nbr_lettre] = '\0';
        reset_nbr_letter(string, &which_lettre, &nbr_lettre);
    }
    array_of_word[word] = NULL;
    return array_of_word;
}
