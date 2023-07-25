/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/25 21:18:05 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plotter_bonus.h"

static double	plot_get_iter_max_for_comp_coords(double x, double y,
t_fra *fra_data)
{
	double complex	z;
	double			conjz2;
	int				i;

	view_translate_mlx_coords_to_comp_coords(&x, &y, &fra_data->com_pln);
	if (fra_data->usr_inp.fract == MANDELBROT)
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
		if (fra_data->usr_inp.fract == MANDELBROT)
			z += (x + y * I);
		else
			z += fra_data->usr_inp.zcons[0] + fra_data->usr_inp.zcons[1] * I;
	}
	return (MAX_ITER);
}

int	plot_colorize_mlx_coords(double x, double y, t_fra *fra_data)
{
	int		basecolors[2];
	int		pal_size;
	double	iter_max;
	int		*palette;

	iter_max = plot_get_iter_max_for_comp_coords(x, y, fra_data);
	if (iter_max < 0)
		iter_max = 0.0;
	palette = fra_data->pal_con.palettes[fra_data->pal_con.current];
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
