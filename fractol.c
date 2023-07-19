/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:50 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/18 17:26:34 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx_data;

	if (get_cli_args(argc, argv, &mlx_data) == -1)
	{
		perror("fractol");
		ft_dprintf(2, "usage: fractol (0 | 1 "
			"<const_real> <const_imag>)\n");
		return (1);
	}
	// load colors here?
	if (init_scene(&mlx_data) == -1 || init_image(&mlx_data) == -1)
	{
		perror("fractol");
		ft_dprintf(2, "Something went wrong when initializing"
			" the MiniLibX Library.\n");
		return (1);
	}
	draw_on_image(&mlx_data);
	register_events(&mlx_data);
	wait_for_events(&mlx_data);
	destroy_scene(&mlx_data);
	return (0);
}
