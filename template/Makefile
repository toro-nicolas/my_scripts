##
## EPITECH PROJECT, 2023
## [project-name]
## File description:
## The main Makefile of our project
##

NAME		=	[project-exec]

BUILDDIR 	=	./build
SRCDIR		=	./src

SRCS        +=  main.c \

OBJS     	=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

CFLAGS		=	-Werror -Wextra -Wpedantic -g3
CFLAGS		+=	-I./include/

LDFLAGS 	=	-L./lib/ -lmy

all: create-build libs $(BUILDDIR) $(NAME)

libs:
	@make -C./lib/my/

create-build:
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	@rm -rf $(BUILDDIR)

fclean: clean
	rm -rf ./lib/*.a
	rm -rf unit_tests*
	rm -rf tests/unit_tests*
	rm -rf vgcore*
	rm -rf *.log
	rm -rf $(NAME)

re:	fclean all

run: re
	@./$(NAME)

valgrind: re
	@valgrind -s ./$(NAME)

# Unit tests Makefile
unit_tests: re
	@make unit_tests -C./tests/

tests_run: re
	@make tests_run -C./tests/
	@gcovr
