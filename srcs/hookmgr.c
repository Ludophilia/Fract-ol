/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/03 15:14:57 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_key_event_manage(int keycode, t_ui *ui)
{
	if (keycode == XK_Escape)
		mlx_loop_end(ui->mlx);
	return (0);
}

int	hook_mouse_event_manage(int button, int x, int y, t_pln *pln)
{
	(void)x;
	(void)y;
	if ((button == 4 && plot_chg_zoom_lvl(ZOOM_IN, pln) == -1)
		|| (button == 5 && plot_chg_zoom_lvl(ZOOM_OUT, pln) == -1))
		return (-1);
	return (0);
}

int	hook_loop_event_manage(t_ui *ui)
{
	image_ui_draw(ui);
	return (0);
}
