/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/15 17:52:44 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static double complex	plotb_get_next_bship(double complex z, t_pnt *cpt)
{
	// z = fabs(creal(z)) - I * fabs(cimag(z));
	// z *= z; // fabs(creal(z)) - I * fabs(cimag(z));
	// double	re_abs;
	// double	im_abs;

	// re_abs = fabs(creal(z));
	// im_abs = fabs(cimag(z));
	// z = re_abs * re_abs - im_abs * im_abs;
	// z += 2 * I * re_abs * im_abs;
	z = fabs(creal(z)) * fabs(creal(z));
	z += 2 * I * fabs(creal(z)) * fabs(cimag(z));
	z -= fabs(cimag(z)) * fabs(cimag(z));
	z += cpt->x + cpt->y * I;
	return (z);
}

static double complex	plotb_get_next_manjul(double complex z, t_pnt *cpt,
	t_fra *fra)
{
	z *= z;
	if (fra->ftype == MANDELBROT)
		z += cpt->x + cpt->y * I;
	else if (fra->ftype == JULIA)
		z += fra->creal + fra->cimag * I;
	return (z);
}

double	plotb_get_max_iter(t_pnt *cpt, t_fra *fra)
{
	double complex	z;
	double			iter;
	double			max_iter;

	z = 0;
	if (fra->ftype == JULIA)
		z = cpt->x + cpt->y * I;
	max_iter = fra->max_iter;
	iter = -1;
	while (++iter < max_iter)
	{
		if (plot_does_seq_escape(z, &iter) == true)
			return (iter);
		if (fra->ftype == SHIP)
			z = plotb_get_next_bship(z, cpt);
		else
			z = plotb_get_next_manjul(z, cpt, fra);
	}
	return (max_iter);
}
