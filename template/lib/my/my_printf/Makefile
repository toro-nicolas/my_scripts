##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## The Makefile of the my_printf
##

BUILDDIR 	=	../../../build

SRCS		=	flag_c.c			\
			flag_s.c			\
			flag_d.c			\
			flag_i.c			\
			flag_p.c			\
			flag_o.c			\
			flag_u.c			\
			flag_x.c			\
			flag_bigx.c			\
			flag_e.c          		\
			flag_bige.c			\
			flag_f.c			\
			flag_bigf.c			\
			flag_g.c          		\
			flag_bigg.c			\
			flag_a.c			\
			flag_biga.c			\
			flag_n.c          		\
			flag_m.c          		\
			flag_b.c			\
			flag_bigs.c			\
			flag_bigd.c			\
			flag_percent.c			\
			flags.c				\
			find_format.c 			\
			get_format.c			\
			my_show_formating.c 		\
			sub_format_double.c		\
			format_it_double.c		\
			precise_it_double.c		\
			sub_format_int.c		\
			format_it_int.c			\
			precise_it_int.c		\
			format_it_char.c		\
			sub_format_char.c		\
			format_it_str.c			\
			sub_format_str.c		\
			specifier_int.c			\
			specifier_base.c		\

OBJS     	=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

CFLAGS		=	-Werror -Wextra -Wpedantic

all: create-build $(BUILDDIR) $(OBJS)

create-build:
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

re: clean all
