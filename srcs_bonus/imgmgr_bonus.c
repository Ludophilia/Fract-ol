/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:47:35 by jegerman          #+#    #+#             */
/*   Updated: 2025/04/14 16:56:10 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	imageb_pixel_colorize(t_pnt *pt, t_ui *ui)
{
	int	color;
	int	px_size;
	int	px_pos;
	int	spx_pos;

	color = viewb_colorize_coords(pt, ui);
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

int	imageb_ui_draw(t_ui *ui)
{
	t_pnt	pt;

	pt.y = -1;
	while (++pt.y < WIN_Y)
	{
		pt.x = -1;
		while (++pt.x < WIN_X)
			imageb_pixel_colorize(&pt, ui);
	}
	mlx_put_image_to_window(ui->mlx, ui->win, ui->img, 0, 0);
	return (0);
}