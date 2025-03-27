/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewmgr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:15:56 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/27 15:35:08 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	view_translate_mlx_coords_to_comp_coords(double *x, double *y,
t_pln *com_pln)
{
	double	*x_lim;
	double	*y_lim;

	x_lim = com_pln->x_lim;
	y_lim = com_pln->y_lim;
	*x = x_lim[0] + ((x_lim[1] - x_lim[0]) / WINDOW_X) * *x;
	*y = y_lim[1] - ((y_lim[1] - y_lim[0]) / WINDOW_Y) * *y;
}

void	view_set_complex_plane_limits(double min, double max, t_pln *com_pln)
{
	double	nb;
	int		i;

	i = -1;
	while (++i < 2)
	{
		if (i == 0)
			nb = min;
		else
			nb = max;
		com_pln->x_lim[i] = nb;
		com_pln->y_lim[i] = nb;
	}
}

void	view_shit_comp_plane(uchar shift_direction, t_pln *com_pln)
{
	double	*x_lim;
	double	*y_lim;

	x_lim = com_pln->x_lim;
	y_lim = com_pln->y_lim;
	if (shift_direction == SHIFT_LEFT)
	{
		com_pln->x_lim[0] -= SHIFT_FACTOR * (x_lim[1] - x_lim[0]);
		com_pln->x_lim[1] -= SHIFT_FACTOR * (x_lim[1] - x_lim[0]);
	}
	else if (shift_direction == SHIFT_RIGHT)
	{
		com_pln->x_lim[0] += SHIFT_FACTOR * (x_lim[1] - x_lim[0]);
		com_pln->x_lim[1] += SHIFT_FACTOR * (x_lim[1] - x_lim[0]);
	}
	else if (shift_direction == SHIFT_UP)
	{
		com_pln->y_lim[0] += SHIFT_FACTOR * (y_lim[1] - y_lim[0]);
		com_pln->y_lim[1] += SHIFT_FACTOR * (y_lim[1] - y_lim[0]);
	}
	else if (shift_direction == SHIFT_DOWN)
	{
		com_pln->y_lim[0] -= SHIFT_FACTOR * (y_lim[1] - y_lim[0]);
		com_pln->y_lim[1] -= SHIFT_FACTOR * (y_lim[1] - y_lim[0]);
	}
}

void	view_change_comp_plane_zoom_level(int zoom_in, double x, double y,
t_pln *com_pln)
{
	double	*x_lim;
	double	*y_lim;
	double	ratios[2];

	x_lim = com_pln->x_lim;
	y_lim = com_pln->y_lim;
	ratios[0] = x / WINDOW_X;
	ratios[1] = y / WINDOW_Y;
	view_translate_mlx_coords_to_comp_coords(&x, &y, com_pln);
	if (zoom_in)
	{
		x_lim[0] = x - ratios[0] * ((x_lim[1] - x_lim[0]) / ZOOM_LEVEL);
		x_lim[1] = x + (1. - ratios[0]) * ((x_lim[1] - x_lim[0]) / ZOOM_LEVEL);
		y_lim[0] = y - (1. - ratios[1]) * ((x_lim[1] - x_lim[0]) / ZOOM_LEVEL);
		y_lim[1] = y + ratios[1] * ((x_lim[1] - x_lim[0]) / ZOOM_LEVEL);
	}
	else
	{
		x_lim[0] = x - ratios[0] * ((x_lim[1] - x_lim[0]) * ZOOM_LEVEL);
		x_lim[1] = x + (1. - ratios[0]) * ((x_lim[1] - x_lim[0]) * ZOOM_LEVEL);
		y_lim[0] = y - (1. - ratios[1]) * ((x_lim[1] - x_lim[0]) * ZOOM_LEVEL);
		y_lim[1] = y + ratios[1] * ((x_lim[1] - x_lim[0]) * ZOOM_LEVEL);
	}
}
