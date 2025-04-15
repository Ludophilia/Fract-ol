/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewmgr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:15:56 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/15 21:31:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	viewb_shift_plane(int direct, double factor, t_pln *pln)
{
	if (direct == SHIFT_LEFT || direct == SHIFT_RIGHT)
	{
		pln->x_min += factor * (pln->x_max - pln->x_min);
		pln->x_max += factor * (pln->x_max - pln->x_min);
	}
	if (direct == SHIFT_DOWN || direct == SHIFT_UP)
	{
		pln->y_min += factor * (pln->y_max - pln->y_min);
		pln->y_max += factor * (pln->y_max - pln->y_min);
	}
}

void	viewb_change_comp_plane_zoom_level(int zoom_in, double x, double y,
t_pln *com_pln)
{
	double	*x_lim;
	double	*y_lim;
	double	ratios[2];

	x_lim = com_pln->x_lim;
	y_lim = com_pln->y_lim;
	ratios[0] = x / WIN_X;
	ratios[1] = y / WIN_Y;
	view_translate_mlx_coords_to_comp_coords(&x, &y, com_pln);
	if (zoom_in)
	{
		x_lim[0] = x - ratios[0] * ((x_lim[1] - x_lim[0]) / ZOOM_LVL);
		x_lim[1] = x + (1. - ratios[0]) * ((x_lim[1] - x_lim[0]) / ZOOM_LVL);
		y_lim[0] = y - (1. - ratios[1]) * ((x_lim[1] - x_lim[0]) / ZOOM_LVL);
		y_lim[1] = y + ratios[1] * ((x_lim[1] - x_lim[0]) / ZOOM_LVL);
	}
	else
	{
		x_lim[0] = x - ratios[0] * ((x_lim[1] - x_lim[0]) * ZOOM_LVL);
		x_lim[1] = x + (1. - ratios[0]) * ((x_lim[1] - x_lim[0]) * ZOOM_LVL);
		y_lim[0] = y - (1. - ratios[1]) * ((x_lim[1] - x_lim[0]) * ZOOM_LVL);
		y_lim[1] = y + ratios[1] * ((x_lim[1] - x_lim[0]) * ZOOM_LVL);
	}
}

static int	viewb_map_iter_to_color(double iter, t_fra *fra)
{
	t_rgb	col;
	double	ni;

	ni = iter / fra->max_iter;
	col.r = (255 / 2) * (1 + sin(2 * PI * ni + (3 * PI / 2)));
	col.g = (255 / 2) * (1 + sin(2 * PI * ni + (11 * PI / 6)));
	col.b = (255 / 2) * (1 + sin(2 * PI * ni + (1 * PI / 6)));
	return ((col.r << 16) | (col.g << 8) | col.b);
}

int	viewb_colorize_coords(t_pnt *pt, t_ui *ui)
{
	int		color;
	double	iter;
	t_pnt	cpt;

	cpt = plot_get_cmplx_coords(pt, &ui->pln);
	iter = plotb_get_max_iter(&cpt, &ui->fra);
	if (iter == ui->fra.max_iter)
		return (0x0);
	color = viewb_map_iter_to_color(iter, &ui->fra);
	return (color);
}
