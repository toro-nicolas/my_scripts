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
