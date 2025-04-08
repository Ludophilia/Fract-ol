/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/08 20:52:06 by jegerman         ###   ########.fr       */
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
// *iter = *iter + 1 - log((log2(zcj_sq) / 2) / log2(RADIUS));
// *iter += 1 - log(log2(fmax(cabs(z), 1e-8)));
static double	plot_is_seq_unstable(double complex z, double *iter)
{
	double	zcj_sq;

	zcj_sq = creal(z) * creal(z) + cimag(z) * cimag(z);
	if (zcj_sq > RADIUS * RADIUS)
	{
		// *iter = *iter + 1 - log((log2(zcj_sq) / 2) / log2(RADIUS));

		*iter += 1 - log(log2(cabs(z)));
		// *iter += 1 - log(log2(fmax(cabs(z), 1e-8)));
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


// https://magoosh.com/hs/ap/ap-calculus-review-trigonometric-identities/
// 0 deg -> 0 rad
// 120 deg -> 2π/3 or 2.0944 rad
// 180 deg -> π or 3.14 rad
// 240 deg -> 4π/3 or 4.1888 rad
// 360 deg -> 2π or 6.2831 rad


// 8/04 - Giving priority to blue is a good idea to match the old model,
// but there is more tweaking to be done.
unsigned int get_color(double t)
{
	// int r = (int)(127.5 * (1 + sin(6.2831 * t + 0)));       // Red wave
	// int g = (int)(127.5 * (1 + sin(6.2831 * t + 2.0944)));   // Green wave (2π/3 phase)
	// int b = (int)(127.5 * (1 + sin(6.2831 * t + 4.1888)));   // Blue wave (4π/3 phase)

	int r = (int)(127.5 * (1 + sin(6.2831 * t + 4 * PI / 3)));       // 4.1888 Red wave (0deg)
	int g = (int)(127.5 * (1 + sin(6.2831 * t + 4 * PI / 3)));   // 0 Green wave (2π/3 (120deg) phase)
	int b = (int)(127.5 * (1 + sin(6.2831 * t + 0)));   // 2.0944Blue wave (4π/3 (240deg) phase)

	// int r = (int)(127.5 * (1 + sin(6.2831 * t + 2.0944)));       // Red wave
	// int g = (int)(127.5 * (1 + sin(6.2831 * t + 4.1888)));   // Green wave (2π/3 phase)
	// int b = (int)(127.5 * (1 + sin(6.2831 * t + 0)));   // Blue wave (4π/3 phase)

	return ((r << 16) | ((g << 8) ) | (b));
}

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
	// icolor = color_interpolate(palette[(int)(pal_len * (iter / MAX_ITER))],
	// 		palette[(int)(pal_len * (iter / MAX_ITER)) + 1],
	// 		iter - (int)iter);
	icolor = get_color(iter / MAX_ITER);
	return (icolor);
}

