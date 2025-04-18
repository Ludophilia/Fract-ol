/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/18 20:59:55 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	hookb_key_event_manage(int keycode, t_ui *ui)
{
	if (keycode == XK_Escape)
		mlx_loop_end(ui->mlx);
	else if (keycode == XK_space)
		ui->pln = (t_pln){.x_min = -2, .y_min = -2, .x_max = 2, .y_max = 2};
	else if (keycode >= XK_Left && keycode <= XK_Down)
		viewb_shift_plane(keycode, SHIFT_FACTOR, &ui->pln);
	else if (keycode == XK_d)
		viewb_shift_color(CLSH_FWD, &ui->fra);
	else if (keycode == XK_s)
		viewb_shift_color(CLSH_BCK, &ui->fra);
	else if (keycode == XK_a)
		viewb_shift_color(CLSH_RST, &ui->fra);
	return (0);
}

int	hookb_mouse_event_manage(int button, int x, int y, t_pln *pln)
{
	t_pnt	pt;

	pt = (t_pnt){x, y};
	if (button == 4)
		viewb_chg_zoom_lvl(ZOOM_IN, &pt, pln);
	else if (button == 5)
		viewb_chg_zoom_lvl(ZOOM_OUT, &pt, pln);
	return (0);
}

int	hookb_loop_event_manage(t_ui *ui)
{
	imageb_ui_draw(ui);
	return (0);
}
