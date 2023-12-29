##
## EPITECH PROJECT, 2023
## Libmycsfml
## File description:
## The Makefile of the libmycsfml
##

NAME    	=	libmycsfml.a

BUILDDIR 	=	../../build

SRCS		=	csfml_audio.c	\
				csfml_fps.c		\
				csfml_image.c	\
				csfml_pixel.c	\
				csfml_rect.c	\
				csfml_shape.c	\
				csfml_text.c	\

OBJS		=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

HEADER		=	mycsfml.h

CFLAGS		=	-Werror -Wextra -Wpedantic -L./ -lmy -I../../include
CFLAGS		+=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all:	my $(BUILDDIR) $(NAME) copy
	@echo -e "\033[1;33mLibmycsfml compiled.\033[0m"

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
	@echo -e "\033[1;31mLibmycsfml .o deleted.\033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo -e "\033[1;31mLibmycsfml cleaned.\033[0m"

re: 	fclean all

copy:
	@cp $(NAME) ../$(NAME)
	@cp $(HEADER) ../../include/$(HEADER)
