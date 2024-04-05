##
## EPITECH PROJECT, 2023
## Libmy
## File description:
## The Makefile of the libmy
##

NAME    	=	libmy.a

BUILDDIR 	=	../../build

SRCS		+=	my_array_len.c
SRCS		+=	my_char_is.c
SRCS		+=	my_char_is_alpha.c
SRCS		+=	my_char_is_num.c
SRCS		+=	my_char_is_printable.c
SRCS		+=	my_compute_factorial_rec.c
SRCS		+=	my_compute_power_rec.c
SRCS		+=	my_compute_power_rec_size_t.c
SRCS		+=	my_compute_square_root.c
SRCS		+=	my_concat_params.c
SRCS		+=	my_convert_base.c
SRCS		+=	my_convert_base_size_t.c
SRCS		+=	my_convert_base_unsigned.c
SRCS		+=	my_count_letter.c
SRCS		+=	my_find_nbr.c
SRCS		+=	my_find_prime_sup.c
SRCS		+=	my_find_prime_inf.c
SRCS		+=	my_fprintf.c
SRCS		+=	my_free_array.c
SRCS		+=	my_free_ptr.c
SRCS		+=	my_getnbr.c
SRCS		+=	my_getnbr_base.c
SRCS		+=	my_getnbr_float.c
SRCS		+=	my_is_prime.c
SRCS		+=	my_isneg.c
SRCS		+=	my_nbrlen.c
SRCS		+=	my_params_to_array.c
SRCS		+=	my_print_combn.c
SRCS		+=	my_print_params.c
SRCS		+=	my_printf.c
SRCS		+=	my_putnbr.c
SRCS		+=	my_putchar.c
SRCS		+=	my_putnbr_base.c
SRCS		+=	my_putstr.c
SRCS		+=	my_putstr_error.c
SRCS		+=	my_putstr_fd.c
SRCS		+=	my_putstr_fd_free.c
SRCS		+=	my_putstr_sized.c
SRCS		+=	my_rev_params.c
SRCS		+=	my_revstr.c
SRCS		+=	my_round_float_str.c
SRCS		+=	my_show_param_array.c
SRCS		+=	my_show_word_array.c
SRCS		+=	my_showmem.c
SRCS		+=	my_showstr.c
SRCS		+=	my_sort_int_array.c
SRCS		+=	my_sort_params.c
SRCS		+=	my_str_contains.c
SRCS		+=	my_str_is.c
SRCS		+=	my_str_isalpha.c
SRCS		+=	my_str_islower.c
SRCS		+=	my_str_isnum.c
SRCS		+=	my_str_isprintable.c
SRCS		+=	my_str_isupper.c
SRCS		+=	my_str_nbr.c
SRCS		+=	my_str_nbr_base_long_long_int.c
SRCS		+=	my_str_nbr_base_unsigned.c
SRCS		+=	my_str_nbr_base_unsigned_long.c
SRCS		+=	my_str_nbr_base_unsigned_short.c
SRCS		+=	my_str_nbr_base_unsigned_short_short.c
SRCS		+=	my_str_nbr_base_unsigned_size_t.c
SRCS		+=	my_str_nbr_long_long.c
SRCS		+=	my_str_nbr_short.c
SRCS		+=	my_str_nbr_short_short.c
SRCS		+=	my_str_nbr_size_t.c
SRCS		+=	my_str_nbr_unsigned.c
SRCS		+=	my_str_nbr_unsigned_long.c
SRCS		+=	my_str_to_word_array.c
SRCS		+=	my_str_to_word_array_select.c
SRCS		+=	my_str_to_word_array_string.c
SRCS		+=	my_strcapitalize.c
SRCS		+=	my_strcat.c
SRCS		+=	my_strcmp.c
SRCS		+=	my_strcpy.c
SRCS		+=	my_strdup.c
SRCS		+=	my_strdup_word_array.c
SRCS		+=	my_strerror.c
SRCS		+=	my_strict_find_nbr.c
SRCS		+=	my_strict_getnbr.c
SRCS		+=	my_strict_getnbr_float.c
SRCS		+=	my_strlen.c
SRCS		+=	my_strlowcase.c
SRCS		+=	my_strncat.c
SRCS		+=	my_strncmp.c
SRCS		+=	my_strncpy.c
SRCS		+=	my_strndup.c
SRCS		+=	my_strstr.c
SRCS		+=	my_strupcase.c
SRCS		+=	my_super_array.c
SRCS		+=	my_super_number.c
SRCS		+=	my_swap.c

OBJS		=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))
OBJS		+=	$(wildcard ../../build/*.o)

HEADER		=	my.h

CFLAGS		=	-Werror -Wall -Wextra -Wpedantic -g3

all:	my-printf create-build $(BUILDDIR) $(NAME) copy
	@echo -e "\033[1;33mLibmy compiled.\033[0m"

my-printf:
	@make --no-print-directory -C ./my_printf/

create-build:
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)
	@echo -e "\033[1;31mLibmy .o deleted.\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo -e "\033[1;31mLibmy cleaned.\033[0m"

re: 	fclean all

copy:
	@cp $(NAME) ../$(NAME)
	@cp $(HEADER) ../../include/$(HEADER)
