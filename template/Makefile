##
## EPITECH PROJECT, 2023
## [project-name]
## File description:
## The main Makefile of our project
##

NAME		=	a#[project-exec]

BUILDDIR 	=	./build
SRCDIR		=	./src

SRCS		+=	main.c

OBJS     	=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

CFLAGS		=	-Werror -Wextra -I./include/
DEBUGFLAGS	=	-g3
OPTIMIZEFLAGS	=	-O3

LDFLAGS 	=	-L./lib/ -lmymemory -lmyhashtable -lmycsfml -lmylist -lmy

all: create-build libs $(BUILDDIR) $(NAME)
	@echo -e "\033[1;33m$(NAME) compiled.\033[0m"

libs:
	@make --no-print-directory -C ./lib/my/
	@make --no-print-directory -C ./lib/mylist/
	@make --no-print-directory -C ./lib/mycsfml/
	@make --no-print-directory -C ./lib/myhashtable/
	@make --no-print-directory -C ./lib/mymemory/
	@echo -e "\033[1;33mLibs made.\033[0m"

create-build:
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUGFLAGS)
debug: OPTIMIZEFLAGS =
debug: all

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -o $(NAME)
	@rm -rf ./lib/my/*.a
	@rm -rf ./lib/mylist/*.a
	@rm -rf ./lib/mycsfml/*.a
	@rm -rf ./lib/myhashtable/*.a
	@rm -rf ./lib/mymemory/*.a

clean:
	@rm -rf $(BUILDDIR)
	@echo -e "\033[1;31mAll .o deleted.\033[0m"

fclean: clean
	@rm -rf ./lib/*.a
	@rm -rf unit_tests*
	@rm -rf tests/unit_tests*
	@rm -rf vgcore*
	@rm -rf *.log
	@rm -rf $(NAME)
	@echo -e "\033[1;31mProject cleaned.\033[0m"

re:	fclean all

# Unit tests Makefile
unit_tests:
	@make unit_tests --no-print-directory -C./tests/

tests_run:
	@make tests_run --no-print-directory -C./tests/
	@gcovr
