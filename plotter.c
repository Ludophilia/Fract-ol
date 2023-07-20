/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/20 14:04:24 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plotter.h"

static double	get_iter_max(double x, double y, t_inp *uinp)
{
	double complex	z;
	double			conjz_sq;
	int				i;

	x = -2 + ((2.0 - -2.0) / WINDOW_X) * x;
	y = 2 - ((2.0 - -2.0) / WINDOW_Y) * y;
	if (uinp->fract == MANDELBROT)
		z = 0;
	else
		z = x + y * I;
	i = -1;
	while (++i < MAX_ITER)
	{
		conjz_sq = creal(z) * creal(z) + cimag(z) * cimag(z);
		if (conjz_sq > RADIUS * RADIUS)
			return (i + 1 - log2((log10(conjz_sq) / 2) / log10(RADIUS)));
		z = (z * z);
		if (uinp->fract == MANDELBROT)
			z += (x + y * I);
		else
			z += uinp->zcons[0] + uinp->zcons[1] * I;
	}
	return (MAX_ITER);
}

int	get_color_for_coordinates(double x, double y, t_mlx *mlx_data)
{
	int		basecolors[2];
	int		pal_size;
	double	iter_max;
	int		*palette;

	iter_max = get_iter_max(x, y, &mlx_data->usr_inp);
	palette = mlx_data->pal_con.palettes[mlx_data->pal_con.current];
	pal_size = -1;
	while (palette[++pal_size])
		;
	if (iter_max == MAX_ITER)
		return (palette[pal_size]);
	basecolors[0] = palette[(int)iter_max % pal_size];
	basecolors[1] = palette[((int)iter_max + 1) % pal_size];
	return (interpolate_colors(basecolors[0], basecolors[1],
			iter_max - (int)iter_max));
}
