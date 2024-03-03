/*
** EPITECH PROJECT, 2023
** Libmy
** File description:
** The header file of the libmy
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <dirent.h>
#include <signal.h>

#ifndef MY_H_
    #define    MY_H_
    #define    ABS(value) ((value < 0) ? - value : value)
    #define    MAX_INT 2147483647
    #define    MIN_INT -2147483648
    #define    MAX_LONG 9223372036854775807
    #define    MIN_LONG -9223372036854775808
    #define    MAX_SHORT 32767
    #define    MIN_SHORT -32768
    #define    MAX_SHORT_SHORT 127
    #define    MIN_SHORT_SHORT -128
    #define    MAX_SIZE_T 18446744073709551615

extern int my_errno;

typedef enum my_bool {
    FALSE = 0,
    TRUE = 1
} my_bool_t;

struct info_param {
    int length;
    char *str;
    char *copy;
    char **word_array;
};

typedef struct number_settings_s {
    my_bool_t multiple_signe;
    my_bool_t letter_before;
    my_bool_t letter_after;
    my_bool_t overflow;
} number_settings_t;

/* Basics libmy functions */
void my_putchar(char c);
int my_isneg(int nb);
int my_putnbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

/* Advanced libmy functions */
int my_print_combn(int n);
int my_compute_factorial_rec(int nb);
int my_putnbr_base(int nbr, char const *base);
int my_getnbr_base(char const *str, char const *base);
void my_print_params(int argc, char **argv);
void my_rev_params(int argc, char **argv);
void my_sort_params(int argc, char **argv);
char *my_strdup(const char *src);
char *my_concat_params(int argc, char **argv);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char const *str);
char *my_convert_base(char const *nbr,
    char const *base_from, char const *base_to);
char *my_convert_base_unsigned(char const *nbr,
    char const *base_from, char const *base_to);
char *my_convert_base_size_t(char const *nbr,
    char const *base_from, char const *base_to);
struct info_param *my_params_to_array(int ac, char **av);
int my_show_param_array(struct info_param const *par);
int my_array_len(char **array);
int my_putstr_error(char const *str);
int my_putstr_sized(char const *str, int size);
int my_putstr_fd(char const *str, int fd);
size_t my_compute_power_rec_size_t(int nb, int p);
void my_round_float_str(char *float_nb, char last_char, int i, int enable);
int my_printf(char const *format, ...);
int my_fprintf(int fd, char const *format, ...);
int my_char_is_alpha(char const c);
int my_char_is_num(char const c);
int my_char_is_printable(char const c);
int my_find_nbr(char const *str);
float my_getnbr_float(char const *str);
int my_nbrlen(int nb);
int my_strict_find_nbr(char const *number);
int my_strict_getnbr(char const *number);
float my_strict_getnbr_float(char const *str);
char **my_str_to_word_array_select(char const *str, char const *separator);
char **my_super_array(char *str, char *sep);
void my_free_word_array(char **array);
int my_find_prime_inf(int nb);
const char *my_strerror(int error);
char **my_strdup_word_array(char **array);
int my_super_number(char *number, number_settings_t settings);

/* my_str_nbr functions */
char *my_str_nbr(int nb);
char *my_str_nbr_short(short int nb);
char *my_str_nbr_short_short(signed char nb);
char *my_str_nbr_base_unsigned(unsigned int nbr, char const *base);
char *my_str_nbr_base_unsigned_short(unsigned short nbr, char const *base);
char *my_str_nbr_base_unsigned_short_short(unsigned char nbr,
    char const *base);
char *my_str_nbr_base_unsigned_size_t(size_t nbr, char const *base);
char *my_str_nbr_base_unsigned_long(unsigned long nbr, char const *base);
char *my_str_nbr_base_long_long_int(long long int nbr, char const *base);
char *my_str_nbr_unsigned(unsigned int nb);
char *my_str_nbr_unsigned_long(unsigned long int nb);
char *my_str_nbr_long_long(long long nb);
char *my_str_nbr_size_t(size_t nb);

#endif /* MY_H_ */
