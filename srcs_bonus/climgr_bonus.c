/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:40:20 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/12 15:12:42 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	clib_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (-1);
	if ((argv[1][0] != (MANDELBROT + '0') && argv[1][0] != (JULIA + '0')
			&& argv[1][0] != (SHIP + '0')) || ft_strlen(argv[1]) != 1)
		return (-1);
	i = 1;
	while (argv[++i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (cli_is_full_digit(argv[i], &j) == -1)
			return (-1);
		if ((argv[i][j] == '.' || argv[i][j] == ',')
			&& cli_is_full_digit(argv[i], (++j, &j)) == -1)
			return (-1);
	}
	return (0);
}

int	clib_get_args(int argc, char **argv, t_fra *fra)
{
	int	fra_type;

	if (clib_check_args(argc, argv) == -1)
		return (-1);
	fra_type = ft_atoi(argv[1]);
	if (!((fra_type == MANDELBROT && argc == 2)
		|| (fra_type == JULIA && argc == 4)
		|| (fra_type == SHIP && argc == 2)))
		return (-1);
	fra->ftype = fra_type;
	if (fra_type == 0)
	{
		fra->max_iter = MMAX_ITER;
		return (0);
	}
	fra->creal = cli_atod(argv[2]); // core->usr_inp.zconsrw[0] = argv[2];
	fra->cimag = cli_atod(argv[3]); // core->usr_inp.zconsrw[1] = argv[3];
	fra->max_iter = JMAX_ITER;
	return (0);
}
