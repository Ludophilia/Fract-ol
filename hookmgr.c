/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/22 19:47:37 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hookmgr.h"

int	hook_key_events_manage(int keycode, t_fra *fra_data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(fra_data->mlx_ptr);
	return (0);
}

int	hook_mouse_events_manage(int button, int x, int y, t_fra *fra_data)
{
	t_pln	*com_pln;

	(void) x;
	(void) y;
	com_pln = &fra_data->com_pln;
	if (button == 4)
		plot_change_comp_plane_zoom_level(1, com_pln);
	else if (button == 5)
		plot_change_comp_plane_zoom_level(0, com_pln);
	return (0);
}

int	hook_loop_events_manage(t_fra *fra_data)
{
	image_draw(fra_data);
	return (0);
}
