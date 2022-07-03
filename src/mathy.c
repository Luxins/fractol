/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:04:45 by ljahn             #+#    #+#             */
/*   Updated: 2022/07/03 15:45:59 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/costume.h"

int	fact(int n)
{
	if (n == 0)
		return (1);
	return (n * fact(n - 1));
}

double	ft_exp(double base, unsigned int exponent)
{
	if (exponent == 0)
		return (1);
	return (base * ft_exp(base, exponent - 1));
}

int	binominal(int choosen, int set)
{
	return (fact(set) / (fact(choosen) * fact(set - choosen)));
}
