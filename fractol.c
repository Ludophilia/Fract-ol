/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:50 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/04 17:51:30 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_image(t_mlx *mlx_data)
{
	t_img	*img_con;

	img_con = &mlx_data->img_con;
	ft_bzero(img_con, sizeof(t_img));
	img_con->img_ptr = mlx_new_image(mlx_data->mlx_ptr, WINDOW_X, WINDOW_Y);
	if (img_con->img_ptr == NULL)
		return (-1);
	img_con->addr = mlx_get_data_addr(img_con->img_ptr, &img_con->bpp,
		&img_con->szl, &img_con->end);
	ft_printf("bpp: %i, szl: %i, end: %i\n", img_con->bpp, img_con->szl,
		img_con->end);
	if (img_con->addr == NULL)
		return (-1);
	return (0);
}

void	colorize_pixel(int start, t_img *img_con, uint32_t color)
{
	int	i;

	i = -1;
	while (++i < (img_con->bpp / 8))
	{
		if (img_con->end == 0)
		{
			img_con->addr[i + start] = color & 0xFF;
			color >>= 8;
		}
		else
		{
			img_con->addr[i + start] = (color >> 24) & 0xFF;
			color <<= 8;
		}
	}
}

int	draw_on_scene(t_mlx *mlx_data, t_img *img_con)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINDOW_Y)
	{
		x = -1;
		while (++x < WINDOW_X)
			colorize_pixel(x * (img_con->bpp / 8) + y * img_con->szl,
				img_con, 0x00008744);
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr,
		img_con->img_ptr, 0, 0);
	return (0);
}

int	main(void)
{
	t_mlx	mlx_data;

	ft_bzero(&mlx_data, sizeof(t_mlx));
	if (init_scene(&mlx_data) == -1 || init_image(&mlx_data) == -1)
		return (1);
	draw_on_scene(&mlx_data, &mlx_data.img_con);
	register_events(&mlx_data);
	wait_for_events(&mlx_data);
	destroy_scene(&mlx_data);
	return (0);
}
