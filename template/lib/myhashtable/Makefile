##
## EPITECH PROJECT, 2023
## Libmyhastable
## File description:
## The Makefile of the libmyhashtable
##

NAME    	=	libmyhashtable.a

CC		=	gcc

BUILDDIR 	=	../../build

SRCS		=	create_table.c
SRCS		+=	delete.c
SRCS		+=	destroy_table.c
SRCS		+=	dump.c
SRCS		+=	hash.c
SRCS		+=	insert.c
SRCS		+=	search.c

OBJS		=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

HEADER		=	myhashtable.h

CFLAGS		=	-Werror -Wextra -Wpedantic -g3 -L./ -lmy -I../../include
DEBUGFLAGS	=	-g3
OPTIMIZEFLAGS	=	-O3

.PHONY: all my debug clean fclean re copy

all:	my $(BUILDDIR) $(NAME) copy
	@echo -e "\033[1;33mLibmyhashtable compiled.\033[0m"

my:
	@cp ../my/libmy.a libmy.a
	@cp ../my/my.h my.h

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(BUILDDIR)
	@$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUGFLAGS)
debug: OPTIMIZEFLAGS =
debug: all

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
