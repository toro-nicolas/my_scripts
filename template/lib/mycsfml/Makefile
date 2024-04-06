##
## EPITECH PROJECT, 2023
## Libmycsfml
## File description:
## The Makefile of the libmycsfml
##

NAME    	=	libmycsfml.a

CC		=	gcc

BUILDDIR 	=	../../build

SRCS		=	csfml_audio.c
SRCS		+=	csfml_fps.c
SRCS		+=	csfml_image.c
SRCS		+=	csfml_pixel.c
SRCS		+=	csfml_rect.c
SRCS		+=	csfml_shape.c
SRCS		+=	csfml_text.c

OBJS		=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

HEADER		=	mycsfml.h

CFLAGS		=	-Werror -Wextra -Wpedantic -L./ -lmy -I../../include
CFLAGS		+=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio
DEBUGFLAGS	=	-g3
OPTIMIZEFLAGS	=	-O3

.PHONY: all my debug clean fclean re copy

all:	my $(BUILDDIR) $(NAME) copy
	@echo -e "\033[1;33mLibmycsfml compiled.\033[0m"

my:
	@cp ../my/libmy.a libmy.a
	@cp ../my/my.h my.h

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUGFLAGS)
debug: OPTIMIZEFLAGS =
debug: all

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)
	@echo -e "\033[1;31mLibmycsfml .o deleted.\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo -e "\033[1;31mLibmycsfml cleaned.\033[0m"

re: fclean all

copy:
	@cp $(NAME) ../$(NAME)
	@cp $(HEADER) ../../include/$(HEADER)
