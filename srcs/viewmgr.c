/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewmgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/10 18:46:32 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	view_chg_zoom_lvl(int zoom_in, t_pln *pln)
{
	double	zoom;

	zoom = ZOOM_LVL;
	if (zoom_in)
		zoom = 1.0 / ZOOM_LVL;
	*pln = (t_pln){.x_min = pln->x_min * zoom, .x_max = pln->x_max * zoom,
		.y_min = pln->y_min * zoom, .y_max = pln->y_max * zoom};
	return (1);
}

static int	view_map_iter_to_color(double iter, t_fra *fra)
{
	t_rgb	col;
	double	ni;

	ni = iter / fra->max_iter;
	col.r = (255 / 2) * (1 + sin(2 * PI * ni + (3 * PI / 2)));
	col.g = (255 / 2) * (1 + sin(2 * PI * ni + (11 * PI / 6)));
	col.b = (255 / 2) * (1 + sin(2 * PI * ni + (1 * PI / 6)));
	return ((col.r << 16) | (col.g << 8) | col.b);
}

int	view_colorize_coords(t_pnt *pt, t_ui *ui)
{
	int		color;
	double	iter;
	t_pnt	cpt;

	cpt = plot_get_cmplx_coords(pt, &ui->pln);
	iter = plot_get_max_iter(&cpt, &ui->fra);
	if (iter == ui->fra.max_iter)
		return (0x0);
	color = view_map_iter_to_color(iter, &ui->fra);
	return (color);
}
