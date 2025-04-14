/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/14 18:38:49 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static double complex	plotb_get_next_bship(double complex z,
	t_pnt *cpt)
{
	z = (cabs(creal(z)) - I * cabs(cimag(z))) * (cabs(creal(z)) - I * cabs(cimag(z))); // 15/04
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
		if (plot_is_seq_unstable(z, &iter) == true)
			return (iter);
		if (fra->ftype == SHIP)
			z = plotb_get_next_bship(z, cpt);
		else
			z = plotb_get_next_manjul(z, cpt, fra);
	}
	return (max_iter);
}
