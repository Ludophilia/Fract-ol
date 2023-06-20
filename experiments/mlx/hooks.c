/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:09:27 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/20 19:34:04 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	test_hook(void)
{
	printf("Event:\n");
	return (0);
}

int	mah_key_hook(int keycode, void *params, void *params2)
{
	int	*head;

	head = (int *)params; 
	while (*head)
		printf("[keycode: %i], params == %i, params2 == %i\n", 
			keycode, *head++, *(int *)params2);
	printf("\n");
	return (0);
}

int	mah_mouse_hook(int button, int x, int y, void *params)
{
	int	*head;

	head = (int *)params;
	printf("[button: %i at (%i, %i)]\n", button, x, y);
	if (params == NULL)
		return (0);
	while (*head)
		printf("param == %i\n", *head++);
	return (0);
}

// void	hide_and_seek(void *mlx_ptr, void *win_ptr)
// {
// 	int		count;

// 	count = 10;
// 	while (count--)
// 	{
// 		mlx_mouse_hide(mlx_ptr, win_ptr);
// 		sleep(1);
// 		mlx_mouse_show(mlx_ptr, win_ptr);
// 	}
// }
