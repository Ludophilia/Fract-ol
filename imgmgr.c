/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:38 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/11 19:47:26 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imgmgr.h"
#include <stdio.h>

#define MAX_VALUE	4
#define MAX_ITER	150.00

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

double	test_mandelbrot(double x, double y, int max_iter)
{
	double complex 	z;
	int				i;
	double 			conj_zsq;

	x = -2.0 + ((2.0 - -2.0) / WINDOW_X) * x;
	y = 1.5 - ((1.5 - -1.5) / WINDOW_Y) * y;
	z = 0;
	i = -1;
	while (++i < max_iter)
	{
		conj_zsq = creal(z) * creal(z) + cimag(z) * cimag(z);
		if (conj_zsq > MAX_VALUE)
			return (i + 1 - log2((log10(conj_zsq) / 2) / log10(2)));
		z = (z * z);
		z += (x + y * I);
	}
	return (max_iter);
}

double	test_julia(double x, double y, int max_iter)
{
	double complex 	z;
	int				i;
	double 			conj_zsq;

	x = -2 + ((2.0 - -2.0)  / WINDOW_X) * x;
	y = 1.5 - ((1.5 - -1.5) / WINDOW_Y) * y;
	z = (x + y * I);
	i = -1;
	while (++i < max_iter)
	{
		conj_zsq = creal(z) * creal(z) + cimag(z) * cimag(z);
		if (conj_zsq > MAX_VALUE)
			return (i + 1 - log2((log10(conj_zsq) / 2) / log10(2)));
		z = (z * z);
		z += 0.285;
	}
	return (max_iter);
}

// color1 + (int)((color2 - color1) * coeff)
int	interpolate_colors(int color1, int color2, double coeff)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = (color1 >> 16 & 0xFF) + (int)(((color2 >> 16 & 0xFF)
		- (color1 >> 16 & 0xFF)) * coeff);
	g = (color1 >> 8 & 0xFF) + (int)(((color2 >> 8 & 0xFF)
		- (color1 >> 8 & 0xFF)) * coeff);
	b = (color1 & 0xFF) + (int)(((color2 & 0xFF)
		- (color1 & 0xFF)) * coeff);
	return (r << 16 | g << 8 | b);
}

# define PAL_LEN 6

int	colorize_fractal(double iter_max)
	{
	int color1;
	int	color2;
	int	ic1;
	int	ic2;

	int	palette[6] = {
		0x120272,
		0x44BCFC,
		0xFFFFFF,
		0xFAA502,
		0xCB2600,
		0x000000
	};
	if (iter_max == MAX_ITER)
		return (palette[(int)(iter_max * (PAL_LEN - 1) / MAX_ITER)]);
	ic1 = (int)(iter_max) % PAL_LEN;
	ic2 = ((int)(iter_max) + 1) % PAL_LEN;
	color1 = palette[ic1];
	color2 = palette[ic2];
	return (interpolate_colors(color1, color2, 1));
	return (interpolate_colors(color1, color2, iter_max - (int)iter_max));
}

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
