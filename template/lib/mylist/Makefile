##
## EPITECH PROJECT, 2023
## Libmylist
## File description:
## The Makefile of the libmylist
##

NAME    	=	libmylist.a

BUILDDIR 	=	../../build

SRCS		=	my_push_front.c			\
				my_push_back.c			\
				my_params_to_list.c		\
				my_show_list.c			\
				my_list_size.c			\
				my_delete_nodes.c		\
				my_delete_list.c		\
				my_rev_list.c			\
				my_find_node.c 			\
				my_concat_list.c		\
				my_sort_list.c			\
				my_add_in_sorted_list.c	\
				my_merge.c				\

OBJS		=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

HEADER		=	mylist.h

CFLAGS		=	-Werror -Wextra -Wpedantic -g3 -L./ -lmy -I../../include

all:	my $(BUILDDIR) $(NAME) copy
	@echo -e "\033[1;33mLibmylist compiled.\033[0m"

my:
	@cp ../my/libmy.a libmy.a
	@cp ../my/my.h my.h

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)
	@echo -e "\033[1;31mLibmylist .o deleted.\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo -e "\033[1;31mLibmylist cleaned.\033[0m"

re: 	fclean all

copy:
	@cp $(NAME) ../$(NAME)
	@cp $(HEADER) ../../include/$(HEADER)
