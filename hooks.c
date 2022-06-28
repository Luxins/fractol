/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:04:23 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/22 09:04:24 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

int	brightness(unsigned int color)
{
	int	a;

	a = (unsigned char)color;
	a += (unsigned char)(color >> 8);
	a += (unsigned char)(color >> 16);
	return (a);
}

void	random_thingy(t_vars *vars)
{
	vars->bernstein.r_n = rand() % 20 + 5;
	vars->bernstein.r_v = rand() % 6;
	vars->bernstein.r_end = rand() % 256;
	vars->bernstein.g_n = rand() % 20 + 5;
	vars->bernstein.g_v = rand() % 6;
	vars->bernstein.g_end = rand() % 256;
	vars->bernstein.b_n = rand() % 20 + 5;
	vars->bernstein.b_v = rand() % 6;
	vars->bernstein.b_end = rand() % 256;
}

int	key_hooks(int keycode, t_vars *vars)
{
	int	bright;

	bright = 0;
	if (keycode == KEY_ONE)
	{
		while (bright < BRIGHTNESS)
		{
			random_thingy(vars);
			bright = brightness(bernstein(20, LIMIT, vars));
		}
	}
	if (keycode == ARROW_LEFT)
		vars->julia_r -= 0.1;
	if (keycode == ARROW_RIGHT)
		vars->julia_r += 0.1;
	if (keycode == ARROW_DOWN)
		vars->julia_i += 0.1;
	if (keycode == ARROW_UP)
		vars->julia_i -= 0.1;
	if (keycode == ESCAPE)
		exit(0);
	iter(vars);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	t_point		con;
	t_point		inv;

	con = pixel_to_complex(x, y, vars);
	if (mousecode == ON_MOUSEUP)
	{
		vars->zoom = 0.9;
		vars->flop *= -1;
	}
	if (mousecode == ON_MOUSEDOWN)
	{
		vars->zoom = 1.1;
		vars->flop *= -1;
	}
	inv = assign_comp(vars->borders.x_left + vars->borders.x_right \
	- con.r, vars->borders.y_up + vars->borders.y_down - con.i);
	vars->borders.x_left = con.r + (vars->borders.x_left - con.r) * vars->zoom;
	vars->borders.x_right = con.r + (vars->borders.x_right - con.r) \
	* vars->zoom;
	vars->borders.y_up = con.i + (vars->borders.y_up - con.i) * vars->zoom;
	vars->borders.y_down = con.i + (vars->borders.y_down - con.i) * vars->zoom;
	iter(vars);
	return (0);
}
