##
## EPITECH PROJECT, 2023
## Libmy
## File description:
## The Makefile of the libmy
##

NAME    	=	libmy.a

BUILDDIR 	=	../../build

SRCS		=	my_array_len.c		\
			my_char_is_alpha.c			\
			my_char_is_num.c		\
			my_char_is_printable.c		\
			my_compute_factorial_rec.c	\
			my_compute_power_rec.c		\
			my_compute_power_rec_size_t.c	\
			my_compute_square_root.c	\
			my_concat_params.c		\
			my_convert_base.c		\
			my_convert_base_unsigned.c	\
			my_convert_base_size_t.c	\
			my_find_nbr.c		\
			my_find_prime_sup.c		\
			my_find_prime_inf.c		\
			my_fprintf.c			\
			my_free_word_array.c			\
			my_getnbr.c			\
			my_getnbr_base.c		\
			my_getnbr_float.c		\
			my_is_prime.c			\
			my_isneg.c			\
			my_nbrlen.c			\
			my_params_to_array.c		\
			my_print_combn.c		\
			my_print_params.c		\
			my_putnbr.c			\
			my_putchar.c			\
			my_putnbr_base.c		\
			my_putstr.c			\
			my_putstr_error.c		\
			my_putstr_fd.c			\
			my_putstr_sized.c		\
			my_rev_params.c			\
			my_revstr.c			\
			my_round_float_str.c		\
			my_show_param_array.c		\
			my_show_word_array.c		\
			my_showmem.c			\
			my_showstr.c			\
			my_sort_int_array.c		\
			my_sort_params.c		\
			my_strict_find_nbr.c		\
			my_strict_getnbr.c		\
			my_strict_getnbr_float.c		\
			my_str_isalpha.c		\
			my_str_islower.c		\
			my_str_isnum.c			\
			my_str_isprintable.c		\
			my_str_isupper.c		\
			my_str_nbr.c			\
			my_str_nbr_short.c		\
			my_str_nbr_short_short.c	\
			my_str_nbr_base_unsigned.c	\
			my_str_nbr_base_long_long_int.c	\
			my_str_nbr_unsigned.c		\
			my_str_nbr_unsigned_long.c	\
			my_str_nbr_base_unsigned_short.c\
			my_str_nbr_base_unsigned_short_short.c\
			my_str_nbr_base_unsigned_size_t.c\
			my_str_nbr_base_unsigned_long.c	\
			my_str_nbr_long_long.c		\
			my_str_nbr_size_t.c		\
			my_str_to_word_array.c		\
			my_str_to_word_array_select.c	\
			my_strcapitalize.c              \
			my_strcat.c                     \
			my_strcmp.c                     \
			my_strcpy.c                     \
			my_strdup.c			\
			my_strdup_word_array.c		\
			my_strerror.c			\
			my_strlen.c			\
			my_strlowcase.c			\
			my_strncat.c			\
			my_strncmp.c			\
			my_strncpy.c			\
			my_strstr.c			\
			my_strupcase.c			\
			my_super_array.c		\
			my_super_number.c		\
			my_swap.c			\
			my_printf.c			\

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
