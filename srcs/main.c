/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:29:38 by jegerman          #+#    #+#             */
/*   Updated: 2025/03/28 16:43:47 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 27/03 - Ok, we've started refactoring...
// perror("fractol");
int	main(int argc, char **argv)
{
	t_core	core;

	if ((cli_get_args(argc, argv, &core) == -1 && ft_dprintf(2, ERR_USAGE))) // Could be moved
		return (1);
	if (color_palettes_build(25, &core) == -1)
		return (2);

	// if ((scene_init(core) == -1 || image_init(core) == -1)
	// 	&& ft_dprintf(2, ERR_MLX_INIT)
	// 	&& color_palettes_free(core->pal_con.palettes, 0))
	// 	return (-1);
	// plot_set_complex_plane_limits(-2, 2, &core->com_pln);
	// image_draw(&core);
	// scene_events_register(&core);
	// scene_events_wait(&core);
	// scene_destroy(&core);
	return (0);
}
