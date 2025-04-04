/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/04 17:09:10 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	plot_chg_zoom_lvl(int zoom_in, t_pln *pln)
{
	double	zoom;

	zoom = ZOOM_LVL;
	if (zoom_in)
		zoom = 1.0 / ZOOM_LVL;
	*pln = (t_pln){.x_min = pln->x_min * zoom, .x_max = pln->x_max * zoom,
		.y_min = pln->y_min * zoom, .y_max = pln->y_max * zoom};
	return (1);
}

static t_pnt	plot_get_cmplx_coords(t_pnt *pt, t_pln *pln)
{
	t_pnt	cpt;

	cpt.x = pln->x_min + ((pln->x_max - pln->x_min) / WIN_X) * pt->x;
	cpt.y = pln->y_max - ((pln->y_max - pln->y_min) / WIN_Y) * pt->y;
	return (cpt);
}

// 04/01 - IMPROVE that smoothing shi.
static double	plot_is_seq_unstable(double complex z, double *iter)
{
	double	zcj_sq;

	zcj_sq = creal(z) * creal(z) + cimag(z) * cimag(z);
	if (zcj_sq > RADIUS * RADIUS)
	{
		*iter += 1 - log2((log10(zcj_sq) / 2) / log10(RADIUS));
		if (*iter < 0)
			*iter = 0.0;
		return (1);
	}
	return (0);
}

static double	plot_get_max_iter(t_pnt *pt, t_ui *ui)
{
	t_pnt			cpt;
	double complex	z;
	double			iter;

	cpt = plot_get_cmplx_coords(pt, &ui->pln);
	z = 0;
	if (ui->cli.ftype == JULIA)
		z = cpt.x + cpt.y * I;
	iter = -1;
	while (++iter < MAX_ITER)
	{
		if (plot_is_seq_unstable(z, &iter) == true)
			return (iter);
		z *= z;
		if (ui->cli.ftype == MANDELBROT)
			z += cpt.x + cpt.y * I;
		else if (ui->cli.ftype == JULIA)
			z += ui->cli.creal + ui->cli.cimag * I;
	}
	return (MAX_ITER);
}

// 04/04 - Is that a new interpolation necessary? 
//		1 / Yeah, it helps add things more, but maybe I can remove it to test...
//		2 / Or maybe I should remove the first interpolation used to create the
//		enriched palette in the first place
int	plot_colorize_coords(t_pnt *pt, t_ui *ui)
{
	int		*palette;
	int		pal_len;
	int		icolor;
	double	iter;

	palette = ui->pals[ui->pal_i];
	pal_len = 0;
	while (palette[pal_len])
		++pal_len;
	iter = plot_get_max_iter(pt, ui);
	if (iter == MAX_ITER)
		return (0x0);
	icolor = color_interpolate(palette[(int)iter % pal_len],
			palette[((int)iter + 1) % pal_len], iter - (int)iter);
	return (icolor);
}
