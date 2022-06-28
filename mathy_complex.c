/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathy_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:04:39 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/22 09:04:40 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "costume.h"

t_point	add_comp(t_point a, t_point b)
{
	a.r = a.r + b.r;
	a.i = a.i + b.i;
	return (a);
}

t_point	mult_comp(t_point a, t_point b)
{
	t_point	res;

	res.r = a.r * b.r - a.i * b.i;
	res.i = a.i * b.r + a.r * b.i;
	return (res);
}

t_point	sqr_comp(t_point a)
{
	return (mult_comp(a, a));
}

void	init_comp(t_point *a)
{
	a->r = 0;
	a->i = 0;
}

t_point	assign_comp(int r, int i)
{
	t_point	res;

	res.r = r;
	res.i = i;
	return (res);
}
