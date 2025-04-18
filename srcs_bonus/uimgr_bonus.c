/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uimgr_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:03 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/18 21:30:46 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	uib_destroy(int target, t_ui *ui)
{
	if (target & TG_IMG)
		mlx_destroy_image(ui->mlx, ui->img);
	if (target & TG_WIN)
		mlx_destroy_window(ui->mlx, ui->win);
	if (target & TG_DIS)
		mlx_destroy_display(ui->mlx);
	if (target & TG_MLX)
		free(ui->mlx);
	return (1);
}

void	uib_loop(t_ui *ui)
{
	mlx_loop(ui->mlx);
}

static void	uib_events_register(t_ui *ui)
{
	mlx_key_hook(ui->win, hookb_key_event_manage, ui);
	mlx_mouse_hook(ui->win, hookb_mouse_event_manage, &ui->pln);
	mlx_loop_hook(ui->mlx, hookb_loop_event_manage, ui);
	mlx_hook(ui->win, DestroyNotify, NoEventMask, mlx_loop_end, ui->mlx);
}

int	uib_init(t_ui *ui)
{
	ui->mlx = mlx_init();
	if (ui->mlx == NULL)
		return (-1);
	ui->win = mlx_new_window(ui->mlx, WIN_X, WIN_Y, WINB_NAME);
	if (ui->win == NULL && uib_destroy(TG_MLX | TG_DIS, ui))
		return (-1);
	if (imageb_init(ui) == -1 && uib_destroy(TG_MLX | TG_DIS | TG_WIN, ui))
		return (-1);
	imageb_ui_draw(ui);
	uib_events_register(ui);
	return (0);
}
