/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/31 14:37:09 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	plot_translate_mlx_coords_to_comp_coords(double *x, double *y,
t_pln *com_pln)
{
	double	*x_lim;
	double	*y_lim;

	x_lim = com_pln->x_lim;
	y_lim = com_pln->y_lim;
	*x = x_lim[0] + ((x_lim[1] - x_lim[0]) / WIN_X) * *x;
	*y = y_lim[1] - ((y_lim[1] - y_lim[0]) / WIN_Y) * *y;
}

static double	plot_get_iter_max_for_comp_coords(double x, double y,
t_core *core)
{
	double complex	z;
	double			conjz2;
	int				i;

	if (core->usr_inp.fract == MANDELBROT)
		z = 0;
	else
		z = x + y * I;
	i = -1;
	while (++i < MAX_ITER)
	{
		conjz2 = creal(z) * creal(z) + cimag(z) * cimag(z);
		if (conjz2 > RADIUS * RADIUS)
			return (i + 1 - log2((log10(conjz2) / 2) / log10(RADIUS)));
		z = (z * z);
		if (core->usr_inp.fract == MANDELBROT)
			z += (x + y * I);
		else
			z += core->usr_inp.zcons[0] + core->usr_inp.zcons[1] * I;
	}
	return (MAX_ITER);
}

int	plot_colorize_mlx_coords(double x, double y, t_core *core)
{
	int		basecolors[2];
	int		pal_size;
	double	iter_max;
	int		*palette;

	plot_translate_mlx_coords_to_comp_coords(&x, &y, &core->com_pln);
	iter_max = plot_get_iter_max_for_comp_coords(x, y, core);
	if (iter_max < 0)
		iter_max = 0.0;
	palette = core->pal_con.palettes[core->pal_con.current];
	pal_size = -1;
	while (palette[++pal_size])
		;
	if (iter_max == MAX_ITER)
		return (palette[pal_size]);
	basecolors[0] = palette[(int)iter_max % pal_size];
	basecolors[1] = palette[((int)iter_max + 1) % pal_size];
	return (color_interpolate(basecolors[0], basecolors[1],
			iter_max - (int)iter_max));
}

void	plot_set_limits(double min, double max, t_pln *plane)
{
	*plane = (t_pln){.x_min = min, .y_min = min, .x_max = max, .y_max = max};
}

void	plot_change_zoom_level(int zoom_in, t_pln *com_pln)
{
	double	min;
	double	max;

	min = com_pln->x_lim[0];
	max = com_pln->y_lim[1];
	if (zoom_in)
	{
		min /= ZOOM_LEVEL;
		max /= ZOOM_LEVEL;
	}
	else
	{
		min *= ZOOM_LEVEL;
		max *= ZOOM_LEVEL;
	}
	plot_set_limits(min, max, com_pln);
}
