/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:04:53 by ljahn             #+#    #+#             */
/*   Updated: 2022/07/03 15:46:05 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/costume.h"

void	error_msg(char *desc)
{
	ft_putstr_fd(desc, 1);
	ft_putstr_fd("--------------------------\n", 1);
	ft_putstr_fd("{fractol}{Julia-subset(if Julia was chosen)}\
	{color scheme}\n", 1);
	ft_putstr_fd("--------------------------\n", 1);
	ft_putstr_fd("Available fractols: 'Julia', 'Mandelbrot'\n", 1);
	ft_putstr_fd("Available Julia-subsets: 'circle', 'trees'\n", 1);
	ft_putstr_fd("Available color schemes: 'rust'(not on Julia circle), 'camouflaged', \
	'hapiness'\n", 1);
	exit(1);
}

void	check_color_schemes(char *argv[], t_vars *vars)
{
	if (!ft_strcmp(argv[1], "Julia") && !ft_strcmp(argv[2], "circle") \
	&& !ft_strcmp(argv[3], "rust"))
		error_msg("Error: Rust is not available for Julia circle\n");
	else if (!ft_strcmp(argv[2], "rust") || (!ft_strcmp(argv[1], "Julia") \
	&& !ft_strcmp(argv[3], "rust")))
		assign_rust(vars);
	else if (!ft_strcmp(argv[2], "camouflaged") || (!ft_strcmp(\
	argv[1], "Julia") && !ft_strcmp(argv[3], "camouflaged")))
		assign_camouflaged(vars);
	else if (!ft_strcmp(argv[2], "hapiness") || \
	(!ft_strcmp(argv[1], "Julia") && !ft_strcmp(argv[3], \
	"hapiness")))
		assign_hapiness(vars);
	else
		error_msg("Error: Invalid color scheme\n");
}

void	check_inputs(int argc, char *argv[], t_vars *vars)
{
	if (argc == 3 || (argc == 4 && !ft_strcmp(argv[1], "Julia")))
	{
		if (!ft_strcmp(argv[1], "Mandelbrot"))
			vars->math_filter = &mandelbrot;
		else if (!ft_strcmp(argv[1], "Julia"))
		{
			if (!ft_strcmp(argv[2], "circle"))
				assign_julia_circle(vars);
			else if (!ft_strcmp(argv[2], "trees"))
				assign_julia_trees(vars);
			else
				error_msg("Error: Invalid Julia-subset\n");
		}
		else
			error_msg("Error: Invalid fractal choice\n");
		check_color_schemes(argv, vars);
	}
	else
		error_msg("Error: Invalid number of arguments\n");
}
