/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenemgr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:03 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/18 18:27:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	scene_init(t_fra *fra_data)
{
	fra_data->mlx_ptr = mlx_init();
	if (fra_data->mlx_ptr == NULL)
		return (-1);
	fra_data->win_ptr = mlx_new_window(
			fra_data->mlx_ptr, WINDOW_X, WINDOW_Y, SCENENAME);
	if (!fra_data->win_ptr)
		return (-1);
	return (0);
}

void	scene_events_register(t_fra *fra_data)
{
	mlx_key_hook(
		fra_data->win_ptr, hook_key_events_manage, fra_data);
	mlx_mouse_hook(
		fra_data->win_ptr, hook_mouse_events_manage, fra_data);
	mlx_loop_hook(
		fra_data->mlx_ptr, hook_loop_events_manage, fra_data);
	mlx_hook(
		fra_data->win_ptr, DestroyNotify, NoEventMask,
		mlx_loop_end, fra_data->mlx_ptr);
}

void	scene_events_wait(t_fra *fra_data)
{
	mlx_loop(fra_data->mlx_ptr);
}

void	scene_destroy(t_fra *fra_data)
{
	mlx_destroy_image(fra_data->mlx_ptr, fra_data->img_con.img_ptr);
	mlx_destroy_window(fra_data->mlx_ptr, fra_data->win_ptr);
	mlx_destroy_display(fra_data->mlx_ptr);
	free(fra_data->mlx_ptr);
	color_palettes_free(fra_data->pal_con.palettes, 0);
}
