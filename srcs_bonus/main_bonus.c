/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:35:34 by jegerman          #+#    #+#             */
/*   Updated: 2025/03/19 12:36:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	fractol_init(int argc, char **argv, t_fra *fra_data)
{
	if (cli_args_get(argc, argv, fra_data) == -1)
	{
		perror("fractol");
		ft_dprintf(2, "usage: fractol (0 | 1 "
			"<const_real> <const_imag> | 2)\n");
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
	view_set_complex_plane_limits(-2, 2, &fra_data->com_pln);
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
