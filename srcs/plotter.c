/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/03 18:58:34 by jegerman         ###   ########.fr       */
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
			.y_min = pln->y_min * zoom, .y_min = pln->y_max * zoom};
	return (1);
}

static t_pnt	plot_get_cmplx_coords(t_pnt *pt, t_pln *pln)
{
	t_pnt	cpt;

	cpt.x = pln->x_min + ((pln->x_max - pln->x_min) / WIN_X) * pt->x;
	cpt.y = pln->y_max - ((pln->y_max - pln->y_min) / WIN_Y) * pt->y;
	return (cpt);
}

static double	plot_get_max_iter(t_pnt *pt, t_ui *ui)
{
	t_pnt			cpt;
	double complex	z;
	double			zcj_sq;
	int				i;

	cpt = plot_get_cmplx_coords(pt, &ui->pln);
	z = 0;
	if (ui->cli.ftype == JULIA)
		z = cpt.x + cpt.y * I;
	i = -1;
	while (++i < MAX_ITER)
	{
		zcj_sq = creal(z) * creal(z) + cimag(z) * cimag(z);
		if (zcj_sq > RADIUS * RADIUS)
			return (i + 1 - log2((log10(zcj_sq) / 2) / log10(RADIUS))); // if (iter_max < 0) iter_max = 0.0;
		z *= z;
		if (ui->cli.ftype == MANDELBROT)
			z += (cpt.x + cpt.y * I);
		else if (ui->cli.ftype == JULIA)
			z += ui->cli.creal + ui->cli.cimag * I;
	}
	return (MAX_ITER);
}

// 31/03 - Here 2
int	plot_colorize_coords(t_pnt *pt, t_ui *ui)
{
	double	iter;
	int		basecolors[2];
	int		*pal;
	int		pal_size;

	iter = plot_get_max_iter(pt, ui);

	pal = ui->pals[ui->pal_i];

	pal_size = 0;
	while (pal[pal_size])
		++pal_size;

	if (iter == MAX_ITER)
		return (pal[pal_size]); //

	// 4/04 - Almost done.
	// 31/03 - Is that a new interpolation necessary?
	basecolors[0] = pal[(int)iter % pal_size];
	basecolors[1] = pal[((int)iter + 1) % pal_size];
	return (color_interpolate(basecolors[0], basecolors[1],
			iter_max - (int)iter_max));
}
