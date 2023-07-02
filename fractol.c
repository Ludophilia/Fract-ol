/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:50 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/02 20:10:22 by jgermany         ###   ########.fr       */
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
	// How to use this shit:
	// char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
	// 		   int *size_line, int *endian);

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
