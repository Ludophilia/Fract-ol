/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/31 19:37:56 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	plot_set_limits(double min, double max, t_pln *pln)
{
	*pln = (t_pln){.x_min = min, .y_min = min, .x_max = max, .y_max = max};
}

int	plot_set_zoom_lvl(int zoom_in, t_pln *pln)
{
	if (pln->x_min != pln->y_min || pln->x_max != pln->y_max)
		return (-1);
	if (zoom_in)
		plot_set_limits(pln->x_min / ZOOM_LVL, pln->y_max / ZOOM_LVL, pln);
	else
		plot_set_limits(pln->x_min * ZOOM_LVL, pln->y_max * ZOOM_LVL, pln);
	return (0);
}

// 31/03 - What is this?
//	- (0, 0) is on the top left, x_min starts at the left, and y_max at the top.
// (x_lim[1] 	- x_lim[0]) - 2 - (-2) - The span of the complex plane.
// ... / WIN_X 	- gives how much a complex unit in the plan worth in mlx pixel
// * *x 		- gives how much the current value in mlx_pixel worth in the complex plane
static void	plot_set_coords_to_cmplx(double *x, double *y, t_pln *pln)
{
	*x = pln->x_min + ((pln->x_max - pln->x_min) / WIN_X) * *x;
	*y = pln->y_max - ((pln->y_max - pln->y_min) / WIN_Y) * *y;
}

static double	plot_get_iter_max_for_comp_coords(double x, double y, t_ui *ui)
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

// 31/03 - Here 2
int	plot_colorize_mlx_coords(double x, double y, t_ui *ui)
{
	int		basecolors[2];
	int		pal_size;
	double	iter_max;
	int		*palette;

	plot_set_coords_to_cmplx(&x, &y, &ui->pln);
	iter_max = plot_get_iter_max_for_comp_coords(x, y, core);
	if (iter_max < 0) // 31/03 - move iter_max guard to plot_get_iter_max_for_comp_coords, wtf this is doing there?
		iter_max = 0.0;

	palette = core->pal_con.palettes[core->pal_con.current];
	pal_size = color_palettes_len(palettes);
	if (iter_max == MAX_ITER)
		return (palette[pal_size]); //

	// 31/03 - Is that a new interpolation necessary?
	basecolors[0] = palette[(int)iter_max % pal_size];
	basecolors[1] = palette[((int)iter_max + 1) % pal_size];
	return (color_interpolate(basecolors[0], basecolors[1],
			iter_max - (int)iter_max));
}
