/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clichecker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:40:20 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/18 18:26:52 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	cli_atod_pre_process(const char *nptr, int64_t *nb, int8_t *s)
{
	int32_t	i;

	i = 0;
	*s = 1;
	nb[0] = 0;
	nb[1] = -1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			*s *= -1;
		i++;
	}
	return (i);
}

static double	cli_atod(const char *nptr)
{
	int64_t	nb[2];
	int8_t	s;
	int32_t	i;

	i = cli_atod_pre_process(nptr, nb, &s);
	while (ft_isdigit(nptr[i]) || ((nptr[i] == '.' || nptr[i] == ',')
			&& ft_isdigit(nptr[i + 1])))
	{
		if (ft_isdigit(nptr[i]))
		{
			nb[0] = 10 * nb[0] + nptr[i] - '0';
			if (nb[1] >= 0)
				nb[1]++;
		}
		else if (nptr[i] == '.' || nptr[i] == ',')
			nb[1] = 0;
		i++;
	}
	if (nb[1] == -1)
		return (s * nb[0]);
	return (s * nb[0] * pow(10, -nb[1]));
}

static int	cli_is_full_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isdigit(str[i]) == 0)
		return (-1);
	while (ft_isdigit(str[i]))
	{
		if (str[i + 1] == 0)
			return (0);
		i++;
	}
	if (str[i] == '.' || str[i] == ',')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (str[i + 1] == 0)
			return (0);
		i++;
	}
	return (-1);
}

static int	cli_args_check(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (-1);
	if (cli_is_full_digit(argv[1]) == -1)
		return (-1);
	i = 1;
	while (argv[++i])
	{
		if (cli_is_full_digit(argv[i]) == -1)
			return (-1);
	}
	return (0);
}

int	cli_args_get(int argc, char **argv, t_fra *fra_data)
{
	int32_t	fract_type;

	if (cli_args_check(argc, argv) == -1)
	{
		errno = EINVAL;
		return (-1);
	}
	ft_bzero(fra_data, sizeof(t_fra));
	fract_type = ft_atoi(argv[1]);
	if ((fract_type < 0 || fract_type > 2) || (fract_type == 0 && argc != 2)
		|| (fract_type == 2 && argc != 2) || (fract_type == 1 && argc != 4))
	{
		errno = EINVAL;
		return (-1);
	}
	fra_data->usr_inp.fract = fract_type;
	if (fract_type == 1)
	{
		fra_data->usr_inp.zcons[0] = cli_atod(argv[2]);
		fra_data->usr_inp.zcons[1] = cli_atod(argv[3]);
		fra_data->usr_inp.zconsrw[0] = argv[2];
		fra_data->usr_inp.zconsrw[1] = argv[3];
	}
	return (0);
}
