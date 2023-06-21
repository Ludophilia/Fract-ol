/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenemgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/21 14:02:34 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scenemgr.h"

int	init_scene(t_mlx *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (mlx_data->mlx_ptr == NULL)
		return (-1);
	mlx_data->win_ptr = mlx_new_window(
		mlx_data->mlx_ptr, 640, 480, "Half Life");
	if (!mlx_data->win_ptr)
		return (-1);
	return (0);
}

// 20/06 - How can I see the events?
// 21/06 - Simple Goal:
//	- How to close the window via ESC and the X button?
//	- 
void	register_events(t_mlx *mlx_data)
{
	mlx_key_hook(
		mlx_data->win_ptr, test_key_hook, mlx_data);
	mlx_mouse_hook(
		mlx_data->win_ptr, test_mouse_hook, NULL); // Array died bc "on stack"
	// mlx_loop_hook(win_ptr, test, NULL);
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
