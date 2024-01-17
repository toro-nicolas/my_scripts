##
## EPITECH PROJECT, 2023
## Libmyhastable
## File description:
## The Makefile of the libmyhashtable
##

NAME    	=	libmyhashtable.a

BUILDDIR 	=	../../build

SRCS		=	hash.c			\
			create_table.c		\
			destroy_table.c		\
			insert.c		\
			delete.c		\
			search.c		\
			dump.c			\

OBJS		=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

HEADER		=	myhashtable.h

CFLAGS		=	-Werror -Wextra -Wpedantic -L./ -lmy -I../../include

all:	my $(BUILDDIR) $(NAME) copy
	@echo -e "\033[1;33mLibmyhashtable compiled.\033[0m"

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
	@echo -e "\033[1;31mLibmyhashtable .o deleted.\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo -e "\033[1;31mLibmyhashtable cleaned.\033[0m"

re: 	fclean all

copy:
	@cp $(NAME) ../$(NAME)
	@cp $(HEADER) ../../include/$(HEADER)
