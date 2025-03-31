/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:38 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/31 16:44:25 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	image_pixel_colorize(int x, int y, int color, t_ui *ui)
{
	int	px_size;
	int	px_pos;
	int	spx_pos;
	
	px_size = ui->img_bpp / BYTE_FROM_BIT;
	px_pos = x * px_size + y * ui->img_szl;
	spx_pos = -1;
	while (++spx_pos < px_size)
	{
		if (ui->img_end == LIL_ENDIAN)
		{
			ui->img_adr[px_pos + spx_pos] = color & 0xFF;
			color >>= 8;
		}
		else if (ui->img_end == BIG_ENDIAN)
		{
			ui->img_adr[px_pos + spx_pos] = (color >> (ui->img_bpp - 8)) & 0xFF;
			color <<= 8;
		}
	}
}

int	image_ui_draw(t_ui *ui)
{
	int	x;
	int	y;
	int	color;

	plot_set_limits(-2, 2, &ui->pln);
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			// 31/03 - Here 2
			color = plot_colorize_mlx_coords(x, y, ui);
			image_pixel_colorize(x, y, color, ui);
		}
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
	if ((ui->img_adr == NULL || color_palettes_build(25, ui) == -1)
		&& ui_destroy(TG_IMG, ui))
		return (-1);
	return (0);
}
