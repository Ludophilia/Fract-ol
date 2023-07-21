/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:50 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/21 20:27:47 by jgermany         ###   ########.fr       */
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

// 20/07 - What modules are responsible for zooming?
// 		- imgmgr for redrawing the image after zooming
//				- plotter for calculating the behavior of mandelbrot/julia
//				for that pixel in the complex plan.
// 		- scenemgr for the mouse events
// 		- hookmgr for managing the mouse hooks, maybe loops hook for refreshing
//		the image
//		- ???

// 21/07 - Zooming, it's just redifining the complex plane.
// Ex a complex plane that goes to [-2, 2] on x and y axis
// will be redifined to [-1, 1] on x and y axis if 2x zoom

// 21/07 - What to do?
//
// - [x] Create an another struct that will represent the complex plane 
// and associate it with the t_fra struct.
// - [ ] Create an event that maps scroll events to a function that modifies
// the limits of the complex plane
// - [ ] Create the hook that manages zooming and dezooming... manage the mouse
// position as well
// - [ ] Maybe create an loop event that redraws the image every time,
// unless you manage this at the end of the zooming even
