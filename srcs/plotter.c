/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/15 17:50:41 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pnt	plot_get_cmplx_coords(t_pnt *pt, t_pln *pln)
{
	t_pnt	cpt;

	cpt.x = pln->x_min + ((pln->x_max - pln->x_min) / WIN_X) * pt->x;
	cpt.y = pln->y_max - ((pln->y_max - pln->y_min) / WIN_Y) * pt->y;
	return (cpt);
}

double	plot_does_seq_escape(double complex z, double *iter)
{
	double	zabs_sq;

	zabs_sq = creal(z) * creal(z) + cimag(z) * cimag(z);
	if (zabs_sq > RADIUS * RADIUS)
	{
		*iter += 1 - log(log2(cabs(z)));
		return (1);
	}
	return (0);
}

double	plot_get_max_iter(t_pnt *cpt, t_fra *fra)
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
		z *= z;
		if (fra->ftype == MANDELBROT)
			z += cpt->x + cpt->y * I;
		else if (fra->ftype == JULIA)
			z += fra->creal + fra->cimag * I;
	}
	return (max_iter);
}
