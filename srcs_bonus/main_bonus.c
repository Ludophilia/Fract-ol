/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:35:34 by jegerman          #+#    #+#             */
/*   Updated: 2025/04/12 16:07:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int argc, char **argv)
{
	t_ui	ui;

	if (clib_get_args(argc, argv, &ui.fra) == -1 && ft_dprintf(2, ERR_USAGE))
		return (1);
	if (uib_init(&ui) == -1)
		return (2);
	ui_loop(&ui);
	ui_destroy(TG_ALL, &ui);
	return (0);
}
