/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:04:17 by ljahn             #+#    #+#             */
/*   Updated: 2022/07/03 15:36:00 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/costume.h"

/**
 * @brief Looks if a complex number is contained in the mandelbrot set
 * 
 * @param comp costume type
 * @return int 
 */
void	mandelbrot(t_point comp, t_vars *vars)
{
	t_point		run;
	int			cnt;

	cnt = 0;
	init_comp(&run);
	vars->iterations = LIMIT;
	while (run.r < 2 && run.i < 2)
	{
		run = add_comp(sqr_comp(run), comp);
		if (cnt > LIMIT)
			return ;
		cnt++;
	}
	vars->iterations = cnt;
	return ;
}

void	julia(t_point comp, t_vars *vars)
{
	t_point	constant;
	int		cnt;

	cnt = 0;
	constant.r = vars->julia_r;
	constant.i = vars->julia_i;
	vars->iterations = LIMIT;
	while (comp.r < 2 && comp.i < 2)
	{
		comp = add_comp(sqr_comp(comp), constant);
		if (cnt > LIMIT)
			return ;
		cnt++;
	}
	vars->iterations = cnt;
	return ;
}
