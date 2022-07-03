/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:04:31 by ljahn             #+#    #+#             */
/*   Updated: 2022/07/03 15:45:47 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/costume.h"

int	ft_close(void)
{
	exit(0);
	return (1);
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
