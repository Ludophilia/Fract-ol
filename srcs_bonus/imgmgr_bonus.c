/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:38 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/18 18:27:05 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	image_init(t_fra *fra_data)
{
	t_img	*img_con;

	img_con = &fra_data->img_con;
	ft_bzero(img_con, sizeof(t_img));
	img_con->img_ptr = mlx_new_image(fra_data->mlx_ptr, WINDOW_X, WINDOW_Y);
	if (img_con->img_ptr == NULL)
		return (-1);
	img_con->addr = mlx_get_data_addr(img_con->img_ptr, &img_con->bpp,
			&img_con->szl, &img_con->end);
	if (img_con->addr == NULL)
		return (-1);
	return (0);
}

static void	image_pixel_colorize(int x, int y, t_img *img_con, uint32_t color)
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

int	image_draw(t_fra *fra_data)
{
	int	cord[2];
	int	color;

	cord[1] = -1;
	while (++cord[1] < WINDOW_Y)
	{
		cord[0] = -1;
		while (++cord[0] < WINDOW_X)
		{
			color = plot_colorize_mlx_coords(cord[0], cord[1], fra_data);
			image_pixel_colorize(cord[0], cord[1], &fra_data->img_con, color);
		}
	}
	mlx_put_image_to_window(fra_data->mlx_ptr, fra_data->win_ptr,
		fra_data->img_con.img_ptr, 0, 0);
	return (0);
}
