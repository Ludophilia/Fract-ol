/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenemgr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:03 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/11 18:47:41 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// int	ui_init(t_core *core)
// {
// 	core->mlx_ptr = mlx_init();
// 	if (core->mlx_ptr == NULL)
// 		return (-1);
// 	core->win_ptr = mlx_new_window(
// 			core->mlx_ptr, WIN_X, WIN_Y, WIN_NAME);
// 	if (!core->win_ptr)
// 		return (-1);
// 	return (0);
// }

// void	ui_events_register(t_core *core)
// {
// 	mlx_key_hook(
// 		core->win_ptr, hook_key_event_manage, core);
// 	mlx_mouse_hook(
// 		core->win_ptr, hook_mouse_event_manage, core);
// 	mlx_loop_hook(
// 		core->mlx_ptr, hook_loop_event_manage, core);
// 	mlx_hook(
// 		core->win_ptr, DestroyNotify, NoEventMask,
// 		mlx_loop_end, core->mlx_ptr);
// }

// void	ui_loop(t_core *core)
// {
// 	mlx_loop(core->mlx_ptr);
// }

// void	ui_destroy(t_core *core)
// {
// 	mlx_destroy_image(core->mlx_ptr, core->img_con.img_ptr);
// 	mlx_destroy_window(core->mlx_ptr, core->win_ptr);
// 	mlx_destroy_display(core->mlx_ptr);
// 	free(core->mlx_ptr);
// 	color_palettes_free(core->pal_con.palettes, 0);
// }
