/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/19 20:02:55 by jgermany         ###   ########.fr       */
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

/// (20/07/23) - So... What to do?

// - Create a structure for palettes (must include palette size)
// - Improve the functions below, why not merge them?

int	get_color_for_iter_max(double iter_max, t_mlx *mlx_data)
{
	int color1;
	int	color2;
	int	ic1;
	int	ic2;

	if (iter_max == MAX_ITER)
		return (palette[(int)(iter_max * (PAL_LEN - 1) / MAX_ITER)]);
	ic1 = (int)(iter_max) % PAL_LEN;
	ic2 = ((int)(iter_max) + 1) % PAL_LEN;
	color1 = palette[ic1];
	color2 = palette[ic2];
	// return (interpolate_colors(color1, color2, 1));
	return (interpolate_colors(color1, color2, iter_max - (int)iter_max));
}


int	get_color_for_coordinates(double x, double y, t_mlx *mlx_data)
{
	double	iter_max;
	int	color;

	iter_max = get_iter_max(x, y, mlx_data);
	color = get_color_for_iter_max(iter_max, mlx_data);
	return (color);
}
