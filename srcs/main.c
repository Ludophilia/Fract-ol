/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:29:38 by jegerman          #+#    #+#             */
/*   Updated: 2025/03/30 17:55:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_core	core;

	if (cli_get_args(argc, argv, &core.cli) == -1 && ft_dprintf(2, ERR_USAGE))
		return (1);
	if (ui_init(&core.ui, &core) == -1)
		return (2);
	ui_loop(&core.ui);
	ui_destroy(TG_ALL, &core.ui);
	return (0);
}
