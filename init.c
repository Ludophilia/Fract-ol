/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:40:20 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/15 01:11:30 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static int	pre_process_nb(const char *nptr, int32_t *nb, int8_t *s)
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
		*s *= -1;
		i++;
	}
	return (i);
}

static double	ft_atod(const char *nptr)
{
	int32_t	nb[2];
	int8_t	s;
	int32_t	i;

	i = pre_process_nb(nptr, nb, &s);
	while (ft_isdigit(nptr[i]) || ((nptr[i] == '.' || nptr[i] == ',')
			&& ft_isdigit(nptr[i + 1])))
	{
		if (ft_isdigit(nptr[i]))
			nb[0] = 10 * nb[0] + nptr[i] - '0';
		if (nb[1] >= 0 && ft_isdigit(nptr[i]))
			nb[1]++;
		if (nptr[i] == '.' || nptr[i] == ',')
			nb[1] = 0;
		i++;
	}
	if (nb[1] == -1)
		return (s * nb[0]);
	return (s * nb[0] * pow(10, -nb[1]));
}

static int	is_full_digit(char *str, int is_float)
{
	int	i;
	int	float_checked;
	int	sign_checked;

	i = -1;
	float_checked = 0;
	sign_checked = 0;
	while (str[++i])
	{
		if (is_float && !float_checked && (str[i] == '.' || str[i] == ','))
			float_checked++;
		else if (!sign_checked && (str[i] == '+' || str[i] == '-'))
			sign_checked++;
		else if (ft_isdigit(str[i]) != 1)
			return (-1);
	}
	return (0);
}

static int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		ft_dprintf(2, "error: argc = %i\n", argc);
		return (-1);
	}
	if (is_full_digit(argv[1], 0) == -1)
		return (-1);
	i = 1;
	while (argv[++i])
	{
		if (is_full_digit(argv[i], 1) == -1)
			return (-1);
	}
	return (0);
}

// What should be done...?

// [OK]
// ./fractol 0
// ./fractol 1 0 0

// [NOT]
// ./fractol 0 0 (if argv[1] == 0, argc should be 2)
// ./fractol 1 0 0 3 (if argv[1] == 1, argc should be 4)
// ./fractol "" "" "" "" (args should be comprized of )
// ./fractol a b c ""

// Where to put the error message?
int	init_prog(int argc, char **argv, t_mlx *mlx_data)
{
	int32_t	fract_type;

	if (check_args(argc, argv) == -1)
		return (-1);
	ft_bzero(mlx_data, sizeof(t_mlx));
	fract_type = ft_atoi(argv[1]);
	if ((fract_type < 0 || fract_type > 2) || (fract_type == 0 && argc != 2)
		|| (fract_type == 1 && argc != 4))
		return (-1);
	mlx_data->usr_inp.fract = fract_type;
	if (fract_type == 1)
	{
		mlx_data->usr_inp.zcons[0] = ft_atod(argv[2]);
		mlx_data->usr_inp.zcons[1] = ft_atod(argv[3]);
	}
	if (init_scene(mlx_data) == -1 || init_image(mlx_data) == -1)
		return (-1);
	return (0);
}
