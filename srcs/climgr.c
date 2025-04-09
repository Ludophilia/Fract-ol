/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:40:20 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/09 17:48:14 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	cli_is_full_digit(char *str, int *j)
{
	while (ft_isdigit(str[*j]))
	{
		++(*j);
		if (str[*j] == 0 || str[*j] == '.' || str[*j] == ',')
			return (0);
	}
	return (-1);
}

static int	cli_check_arg_validity(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (-1);
	if ((argv[1][0] != (MANDELBROT + '0') && argv[1][0] != (JULIA + '0'))
		|| ft_strlen(argv[1]) != 1)
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

static double	cli_atod(char *str)
{
	t_fpn	nbr;
	int		i;
	int		is_fpn;

	nbr = (t_fpn){.sign = 1, .mant = 0, .exp = 0};
	is_fpn = 0;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i++] == '-')
		nbr.sign *= -1;
	while (ft_isdigit(str[i]) || (i && str[i] && ft_isdigit(str[i + 1])))
	{
		if ((str[i] == '.' || str[i] == ',') && (i++, ++is_fpn))
			continue ;
		nbr.mant = 10 * nbr.mant + (str[i] - '0');
		if (i++, is_fpn)
			nbr.exp--;
	}
	return (nbr.sign * nbr.mant * pow(10, nbr.exp));
}

int	cli_get_args(int argc, char **argv, t_cli *cli)
{
	int	fra_type;

	if (cli_check_arg_validity(argc, argv) == -1)
		return (-1);
	fra_type = ft_atoi(argv[1]);
	if (!((fra_type == 0 && argc == 2) || (fra_type == 1 && argc == 4)))
		return (-1);
	cli->ftype = fra_type;
	if (fra_type == 0)
	{
		cli->max_iter = MMAX_ITER;
		return (0);
	}
	cli->creal = cli_atod(argv[2]);
	cli->cimag = cli_atod(argv[3]);
	cli->max_iter = JMAX_ITER;
	return (0);
}
