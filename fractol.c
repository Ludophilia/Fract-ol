/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:50 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/14 02:40:49 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

// double ft_atod() - converts a string to a double 
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

double	ft_atod(const char *nptr)
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

int	main(int argc, char **argv)
{
	t_mlx	mlx_data;
	t_inp	user_inp;

	if (argc < 2) // and mandelbrot ??
	{
		ft_dprintf(2, "error: argc = %i\n", argc);
		return (1);
	}

	// I need something to check if this is okay...
	ft_bzero(&mlx_data, sizeof(t_mlx)); // In another function. // init img_con too?
	ft_bzero(&user_inp, sizeof(t_inp)); // In another function, type sanicheck, like init_project
	if (init_scene(&mlx_data) == -1 || init_image(&mlx_data) == -1) // In another function, type sanicheck.
		return (1);
	user_inp.fract = ft_atoi(argv[1]);
	if (argc == 4)
	{
		user_inp.zcons[0] = ft_atod(argv[2]);
		user_inp.zcons[1] = ft_atod(argv[3]); // if this does not exist, should be replaced by zero
		dprintf(2, "argv[2] == %.15lf, argv[3] == %.15lf\n", user_inp.zcons[0], user_inp.zcons[1]);
	}

	draw_on_image(&mlx_data, &user_inp);
	register_events(&mlx_data);
	wait_for_events(&mlx_data);
	destroy_scene(&mlx_data);
	return (0);
}
