/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenemgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/15 01:02:09 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scenemgr.h"

int	init_scene(t_mlx *mlx_data)
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
		mlx_data->win_ptr, manage_key_events, mlx_data);
	mlx_hook(
		mlx_data->win_ptr, DestroyNotify, NoEventMask,
		mlx_loop_end, mlx_data->mlx_ptr);
}

void	wait_for_events(t_mlx *mlx_data)
{
	mlx_loop(mlx_data->mlx_ptr);
}

void	destroy_scene(t_mlx *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img_con.img_ptr);
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->mlx_ptr);
}
