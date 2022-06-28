/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:03:56 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/22 09:03:57 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

void	assign_rust(t_vars *vars)
{
	vars->bernstein.r_n = 5;
	vars->bernstein.r_v = 0;
	vars->bernstein.r_end = 243;
	vars->bernstein.g_n = 6;
	vars->bernstein.g_v = 2;
	vars->bernstein.g_end = 125;
	vars->bernstein.b_n = 21;
	vars->bernstein.b_v = 5;
	vars->bernstein.b_end = 174;
}

void	assign_camouflaged(t_vars *vars)
{
	vars->bernstein.r_n = 11;
	vars->bernstein.r_v = 2;
	vars->bernstein.r_end = 195;
	vars->bernstein.g_n = 6;
	vars->bernstein.g_v = 1;
	vars->bernstein.g_end = 155;
	vars->bernstein.b_n = 6;
	vars->bernstein.b_v = 5;
	vars->bernstein.b_end = 128;
}

void	assign_hapiness(t_vars *vars)
{
	vars->bernstein.r_n = 18;
	vars->bernstein.r_v = 0;
	vars->bernstein.r_end = 239;
	vars->bernstein.g_n = 20;
	vars->bernstein.g_v = 1;
	vars->bernstein.g_end = 239;
	vars->bernstein.b_n = 22;
	vars->bernstein.b_v = 2;
	vars->bernstein.b_end = 223;
}

void	assign_julia_circle(t_vars *vars)
{
	vars->julia_r = 0;
	vars->julia_i = 0;
	vars->math_filter = &julia;
}

void	assign_julia_trees(t_vars *vars)
{
	vars->julia_r = -1.4;
	vars->julia_i = 0;
	vars->math_filter = &julia;
}
