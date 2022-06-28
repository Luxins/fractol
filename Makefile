ADDITIONALS = mathy.c iter_and_ignore.c colors.c hooks.c parameters.c second_read.c fractals.c mathy_complex.c assigning.c

MAIN = main.c

NAME = fractol

$(NAME):	all

bonus:	all

all:
	gcc -Werror -Wextra -Wall $(MAIN) $(ADDITIONALS) libmlx.a libft.a -g -framework OpenGL -framework AppKit -O3 -o $(NAME)
clean:
	rm -f $(NAME)
fclean:
	rm -f $(NAME)
re:	fclean all

.PHONY:	all $(NAME) labs