/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uimgr_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:03 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/12 17:00:07 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	uib_events_register(t_ui *ui)
{
	mlx_key_hook(ui->win, hookb_key_event_manage, ui);
	mlx_mouse_hook(ui->win, hookb_mouse_event_manage, &ui->pln);
	mlx_loop_hook(ui->mlx, hook_loop_event_manage, ui);
	mlx_hook(ui->win, DestroyNotify, NoEventMask, mlx_loop_end, ui->mlx);
}

int	uib_init(t_ui *ui)
{
	ui->mlx = mlx_init();
	if (ui->mlx == NULL)
		return (-1);
	ui->win = mlx_new_window(ui->mlx, WIN_X, WIN_Y, WIN_NAME);
	if (ui->win == NULL && ui_destroy(TG_MLX | TG_DIS, ui))
		return (-1);
	if (image_init(ui) == -1 && ui_destroy(TG_MLX | TG_DIS | TG_WIN, ui))
		return (-1);
	image_ui_draw(ui);
	uib_events_register(ui);
	return (0);
}
