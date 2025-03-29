/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:38 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/29 19:27:18 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	image_pixel_colorize(int x, int y, t_img *img_con, uint color)
{
	int	i;
	int	start_addr;

	start_addr = x * (img_con->bpp / 8) + y * img_con->szl;
	i = -1;
	while (++i < (img_con->bpp / 8))
	{
		if (img_con->end == 0)
		{
			img_con->addr[i + start_addr] = color & 0xFF;
			color >>= 8;
		}
		else
		{
			img_con->addr[i + start_addr] = (color >> 24) & 0xFF;
			color <<= 8;
		}
	}
	return ;
}

// 30/03 - NEXT
int	image_draw(t_core *core)
{
	int	cord[2];
	int	color;

	// plot_set_complex_plane_limits

	cord[1] = -1;
	while (++cord[1] < WIN_Y)
	{
		cord[0] = -1;
		while (++cord[0] < WIN_X)
		{
			color = plot_colorize_mlx_coords(cord[0], cord[1], core);
			image_pixel_colorize(cord[0], cord[1], &core->img_con, color);
		}
	}
	mlx_put_image_to_window(core->mlx_ptr, core->win_ptr,
		core->img_con.img_ptr, 0, 0);
	return (0);
}

int	image_init(t_core *core)
{
	t_ui	ui;

	ui = core->ui;
	ui.img = mlx_new_image(ui.mlx, WIN_X, WIN_Y);
	if (ui.img == NULL)
		return (-1);
	ui.img_adr = mlx_get_data_addr(ui.img, &ui.img_bpp, &ui.img_szl,
		&ui.img_end);
	if ((ui.img_adr == NULL || color_palettes_build(25, &core) == -1)
		&& ui_destroy(TG_IMG, core))
		return (-1);
	return (0);
}
