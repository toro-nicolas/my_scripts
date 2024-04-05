##
## EPITECH PROJECT, 2023
## [project-name]
## File description:
## The main Makefile of our project
##

NAME		=	[project-exec]

CC		=	gcc

BUILDDIR 	=	./build
SRCDIR		=	./src

SRCS		+=	main.c

OBJS     	=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

CFLAGS		=	-Werror -Wextra -I./include/
DEBUGFLAGS	=	-g3
OPTIMIZEFLAGS	=	-O3

LDFLAGS 	=	-L./lib/ -lmymemory -lmyhashtable -lmycsfml -lmylist -lmy

.PHONY: all libs create-build debug clean fclean re unit_tests tests_run

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
	@rm -rf ./lib/my/libmy.a
	@rm -rf ./lib/mylist/libmylist.a
	@rm -rf ./lib/mycsfml/libmycsfml.a
	@rm -rf ./lib/myhashtable/libmyhashtable.a
	@rm -rf ./lib/mymemory/libmymemory.a

clean:
	@rm -rf $(BUILDDIR)
	@echo -e "\033[1;31mAll .o deleted.\033[0m"

fclean: clean
	@rm -rf *.a
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
	@gcovr \
	--exclude lib/my/my_printf/round_flag_a.c \
	--exclude lib/mylist/my_list_to_array.c \
	--exclude lib/mylist/my_show_list.c \
