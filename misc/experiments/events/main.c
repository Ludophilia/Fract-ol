/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:50 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/20 13:40:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	destroy_scene(t_mlx *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	// free(mlx_data->win_ptr);
	mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->mlx_ptr);
}

void	wait_for_events(t_mlx *mlx_data)
{
	mlx_loop(mlx_data->mlx_ptr);
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

void	register_events(t_mlx *mlx_data)
{
	mlx_key_hook(
		mlx_data->win_ptr, test_key_hook, mlx_data);
	mlx_mouse_hook(
		mlx_data->win_ptr, test_mouse_hook, mlx_data);
	mlx_expose_hook(
		mlx_data->win_ptr, test_expose_hook, NULL);
	mlx_loop_hook(
		mlx_data->mlx_ptr, test_loop_hook, mlx_data);
	mlx_hook(
		mlx_data->win_ptr, DestroyNotify, NoEventMask,
		test_destroy_hook, mlx_data);
	mlx_hook(
		mlx_data->win_ptr, MotionNotify, Button1MotionMask,
		test_motion_hook, mlx_data);
}

int		init_scene(t_mlx *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (mlx_data->mlx_ptr == NULL)
		return (-1);
	mlx_data->win_ptr = mlx_new_window(
		mlx_data->mlx_ptr, WINDOW_X, WINDOW_Y, SCENENAME);
	if (!mlx_data->win_ptr)
		return (-1);
	mlx_data->loopcount = 0;
	return (0);
}

int	main(void)
{
	t_mlx	mlx_data;

	if (init_scene(&mlx_data) == -1)
		return (1);
	register_events(&mlx_data);
	draw_on_scene(&mlx_data);
	wait_for_events(&mlx_data);
	destroy_scene(&mlx_data);
	return (0);
}
