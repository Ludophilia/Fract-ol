/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:29:38 by jegerman          #+#    #+#             */
/*   Updated: 2025/03/29 18:59:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_core	core;

	if (cli_get_args(argc, argv, &core) == -1 && ft_dprintf(2, ERR_USAGE))
		return (1);
	if (ui_init(&core) == -1)
		return (2);
	ui_loop(&core);
	ui_destroy(TG_ALL, &core);
	return (0);
}
