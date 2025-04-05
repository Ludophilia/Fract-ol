/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:38 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/05 19:28:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	image_pixel_colorize(t_pnt *pt, t_ui *ui)
{
	int	color;
	int	px_size;
	int	px_pos;
	int	spx_pos;

	color = plot_colorize_coords(pt, ui);
	px_size = ui->img_bpp / BYTE_FROM_BIT;
	px_pos = pt->x * px_size + pt->y * ui->img_szl;
	spx_pos = -1;
	while (++spx_pos < px_size)
	{
		if (ui->img_end == ENDIAN_LIT)
		{
			ui->img_adr[px_pos + spx_pos] = color & 0xFF;
			color >>= 8;
		}
		else if (ui->img_end == ENDIAN_BIG)
		{
			ui->img_adr[px_pos + spx_pos] = (color >> (ui->img_bpp - 8)) & 0xFF;
			color <<= 8;
		}
	}
}

int	image_ui_draw(t_ui *ui)
{
	t_pnt	pt;

	pt.y = -1;
	while (++pt.y < WIN_Y)
	{
		pt.x = -1;
		while (++pt.x < WIN_X)
			image_pixel_colorize(&pt, ui);
	}
	mlx_put_image_to_window(ui->mlx, ui->win, ui->img, 0, 0);
	return (0);
}

int	image_init(t_ui *ui)
{
	ui->img = mlx_new_image(ui->mlx, WIN_X, WIN_Y);
	if (ui->img == NULL)
		return (-1);
	ui->img_adr = mlx_get_data_addr(ui->img, &ui->img_bpp, &ui->img_szl,
			&ui->img_end);
	if ((ui->img_adr == NULL || color_palettes_build(ui) == -1)
		&& ui_destroy(TG_IMG, ui))
		return (-1);
	ui->pln = (t_pln){.x_min = -2, .y_min = -2, .x_max = 2, .y_max = 2};
	return (0);
}
