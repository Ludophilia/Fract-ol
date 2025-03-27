/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:40:20 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/27 19:57:06 by jegerman         ###   ########.fr       */
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

static int	cli_check_validity(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (-1);
	i = 1;
	if ((argv[i][0] != MANDELBROT + '0' && argv[i][0] != JULIA + '0')
		|| ft_strlen(argv[i]) != 1)
		return (-1);
	while (argv[++i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (cli_is_full_digit(argv[i], &j) == -1)
			return (-1);
		if ((argv[i][j] == '.' || argv[i][j] == ',')
			&& j++ && cli_is_full_digit(argv[i], &j) == -1)
			return (-1);
	}
	return (0);
}

static double	cli_atod(char *str)
{
	t_fpn	nbr;
	int		i;

	nbr = (t_fpn){.sign = 1, .mant = 0, .exp = -1};
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			nbr.sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) || (str[i] && i && ft_isdigit(str[i + 1])))
	{
		if ((str[i] == '.' || str[i] == ',') && (nbr.exp++, i++))
			continue ;
		nbr.mant = 10 * nbr.mant + (str[i] - '0');
		if (nbr.exp >= 0)
			nbr.exp++;
		i++;
	}
	if (nbr.exp == -1)
		return (nbr.sign * nbr.mant);
	return (nbr.sign * nbr.mant * pow(10, -nbr.exp));
}

int	cli_get_args(int argc, char **argv, t_core *core)
{
	int	fra_type;

	if (cli_check_validity(argc, argv) == -1)
		return (-1);
	fra_type = ft_atoi(argv[1]);
	if (!((fra_type == 0 && argc == 2) || (fra_type == 1 && argc == 4)))
		return (-1);
	ft_bzero(core, sizeof(t_core));
	core->cli.ftype = fra_type;
	// ft_printf("ftype -> %i\n", core->cli.ftype);
	if (fra_type == 0)
		return (0);
	core->cli.creal = cli_atod(argv[2]);
	core->cli.cimag = cli_atod(argv[3]);
	// printf("creal -> %.6f\n", core->cli.creal);
	// printf("cimag -> %.6f\n", core->cli.cimag);
	return (0);
}
