/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:29:38 by jegerman          #+#    #+#             */
/*   Updated: 2025/04/22 15:24:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 22/04/25
// - Please think again about how a frame is generated. Calling image_ui_draw(ui)
//  at every frame seem to be a Yandere-Dev tier mistake.
// - While worthing 125, the project still need improvements, especially
// regarding its performance.
int	main(int argc, char **argv)
{
	t_ui	ui;

	if (cli_get_args(argc, argv, &ui.fra) == -1 && ft_dprintf(2, ERR_USAGE))
		return (1);
	if (ui_init(&ui) == -1)
		return (2);
	ui_loop(&ui);
	ui_destroy(TG_ALL, &ui);
	return (0);
}
