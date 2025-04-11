/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/11 18:57:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// 11/04 - Changed...
double	plot_get_iter_max_for_comp_coords(double x, double y,
int fract_type, double *zconsts)
{
	double			conjz2;
	double complex	z;
	int				i;

	if (fract_type == MANDELBROT || fract_type == SHIP)
		z = 0;
	else
		z = x + y * I;
	i = -1;
	while (++i < MAX_ITER)
	{
		conjz2 = creal(z) * creal(z) + cimag(z) * cimag(z);
		if (conjz2 > RADIUS * RADIUS)
			return (i + 1 - log2((log10(conjz2) / 2) / log10(RADIUS)));
		if (fract_type == SHIP)
			z = (fabs(creal(z)) - I * fabs(cimag(z)))
				* (fabs(creal(z)) - I * fabs(cimag(z)));
		else
			z = (z * z);
		if (fract_type == MANDELBROT || fract_type == SHIP)
			z += (x + y * I);
		else
			z += zconsts[0] + zconsts[1] * I;
	}
	return (MAX_ITER);
}

// int	plot_colorize_coords(double x, double y, t_core *core)
// {
// 	int		basecolors[2];
// 	int		pal_size;
// 	double	iter_max;
// 	int		*palette;

// 	view_translate_mlx_coords_to_comp_coords(&x, &y, &core->com_pln);
// 	iter_max = plot_get_iter_max_for_comp_coords(x, y, core->usr_inp.fract,
// 			core->usr_inp.zcons);
// 	if (iter_max < 0)
// 		iter_max = 0.0;
// 	palette = core->pal_con.palettes[core->pal_con.current];
// 	pal_size = -1;
// 	while (palette[++pal_size])
// 		;
// 	if (iter_max == MAX_ITER)
// 		return (palette[pal_size]);
// 	basecolors[0] = palette[(int)iter_max % pal_size];
// 	basecolors[1] = palette[((int)iter_max + 1) % pal_size];
// 	return (color_interpolate(basecolors[0], basecolors[1],
// 			iter_max - (int)iter_max));
// }
