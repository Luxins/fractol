/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:04:58 by ljahn             #+#    #+#             */
/*   Updated: 2022/07/03 15:46:10 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/costume.h"

/**
 * @brief Gets the color value of a pixel
 * 
 * @param vars The picture iter wrote to right before
 * @param x 
 * @param y 
 * @return unsigned int 
 */
unsigned int	getcolor(t_vars *vars, int x, int y)
{
	char	*pxl;

	if (vars->flop == 1)
		pxl = vars->img.start + x * (vars->img.bits_per_pixel / 8) \
		+ y * vars->img.size_line;
	else
		pxl = vars->img2.start + x * (vars->img2.bits_per_pixel / 8) \
		+ y * vars->img2.size_line;
	return (*(unsigned int *)pxl);
}

void	filler(int x, int y, t_vars *vars, unsigned int color)
{
	int	i;
	int	j;

	x++;
	y++;
	i = 0;
	j = 0;
	while (i < BOX_SIZE - 1)
	{
		while (j < BOX_SIZE - 1)
		{
			paint_pixel(vars, x + i, y + j, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	four(int x, int y, t_vars *vars)
{
	int	i;
	int	j;

	x++;
	y++;
	i = 0;
	j = 0;
	while (i < BOX_SIZE - 2)
	{
		while (j < BOX_SIZE - 2)
		{
			paint_pixel(vars, x + j, y + i, 0x00000000);
			vars->math_filter(pixel_to_complex(x + j, y + i, vars), vars);
			paint_pixel(vars, x + j, y + i, bernstein \
			(vars->iterations, LIMIT, vars));
			j++;
		}
		j = 0;
		i++;
	}
}

int	check_box(int x, int y, t_vars *vars)
{
	int	i;

	vars->pxl1 = getcolor(vars, x, y);
	i = 0;
	while (i < BOX_SIZE)
	{
		if (getcolor(vars, x + i, y) != vars->pxl1 || \
			getcolor(vars, x + BOX_SIZE - 1, y + i) != vars->pxl1 || \
			getcolor(vars, x + BOX_SIZE - 1 - i, y + BOX_SIZE - 1) != \
			vars->pxl1 || getcolor(vars, x, y + BOX_SIZE -1 - i) != vars->pxl1)
			return (0);
		i++;
	}
	return (1);
}

void	second_read(t_vars *vars)
{
	int	box_x;
	int	box_y;

	box_x = 0;
	box_y = 0;
	while (box_x < X - 1)
	{
		while (box_y < Y - 1)
		{
			if (check_box(box_x, box_y, vars))
				filler(box_x, box_y, vars, vars->pxl1);
			else
				four(box_x, box_y, vars);
			box_y += BOX_SIZE - 1;
		}
		box_y = 0;
		box_x += BOX_SIZE - 1;
	}
}
