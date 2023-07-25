/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewmgr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:15:56 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/25 21:45:34 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewmgr_bonus.h"

void	view_translate_mlx_coords_to_comp_coords(double *x, double *y,
t_pln *com_pln)
{
	double	*x_lim;
	double	*y_lim;

	x_lim = com_pln->x_lim;
	y_lim = com_pln->y_lim;
	*x = x_lim[0] + ((x_lim[1] - x_lim[0]) / WINDOW_X) * *x;
	*y = y_lim[1] - ((y_lim[1] - y_lim[0]) / WINDOW_Y) * *y;
	return ;
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
	return ;
}

// Push left: -2;2 on x becomes -2.01;1.99
// Push right: -2;2 on x becomes -1.99;2.01

// Push top: -2;2 on y becomes -1.99;2.01
// Push bottom: -2;2 on y becomes -2.01;1.99


void	view_change_comp_plane_zoom_level(int zoom_in, double x, double y,
t_pln *com_pln)
{
	double	*x_lim;
	double	*y_lim;

	x_lim = com_pln->x_lim;
	y_lim = com_pln->y_lim;
	view_translate_mlx_coords_to_comp_coords(&x, &y, com_pln);
	if (zoom_in)
	{
		x_lim[0] = x - 0.50 * ((x_lim[1] - x_lim[0]) / ZOOM_LEVEL);
		x_lim[1] = x + 0.50 * ((x_lim[1] - x_lim[0]) / ZOOM_LEVEL);
		y_lim[0] = y - 0.50 * ((x_lim[1] - x_lim[0]) / ZOOM_LEVEL);
		y_lim[1] = y + 0.50 * ((x_lim[1] - x_lim[0]) / ZOOM_LEVEL);
	}
	else
	{
		x_lim[0] = x - 0.50 * ((x_lim[1] - x_lim[0]) * ZOOM_LEVEL);
		x_lim[1] = x + 0.50 * ((x_lim[1] - x_lim[0]) * ZOOM_LEVEL);
		y_lim[0] = y - 0.50 * ((x_lim[1] - x_lim[0]) * ZOOM_LEVEL);
		y_lim[1] = y + 0.50 * ((x_lim[1] - x_lim[0]) * ZOOM_LEVEL);
	}
}
