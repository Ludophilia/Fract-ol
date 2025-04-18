/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climgr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:40:20 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/18 22:28:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	clib_is_full_digit(char *str, int *j)
{
	while (ft_isdigit(str[*j]))
	{
		++(*j);
		if (str[*j] == 0 || str[*j] == '.' || str[*j] == ',')
			return (0);
	}
	return (-1);
}

static int	clib_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (-1);
	if ((argv[1][0] != (MANDEL + '0') && argv[1][0] != (JULIA + '0')
			&& argv[1][0] != (SHIP + '0')) || ft_strlen(argv[1]) != 1)
		return (-1);
	i = 1;
	while (argv[++i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (clib_is_full_digit(argv[i], &j) == -1)
			return (-1);
		if ((argv[i][j] == '.' || argv[i][j] == ',')
			&& clib_is_full_digit(argv[i], (++j, &j)) == -1)
			return (-1);
	}
	return (0);
}

static double	clib_atod(char *str)
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

int	clib_get_args(int argc, char **argv, t_fra *fra)
{
	int	fra_typ;

	if (clib_check_args(argc, argv) == -1)
		return (-1);
	fra_typ = ft_atoi(argv[1]);
	if (!((fra_typ == MANDEL && argc == 2) || (fra_typ == JULIA && argc == 4)
			|| (fra_typ == SHIP && argc == 2)))
		return (-1);
	fra->ftype = fra_typ;
	fra->off_col = 0;
	if (fra_typ == JULIA)
	{
		fra->creal = clib_atod(argv[2]);
		fra->cimag = clib_atod(argv[3]);
		fra->max_iter = JUL_ITMX;
		return (0);
	}
	if (fra_typ == MANDEL)
		fra->max_iter = MAN_ITMX;
	else if (fra_typ == SHIP)
		fra->max_iter = SHP_ITMX;
	return (0);
}
