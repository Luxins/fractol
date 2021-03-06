/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:04:27 by ljahn             #+#    #+#             */
/*   Updated: 2022/07/03 16:58:17 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/costume.h"

/**
 * @brief pixels -> complexs
 * 
 * @param x 
 * @param y 
 * @param vars substruct borders
 * @return t_point 
 */
t_point	pixel_to_complex(int x, int y, t_vars *vars)
{
	t_point	comp;

	comp.r = (float)x / (X - 1);
	comp.i = (float)y / (Y - 1);
	comp.r *= vars->borders.x_right - vars->borders.x_left;
	comp.i *= vars->borders.y_down - vars->borders.y_up;
	comp.r += vars->borders.x_left;
	comp.i += vars->borders.y_up;
	return (comp);
}

/**
 * @brief Puts a grid on the screen, between the lines there are 95 pixels
 * 
 * @param cur_x current x coordinate (iter)
 * @param cur_y current y coordinate (iter)
 * @return int ; is the pixel contained in the grid
 */
int	pixel_filter(int cur_x, int cur_y)
{
	if (cur_x % 96 == 0 || cur_y % 96 == 0)
		return (1);
	return (0);
}

//1728x 1056y

/**
 * @brief Writing to the appropriate image
 * 
 * @param vars Constant, used for image data
 * @param x 
 * @param y 
 * @param color second -> red, third -> green, fourth -> blue
 */
void	paint_pixel(t_vars *vars, int x, int y, int color)
{
	char	*address;

	if (vars->flop == 1)
	{
		address = vars->img.start + x \
		* (vars->img.bits_per_pixel / 8) + y * vars->img.size_line;
		*(unsigned int *)address = color;
	}
	if (vars->flop == -1)
	{
		address = vars->img2.start + x * (vars->img2.bits_per_pixel / 8) \
		+ y * vars->img2.size_line;
		*(unsigned int *)address = color;
	}
}

static void	draw_grid(t_vars *vars)
{
	paint_pixel(vars, vars->x, vars->y, 0x00000000);
	if (pixel_filter(vars->x, vars->y))
	{
		vars->math_filter(pixel_to_complex(vars->x, \
		vars->y, vars), vars);
		if (vars->opt == -1)
		{
			paint_pixel(vars, vars->x, vars->y, \
			bernstein(vars->iterations, LIMIT, vars));
		}
		else
		{
			paint_pixel(vars, vars->x, vars->y, \
			opt(vars->iterations, LIMIT));
		}
	}
}

/**
 * @brief iterates through every pixel and paints 
 * - passes image to second read - puts right image to window
 */
void	iter(t_vars *vars)
{
	while (vars->y < Y)
	{
		while (vars->x < X)
		{
			draw_grid(vars);
			vars->x++;
		}
		vars->x = 0;
		vars->y++;
	}
	vars->y = 0;
	second_read(vars);
	if (vars->flop == 1)
		mlx_put_image_to_window(vars->inst, vars->win, vars->img.img, 0, 0);
	if (vars->flop == -1)
		mlx_put_image_to_window(vars->inst, \
		vars->win, vars->img2.img, 0, 0);
}
