##
## EPITECH PROJECT, 2023
## Unit tests
## File description:
## The Makefile of the unit tests
##

NAME		=	unit_tests

SRCS		=	../lib/my/my_array_len.c	\
		../lib/my/my_compute_factorial_rec.c	\
		../lib/my/my_compute_power_rec.c		\
		../lib/my/my_compute_square_root.c	\
		../lib/my/my_concat_params.c		\
		../lib/my/my_convert_base.c		\
		../lib/my/my_convert_base_unsigned.c	\
		../lib/my/my_find_prime_sup.c		\
		../lib/my/my_getnbr.c			\
		../lib/my/my_getnbr_base.c		\
		../lib/my/my_isneg.c			\
		../lib/my/my_is_prime.c			\
		../lib/my/my_params_to_array.c		\
		../lib/my/my_print_combn.c		\
		../lib/my/my_print_params.c		\
		../lib/my/my_putnbr.c			\
		../lib/my/my_putchar.c			\
		../lib/my/my_putnbr_base.c		\
		../lib/my/my_putstr.c			\
		../lib/my/my_putstr_error.c		\
		../lib/my/my_putstr_sized.c		\
		../lib/my/my_rev_params.c		\
		../lib/my/my_revstr.c			\
		../lib/my/my_show_param_array.c		\
		../lib/my/my_show_word_array.c		\
		../lib/my/my_showmem.c			\
		../lib/my/my_showstr.c			\
		../lib/my/my_sort_int_array.c		\
		../lib/my/my_sort_params.c		\
		../lib/my/my_str_isalpha.c		\
		../lib/my/my_str_islower.c		\
		../lib/my/my_str_isnum.c			\
		../lib/my/my_str_isprintable.c		\
		../lib/my/my_str_isupper.c		\
		../lib/my/my_str_nbr.c			\
		../lib/my/my_str_nbr_base_unsigned.c	\
		../lib/my/my_str_nbr_base_long_long_int.c\
		../lib/my/my_str_nbr_unsigned.c		\
		../lib/my/my_str_nbr_unsigned_long.c	\
		../lib/my/my_str_nbr_long_long.c		\
		../lib/my/my_str_nbr_size_t.c		\
		../lib/my/my_str_to_word_array.c		\
		../lib/my/my_strcapitalize.c             \
		../lib/my/my_strcat.c                    \
		../lib/my/my_strcmp.c                    \
		../lib/my/my_strcpy.c                    \
		../lib/my/my_strdup.c			\
		../lib/my/my_strlen.c			\
		../lib/my/my_strlowcase.c		\
		../lib/my/my_strncat.c			\
		../lib/my/my_strncmp.c			\
		../lib/my/my_strncpy.c			\
		../lib/my/my_strstr.c			\
		../lib/my/my_strupcase.c			\
		../lib/my/my_swap.c			\
		../lib/my/my_printf/flag_c.c			\
                ../lib/my/my_printf/flag_s.c			\
                ../lib/my/my_printf/flag_d.c			\
                ../lib/my/my_printf/flag_i.c			\
                ../lib/my/my_printf/flag_p.c			\
                ../lib/my/my_printf/flag_o.c			\
                ../lib/my/my_printf/flag_u.c			\
                ../lib/my/my_printf/flag_x.c			\
                ../lib/my/my_printf/flag_bigx.c		\
                ../lib/my/my_printf/flag_e.c			\
                ../lib/my/my_printf/flag_bige.c		\
                ../lib/my/my_printf/flag_f.c			\
                ../lib/my/my_printf/flag_bigf.c		\
                ../lib/my/my_printf/flag_g.c			\
                ../lib/my/my_printf/flag_bigg.c		\
                ../lib/my/my_printf/flag_a.c			\
                ../lib/my/my_printf/flag_biga.c		\
                ../lib/my/my_printf/flag_n.c			\
                ../lib/my/my_printf/flag_b.c			\
                ../lib/my/my_printf/flag_bigs.c		\
                ../lib/my/my_printf/flag_bigd.c		\
	        ../lib/my/my_printf/flag_percent.c		\
		../lib/my/my_printf/find_format.c		\
		../lib/my/my_printf/get_format.c		\
		../lib/my/my_printf/my_show_formating.c	\
		../lib/my/my_printf/sub_format_double.c	\
		../lib/my/my_printf/format_it_int.c		\
		../lib/my/my_printf/format_it_double.c	\
		../lib/my/my_printf/precise_it_int.c		\
		../lib/my/my_printf/precise_it_double.c	\
		../lib/my/my_printf/format_it_str.c		\
		../lib/my/my_printf/format_it_char.c		\
		../lib/my/my_printf/sub_format_int.c		\
		../lib/my/my_printf/sub_format_str.c		\
		../lib/my/my_printf/sub_format_char.c	\
		../lib/my/my_printf/specifier_int.c		\
		../lib/my/my_printf/specifier_base.c		\
		../lib/my/my_printf.c				\

TESTS		=	test_my_printf.c	\
				test_mylib.c		\

CFLAGS		=	-Werror -Wextra -Wpedantic
CFLAGS		+=	-I../include/
CFLAGS		+= 	--coverage -lcriterion -lgcov

LDFLAGS 	=	-L../lib/ -lmy

clean:
	@rm -rf *.gcda
	@rm -rf *.gcno
	@echo -e "\033[1;31mUnit tests deleted.\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@rm -rf ../$(NAME)

libs:
	@make --no-print-directory -C ../lib/my/
	@echo -e "\033[1;33mLibs made.\033[0m"

$(NAME):	fclean libs
	@$(CC) -o $(NAME) $(TESTS) $(SRCS) $(CFLAGS) $(LDFLAGS)
	@cp $(NAME) ../
	@echo -e "\033[1;33mUnit tests created.\033[0m"

tests_run: $(NAME)
	@echo -e "\033[1;32mExecuting unit tests and gcovr...\033[0m"
	@./$(NAME)
