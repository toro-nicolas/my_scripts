##
## EPITECH PROJECT, 2023
## Libmylist
## File description:
## The Makefile of the libmylist
##

NAME    	=	libmylist.a

BUILDDIR 	=	../../build

SRCS		=	my_params_to_list.c	\
				my_list_size.c		\
				my_rev_list.c		\
				my_show_list.c		\
				my_apply_on_nodes.c	\
				my_apply_on_matching_nodes.c \
				my_find_node.c 		\
				my_delete_nodes.c	\
				my_concat_list.c	\
				my_sort_list.c		\
				my_strput.c		\
				my_charput.c		\
				my_nbr_put.c		\
				my_data_put.c		\

OBJS		=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

HEADER		=	mylist.h

CFLAGS		=	-Werror -Wall -Wextra -Wpedantic

all:	$(BUILDDIR) $(NAME) copy

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean:	clean
	@rm -rf $(NAME)

re: 	fclean all

copy:
	@mv $(NAME) ../$(NAME)
	@cp $(HEADER) ../../include/$(HEADER)
