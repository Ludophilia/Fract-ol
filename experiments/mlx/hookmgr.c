/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/21 19:37:53 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hookmgr.h"


int	test_loop_hook(void) // (void *param)
{
	printf("Loop event fired. But what for?\n");
	return (0);
}

int	test_key_hook(int keycode, void *params)
{
	printf("[keycode : %i]\n", keycode);
	if (keycode == ESC_KEY)
	{
		mlx_loop_end(((t_mlx *)params)->mlx_ptr);
		return (0);
	}
	return (0);
}

int	test_mouse_hook(int button, int x, int y, void *params)
{
	t_mlx	*mlx_data;
	int		offx;
	int		offy;

	printf("[button: %i at (%i, %i)]\n", button, x, y);
	mlx_data = params;
	offy = -1;
	while (++offy < 10) 
	{
		offx = -1;
		while (++offx < 10)
			mlx_pixel_put(mlx_data->mlx_ptr, mlx_data->win_ptr,
			offx + x, offy + y, FORE_COLOR);
	}
	return (0);
}
