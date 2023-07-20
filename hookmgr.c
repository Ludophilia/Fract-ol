/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/20 18:20:30 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hookmgr.h"

int	hook_key_events_manage(int keycode, t_fra *mlx_data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(mlx_data->mlx_ptr);
	return (0);
}
