##
## EPITECH PROJECT, 2023
## Libmymemory
## File description:
## The Makefile of the libmymemory
##

NAME    	=	libmymemory.a

BUILDDIR 	=	../../build

SRCS		=	my_calloc.c		\
			my_free.c		\
			my_malloc.c		\
			my_malloc_strdup.c		\
			my_malloc_strdup_word_array.c	\
			my_memchr.c		\
			my_memcpy.c		\
			my_memcmp.c		\
			my_memmove.c		\
			my_memset.c		\
			my_realloc.c		\

OBJS		=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

HEADER		=	mymemory.h

CFLAGS		=	-Werror -Wextra -Wpedantic -g3
CFLAGS		+=	-L./ -lmylist -lmy -I../../include

all:	my $(BUILDDIR) $(NAME) copy
	@echo -e "\033[1;33mLibmymemory compiled.\033[0m"

my:
	@cp ../my/libmy.a libmy.a
	@cp ../my/my.h my.h
	@cp ../mylist/libmylist.a libmylist.a
	@cp ../mylist/mylist.h mylist.h

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)
	@echo -e "\033[1;31mLibmymemory .o deleted.\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo -e "\033[1;31mLibmymemory cleaned.\033[0m"

re: 	fclean all

copy:
	@cp $(NAME) ../$(NAME)
	@cp $(HEADER) ../../include/$(HEADER)
