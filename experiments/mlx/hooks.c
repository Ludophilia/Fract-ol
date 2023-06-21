/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/21 14:11:52 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

#define ESC_KEY 65307 

// int	test0_hook(void)
// {
// 	printf("Event:\n");
// 	return (0);
// }

int	test_key_hook(int keycode, void *param)
{
	printf("[keycode : %i]\n", keycode);
	if (keycode == ESC_KEY)
	{
		mlx_loop_end(((t_mlx *)param)->mlx_ptr);
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
