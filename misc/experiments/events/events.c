/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/21 18:19:13 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	test_expose_hook(void)
{
	printf("Expose event happened...\n");
	return (0);
}

int	test_destroy_hook(void *params)
{
	printf("Destroy event happened...\n");
	mlx_loop_end(((t_mlx *)params)->mlx_ptr);
	return (0);
}

int	test_motion_hook(int x, int y, t_mlx *mlx_data)
{
	int		offx;
	int		offy;

	printf("Motion event happened...\n");
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

int	test_loop_hook(t_mlx *mlx_data) // (void *params)
{
	mlx_data->loopcount++;
	if ((mlx_data->loopcount % (2 * 100 * 1000)) == 0)
		printf("loop #%i\n", mlx_data->loopcount);
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
