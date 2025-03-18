/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:50 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/23 13:14:20 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	t_mlx	mlx_data;

	if (init_scene(&mlx_data) == -1)
		return (1);
	register_events(&mlx_data);
	draw_on_scene(&mlx_data);
	wait_for_events(&mlx_data);
	destroy_scene(&mlx_data);
	return (0);
}
