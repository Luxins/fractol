/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:04:31 by ljahn             #+#    #+#             */
/*   Updated: 2022/07/03 16:59:16 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/costume.h"

int	ft_close(void)
{
	exit(0);
	return (1);
}

static void	init_vars(t_vars *vars)
{
	vars->opt = -1;
	vars->x = 0;
	vars->y = 0;
	vars->flop = 1;
	vars->zoom = 1;
	vars->pxl1 = 0;
	vars->borders.x_left = -1.6;
	vars->borders.y_up = -1;
	vars->borders.x_right = 1;
	vars->borders.y_down = 1;
	vars->bernstein.r_n = 4;
	vars->bernstein.r_v = 2;
	vars->inst = mlx_init();
	vars->win = mlx_new_window(vars->inst, X, Y, "fract-ol");
	vars->img.img = mlx_new_image(vars->inst, X, Y);
	vars->img2.img = mlx_new_image(vars->inst, X, Y);
	vars->img.start = mlx_get_data_addr(vars->img.img, \
	&vars->img.bits_per_pixel, &vars->img.size_line, &vars->img.endian);
	vars->img2.start = mlx_get_data_addr(vars->img2.img, \
	&vars->img2.bits_per_pixel, &vars->img2.size_line, &vars->img2.endian);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	srand(time(NULL));
	check_inputs(argc, argv, &vars);
	init_vars(&vars);
	iter(&vars);
	mlx_put_image_to_window(vars.inst, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, ON_DESTROY, 0, ft_close, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hooks, &vars);
	mlx_loop(vars.inst);
	return (0);
}
