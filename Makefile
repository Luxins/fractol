ADDITIONALS = src/mathy.c src/iter.c src/colors.c src/hooks.c src/parameters.c src/second_read.c src/fractals.c src/mathy_complex.c src/assigning.c

MAIN = src/main.c

NAME = fractol

$(NAME):	all

bonus:	all

all:
	gcc -Werror -Wextra -Wall $(MAIN) $(ADDITIONALS) includes/libmlx.a includes/libft.a -g -framework OpenGL -framework AppKit -O3 -o $(NAME)
clean:
	rm -f $(NAME)
fclean:
	rm -f $(NAME)
re:	fclean all

.PHONY:	all $(NAME) labs