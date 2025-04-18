/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewmgr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:15:56 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/18 22:39:27 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	viewb_shift_plane(int keycode, double factor, t_pln *pln)
{
	if (keycode == XK_Left || keycode == XK_Down)
	{
		factor *= -1;
	}
	if (keycode == XK_Left || keycode == XK_Right)
	{
		pln->x_min += factor * (pln->x_max - pln->x_min);
		pln->x_max += factor * (pln->x_max - pln->x_min);
	}
	else if (keycode == XK_Up || keycode == XK_Down)
	{
		pln->y_min += factor * (pln->y_max - pln->y_min);
		pln->y_max += factor * (pln->y_max - pln->y_min);
	}
}

int	viewb_shift_color(int dir, t_fra *fra)
{
	if (dir == CLSH_RST)
		fra->off_col = 0;
	else if (dir == CLSH_FWD)
		fra->off_col += 2 PI / 6;
	else if (dir == CLSH_BCK)
		fra->off_col -= 2 PI / 6;
	return (0);
}

static int	viewb_map_iter_to_color(double iter, t_fra *fra)
{
	t_rgb	col;
	double	angle;
	t_rgb	off;

	angle = (iter / fra->max_iter) * 2 PI;
	off.r = (3 PI / 2) + fra->off_col;
	off.g = (11 PI / 6) + fra->off_col;
	off.b = (1 PI / 6) + fra->off_col;
	col.r = (255 / 2) * (1 + sin(angle + off.r));
	col.g = (255 / 2) * (1 + sin(angle + off.g));
	col.b = (255 / 2) * (1 + sin(angle + off.b));
	return ((col.r << 16) | (col.g << 8) | col.b);
}

void	viewb_chg_zoom_lvl(int zoom_in, t_pnt *pt, t_pln *pln)
{
	double	zoom;
	t_pnt	pos_ratio;
	t_pnt	range;
	t_pnt	cpt;

	zoom = ZOOM_LVL;
	if (zoom_in)
		zoom = 1.0 / ZOOM_LVL;
	cpt = plotb_get_cmplx_coords(pt, pln);
	pos_ratio.x = pt->x / WIN_X;
	pos_ratio.y = pt->y / WIN_Y;
	range.x = (pln->x_max - pln->x_min);
	range.y = (pln->y_max - pln->y_min);
	pln->x_min = cpt.x - pos_ratio.x * range.x * zoom;
	pln->x_max = cpt.x + (1.0 - pos_ratio.x) * range.x * zoom;
	pln->y_min = cpt.y - (1.0 - pos_ratio.y) * range.y * zoom;
	pln->y_max = cpt.y + pos_ratio.y * range.y * zoom;
}

int	viewb_colorize_coords(t_pnt *pt, t_ui *ui)
{
	int		color;
	double	iter;
	t_pnt	cpt;

	cpt = plotb_get_cmplx_coords(pt, &ui->pln);
	iter = plotb_get_max_iter(&cpt, &ui->fra);
	if (iter == ui->fra.max_iter)
		return (0x0);
	color = viewb_map_iter_to_color(iter, &ui->fra);
	return (color);
}
