/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:38 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/10 22:51:17 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imgmgr.h"
#include <stdio.h>

#define MAX_VALUE	4
#define MAX_ITER	150

// Need a struct or something to store the window and plane info?
int	init_image(t_mlx *mlx_data)
{
	t_img	*img_con;

	img_con = &mlx_data->img_con;
	ft_bzero(img_con, sizeof(t_img));
	img_con->img_ptr = mlx_new_image(mlx_data->mlx_ptr, WINDOW_X, WINDOW_Y);
	if (img_con->img_ptr == NULL)
		return (-1);
	img_con->addr = mlx_get_data_addr(img_con->img_ptr, &img_con->bpp,
		&img_con->szl, &img_con->end);
	if (img_con->addr == NULL)
		return (-1);
	return (0);
}

static void	colorize_pixel(int x, int y, t_img *img_con, uint32_t color)
{
	int	i;
	int start_addr;

	start_addr = x * (img_con->bpp / 8) + y * img_con->szl;
	i = -1;
	while (++i < (img_con->bpp / 8))
	{
		if (img_con->end == 0)
		{
			img_con->addr[i + start_addr] = color & 0xFF;
			color >>= 8;
		}
		else
		{
			img_con->addr[i + start_addr] = (color >> 24) & 0xFF;
			color <<= 8;
		}
	}
}

int	test_mandelbrot(double x, double y, int max_iter)
{
	double complex 	z;
	int				i;
	double 			conj_zsq;

	i = -1;
	x = -2.0 + ((2.0 - -2.0) / WINDOW_X) * x;
	y = 1.0 - ((1.0 - -1.0) / WINDOW_Y) * y;
	z = 0;
	while (++i < max_iter)
	{
		conj_zsq = creal(z) * creal(z) + cimag(z) * cimag(z);
		if (conj_zsq > MAX_VALUE)
		{
			printf("i = %i; nu = %.4lf\n", i,
				i + 1 - log2((log(conj_zsq) / log(2)) / log(2)));
			return (i);
		}
		z = (z * z);
		z += (x + y * I);
	}
	return (max_iter);
}

int	test_julia(double x, double y, int max_iter)
{
	double complex 	z;
	int				i;

	i = -1;
	x = -2 + ((2.0 - -2.0)  / WINDOW_X) * x;
	y = 1.5 - ((1.5 - -1.5) / WINDOW_Y) * y;
	z = (x + y * I);
	while (++i < max_iter)
	{
		if ((creal(z) * creal(z) + cimag(z) * cimag(z)) > MAX_VALUE)
			return (i);
		// Magical dude.
		z = (z * z);
		z += 0.285;
	}
	return (max_iter);
}

// Give me a palette, maybe try linear interpolation on it. 
// NO HISTOGRAMS. (too costly)

// linear iterpolation(color1, color2, coeff)... Not that difficult actually...

// julia() or mandelbrot() will return a i with decimals (e.g. 1.25)
//		- the whole part of i will give us the arr index of the first
// 		and second color (if possible) to use 
//		- the decimal part will give us the coefficient to plug to the function
//		. The closer it is to 1, and the closer it will be to the second color.
//
int	colorize_fractal(int iter_max)
{
	int	palette[14] = {
		0x120272,
		0x0047aa,
		0x0081d7,
		0x44BCFC,
		0x95d2fd,
		0xcde8fe,
		0xFFFFFF,
		0xffe0b5,
		0xffc26c,
		0xFAA502,
		0xed7f00,
		0xde5700,
		0xCB2600,
		0x000000
	};
	return (palette[iter_max * 13 / MAX_ITER]);
}
// color = 255 - (iter_max * 255 / MAX_ITER);
// return (color << 16 | color << 8 | color);

int	draw_on_scene(t_mlx *mlx_data, t_img *img_con)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	while (++y < WINDOW_Y)
	{
		x = -1;
		while (++x < WINDOW_X)
		{
			color = colorize_fractal(test_mandelbrot(x, y, MAX_ITER));
			colorize_pixel(x, y, img_con, color);
		}
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr,
		img_con->img_ptr, 0, 0);
	return (0);
}
