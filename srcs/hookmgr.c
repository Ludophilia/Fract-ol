/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/29 16:17:09 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_key_events_manage(int keycode, t_core *core)
{
	if (keycode == XK_Escape)
		mlx_loop_end(core->mlx_ptr);
	return (0);
}

int	hook_mouse_events_manage(int button, int x, int y, t_core *core)
{
	t_pln	*com_pln;

	(void) x;
	(void) y;
	com_pln = &core->com_pln;
	if (button == 4)
		plot_change_zoom_level(1, com_pln);
	else if (button == 5)
		plot_change_zoom_level(0, com_pln);
	return (0);
}

int	hook_loop_events_manage(t_core *core)
{
	image_draw(core);
	return (0);
}
