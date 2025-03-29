/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uimgr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:03 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/29 19:27:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ui_destroy(int target, t_core *core)
{
	if (target & TG_MLX)
		free(core->ui.mlx);
	if (target & TG_DIS)
		mlx_destroy_display(core->ui.mlx);
	if (target & TG_WIN)
		mlx_destroy_window(core->ui.mlx, core->ui.win);
	if (target & TG_IMG)
		mlx_destroy_image(core->ui.mlx, core->ui.img);
	if (target & TG_PALS)
		color_palettes_free(0, core->ui.pals);
	return (1);
}

void	ui_loop(t_core *core)
{
	mlx_loop(core->ui.mlx);
}

void	ui_events_register(t_core *core)
{
	t_ui	ui;

	ui = core->ui;
	mlx_key_hook(ui.win, hook_key_events_manage, core);
	mlx_mouse_hook(ui.win, hook_mouse_events_manage, core);
	mlx_loop_hook(ui.mlx, hook_loop_events_manage, core);
	mlx_hook(ui.win, DestroyNotify, NoEventMask, mlx_loop_end, ui.mlx);
}

int	ui_init(t_core *core)
{
	core->ui.mlx = mlx_init();
	if (core->ui.mlx == NULL)
		return (-1);

	core->ui.win = mlx_new_window(core->ui.mlx, WIN_X, WIN_Y, WIN_NAME);
	if (core->ui.win == NULL && ui_destroy(TG_MLX | TG_DIS, core))
		return (-1);
	if (image_init(core) == -1 && ui_destroy(TG_MLX | TG_DIS | TG_WIN, core))
		return (-1);
	
	// 30/03 - NEXT
	image_draw(core); // image_ui_draw?


	ui_events_register(core);
	return (0);
}
