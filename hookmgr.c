/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/01 23:13:21 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hookmgr.h"

int	manage_key_events(int keycode, t_mlx *mlx_data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(mlx_data->mlx_ptr);
	return (0);
}
