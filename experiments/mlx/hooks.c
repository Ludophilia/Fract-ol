/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/21 14:56:04 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

#define ESC_KEY 65307 

int	test_loop_hook(void *params) // void *param;
{
	(void)params;
	printf("Loop event fired.\n");
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
	int	*head;

	head = (int *)params;
	printf("[button: %i at (%i, %i)]\n", button, x, y);
	if (params == NULL)
		return (-1);
	while (*head)
		printf("param == %i\n", *head++);
	return (0);
}
