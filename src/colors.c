/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:04:02 by ljahn             #+#    #+#             */
/*   Updated: 2022/07/03 16:47:08 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/costume.h"

unsigned int	create_trgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

unsigned int	bernstein(int iterations, int max_iterations, t_vars *vars)
{
	double			ratio;
	double			negative;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	ratio = (float)iterations / max_iterations;
	negative = 1 - ratio;
	r = binominal(vars->bernstein.r_v, vars->bernstein.r_n) \
	* ft_exp(ratio, vars->bernstein.r_v) \
	* ft_exp(negative, vars->bernstein.r_n - vars->bernstein.r_v) \
	* vars->bernstein.r_end;
	g = binominal(vars->bernstein.g_v, vars->bernstein.g_n) \
	* ft_exp(ratio, vars->bernstein.g_v) \
	* ft_exp(negative, vars->bernstein.g_n - vars->bernstein.g_v) \
	* vars->bernstein.g_end;
	b = binominal(vars->bernstein.b_v, vars->bernstein.b_n) \
	* ft_exp(ratio, vars->bernstein.b_v) \
	* ft_exp(negative, vars->bernstein.b_n - vars->bernstein.b_v) \
	* vars->bernstein.b_end;
	return (create_trgb(r, g, b));
}

unsigned int	opt(int iterations, int max_iterations)
{
	if (iterations / max_iterations > 0.5)
		return (0x00FF0000);
	return (0x0000FF00);
}
