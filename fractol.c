/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:50 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/03 17:46:01 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_on_scene(t_mlx *mlx_data)
{
	t_img	*img_con;

	img_con = &(mlx_data->img_con);
	img_con->img_ptr = mlx_new_image(mlx_data->mlx_ptr, WINDOW_X, WINDOW_Y);
	if (img_con->img_ptr == NULL)
		return (-1);

	img_con->addr = mlx_get_data_addr(img_con->img_ptr, &img_con->bpp,
		&img_con->szl, &img_con->end);

	// You should mod the addr to mod the img
	// 0x00FF0000 // #FF0000
	int	x, y;

	y = -1;
	while (++y < WINDOW_Y)
	{
		x = -1;
		while (++x < WINDOW_X)
			((int *)img_con->addr)[x + y * img_con->szl / (img_con->bpp / 8)] = 
				0x00 << 24 | 0xFF << 16 | 0x00 << 8 | 0x00;
	}

	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr,
		img_con->img_ptr, 0, 0);
	ft_printf("[DEBUG] addr: %p, bpp: %i, szl: %i, end: %i\n",
		img_con->addr, img_con->bpp, img_con->szl, img_con->end);
	// Move that elsewhere
	mlx_destroy_image(mlx_data->mlx_ptr, img_con->img_ptr);
	return (0);
}

int	main(void)
{
	t_mlx	mlx_data;

	ft_bzero(&mlx_data, sizeof(t_mlx));
	if (init_scene(&mlx_data) == -1 || draw_on_scene(&mlx_data) == -1)
		return (1);
	register_events(&mlx_data);
	wait_for_events(&mlx_data);
	destroy_scene(&mlx_data);
	return (0);
}
