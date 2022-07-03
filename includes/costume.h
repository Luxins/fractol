/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costume.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:04:07 by ljahn             #+#    #+#             */
/*   Updated: 2022/07/03 16:30:52 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COSTUME_H
# define COSTUME_H

# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define BRIGHTNESS 100
# define X 1729
# define Y 1153
# define BOX_SIZE 97

//		ignore.c -> math_filter()
# define LIMIT 100

//		second_read() and subfunction
// #define BOX_SIZE 97

typedef void	(*t_math_filter)();

typedef struct s_img
{
	void	*img;
	char	*start;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_point
{
	float	r;
	float	i;
	int		x;
	int		y;
}	t_point;

typedef struct s_borders
{
	float	x_left;
	float	y_up;
	float	x_right;
	float	y_down;
}	t_borders;

typedef struct s_bernstein
{
	unsigned int	r_v;
	unsigned int	r_n;
	unsigned int	g_v;
	unsigned int	g_n;
	unsigned int	b_v;
	unsigned int	b_n;
	unsigned char	r_end;
	unsigned char	g_end;
	unsigned char	b_end;
}	t_bernstein;

typedef struct s_vars
{
	int				flop;
	int				iterations;
	unsigned int	pxl1;
	float			zoom;
	void			*win;
	void			*inst;
	t_borders		borders;
	t_img			img;
	t_img			img2;
	t_math_filter	math_filter;
	float			julia_r;
	float			julia_i;
	t_bernstein		bernstein;
	int				x;
	int				y;
}	t_vars;

enum
{
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
};

enum
{
	KEY_ONE = 18,
	ESCAPE = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	ARROW_DOWN = 125,
	ARROW_UP = 126,
	ON_DESTROY = 17
};

//			mathy_complex.c
t_point			add_comp(t_point a, t_point b);
t_point			mult_comp(t_point a, t_point b);
t_point			sqr_comp(t_point a);
void			init_comp(t_point *a);
t_point			assign_comp(int r, int i);

//			mathy.c
int				fact(int n);
double			ft_exp(double base, unsigned int exponent);
int				binominal(int choosen, int set);

//			ignore.c
void			init_vars(t_vars *vars);
void			iter(t_vars *vars);
void			paint_pixel(t_vars *vars, int x, int y, int color);
int				pixel_filter(int cur_x, int cur_y);
t_point			pixel_to_complex(int x, int y, t_vars *vars);

//			fractals.h
void			mandelbrot(t_point comp, t_vars *vars);
void			julia(t_point comp, t_vars *vars);

//			second_read.c
unsigned int	getcolor(t_vars *vars, int x, int y);
void			second_read(t_vars *vars);

//			parameters.c
void			check_inputs(int argc, char *argv[], t_vars *vars);

//			hooks.c
int				key_hooks(int keycode, t_vars *vars);

//			main.c
int				mouse_hook(int mousecode, int x, int y, t_vars	*vars);
void			julia(t_point comp, t_vars *vars);

//			assigning.c
void			assign_rust(t_vars *vars);
void			assign_camouflaged(t_vars *vars);
void			assign_hapiness(t_vars *vars);
void			assign_julia_circle(t_vars *vars);
void			assign_julia_trees(t_vars *vars);

//			colors.c
unsigned int	bernstein(int iterations, int max_iterations, t_vars *vars);
unsigned int	opt(int iterations, int max_iterations);

#endif
