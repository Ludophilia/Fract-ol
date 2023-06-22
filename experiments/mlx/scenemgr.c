/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenemgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/22 19:55:13 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scenemgr.h"

int		init_scene(t_mlx *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (mlx_data->mlx_ptr == NULL)
		return (-1);
	mlx_data->win_ptr = mlx_new_window(
		mlx_data->mlx_ptr, WINDOW_X, WINDOW_Y, SCENENAME);
	if (!mlx_data->win_ptr)
		return (-1);
	return (0);
}

void	register_events(t_mlx *mlx_data)
{
	mlx_key_hook(
		mlx_data->win_ptr, test_key_hook, mlx_data);
	mlx_mouse_hook(
		mlx_data->win_ptr, test_mouse_hook, mlx_data);
	mlx_hook(
		mlx_data->win_ptr, DestroyNotify, NoEventMask, 
		test_destroy_hook, mlx_data);
	mlx_hook(
		mlx_data->win_ptr, MotionNotify, Button1MotionMask,
		test_motion_hook, mlx_data);
	mlx_loop_hook(
		mlx_data->win_ptr, test_loop_hook, NULL); // What's for ???
}

void	draw_on_scene(t_mlx *mlx_data)
{
	t_mtx	mtx;
	
	mtx.y = -1;
	while (++mtx.y < WINDOW_Y)
	{
		mtx.x = -1;
		while (++mtx.x < WINDOW_X)
			mlx_pixel_put(mlx_data->mlx_ptr, mlx_data->win_ptr,
			mtx.x, mtx.y, BACK_COLOR);
	}
}

void	wait_for_events(t_mlx *mlx_data)
{
	mlx_loop(mlx_data->mlx_ptr);
}

void	destroy_scene(t_mlx *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	// free(mlx_data->win_ptr);
	mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->mlx_ptr);
}
