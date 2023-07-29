/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:50 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/25 16:33:41 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	fractol_init(int argc, char **argv, t_fra *fra_data)
{
	if (cli_args_get(argc, argv, fra_data) == -1)
	{
		perror("fractol");
		ft_dprintf(2, "usage: fractol (0 | 1 "
			"<const_real> <const_imag>)\n");
		return (-1);
	}
	if (color_palettes_load(25, fra_data) == -1)
	{
		errno = ENOMEM;
		perror("fractol");
		return (-1);
	}
	if (scene_init(fra_data) == -1 || image_init(fra_data) == -1)
	{
		perror("fractol");
		ft_dprintf(2, "Something went wrong when initializing"
			" the MiniLibX Library.\n");
		color_palettes_free(fra_data->pal_con.palettes, 0);
		return (-1);
	}
	plot_set_complex_plane_limits(-2, 2, &fra_data->com_pln);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fra	fra_data;

	if (fractol_init(argc, argv, &fra_data) == -1)
		return (1);
	image_draw(&fra_data);
	scene_events_register(&fra_data);
	scene_events_wait(&fra_data);
	scene_destroy(&fra_data);
	return (0);
}
