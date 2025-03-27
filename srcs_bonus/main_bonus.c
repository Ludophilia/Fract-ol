/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:35:34 by jegerman          #+#    #+#             */
/*   Updated: 2025/03/27 16:16:55 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	fractol_init(int argc, char **argv, t_core *core)
{
	if (cli_get_args(argc, argv, core) == -1)
	{
		perror("fractol");
		ft_dprintf(2, "usage: fractol (0 | 1 "
			"<const_real> <const_imag> | 2)\n");
		return (-1);
	}
	if (color_palettes_load(25, core) == -1)
	{
		errno = ENOMEM;
		perror("fractol");
		return (-1);
	}
	if (scene_init(core) == -1 || image_init(core) == -1)
	{
		perror("fractol");
		ft_dprintf(2, "Something went wrong when initializing"
			" the MiniLibX Library.\n");
		color_palettes_free(core->pal_con.palettes, 0);
		return (-1);
	}
	view_set_complex_plane_limits(-2, 2, &core->com_pln);
	return (0);
}

int	main(int argc, char **argv)
{
	t_core	core;

	if (fractol_init(argc, argv, &core) == -1)
		return (1);
	image_draw(&core);
	scene_events_register(&core);
	scene_events_wait(&core);
	scene_destroy(&core);
	return (0);
}
