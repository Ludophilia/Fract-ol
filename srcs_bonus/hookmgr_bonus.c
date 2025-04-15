/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/15 21:31:08 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	hookb_key_event_manage(int keycode, t_ui *ui)
{

	if (keycode == XK_Escape)
		mlx_loop_end(ui->mlx);
	else if (keycode == XK_space)
		ui->pln = (t_pln){.x_min = -2, .y_min = -2, .x_max = 2, .y_max = 2};

	else if (keycode == XK_Left)
		viewb_shift_plane(SHIFT_LEFT, -SHIFT_FACTOR, &ui->pln);
	else if (keycode == XK_Right)
		viewb_shift_plane(SHIFT_RIGHT, SHIFT_FACTOR, &ui->pln);
	else if (keycode == XK_Up)
		viewb_shift_plane(SHIFT_UP, SHIFT_FACTOR, &ui->pln);
	else if (keycode == XK_Down)
		viewb_shift_plane(SHIFT_DOWN, -SHIFT_FACTOR, &ui->pln);

	// else if (keycode == XK_d)
	// 	color_palettes_shift(1, &core->pal_con);
	// else if (keycode == XK_s)
	// 	color_palettes_shift(0, &core->pal_con);
	return (0);
}

int	hookb_mouse_event_manage(int button, int x, int y, t_pln *pln)
{
	t_pln	*com_pln;

	com_pln = &core->com_pln;
	if (button == 4)
		view_change_comp_plane_zoom_level(1, x, y, com_pln);
	else if (button == 5)
		view_change_comp_plane_zoom_level(0, x, y, com_pln);
	return (0);
}

int	hookb_loop_event_manage(t_ui *ui)
{
	imageb_ui_draw(ui);
	return (0);
}
