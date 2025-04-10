/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:29:38 by jegerman          #+#    #+#             */
/*   Updated: 2025/04/10 18:48:13 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 10/04 - Double buffer to improve fluidity
// 10/04 - Understand 1 - log() better...
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
