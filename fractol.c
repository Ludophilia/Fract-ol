/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:50 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/13 00:15:09 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void) // argc, argv, envp?
{
	t_mlx	mlx_data;
	t_inp	user_inp;

	ft_bzero(&mlx_data, sizeof(t_mlx)); // In another function. // init img_con too?
	ft_bzero(&user_inp, sizeof(t_inp)); // In another function, type sanicheck, like init_project
	if (init_scene(&mlx_data) == -1 || init_image(&mlx_data) == -1) // In another function, type sanicheck.
		return (1);
	draw_on_scene(&mlx_data);
	register_events(&mlx_data);
	wait_for_events(&mlx_data);
	destroy_scene(&mlx_data);
	return (0);
}
