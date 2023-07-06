/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:38 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/06 22:34:04 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imgmgr.h"
#include <stdio.h>

#define WHITE		0x00FFFFFF
#define BLACK		0x00000000
#define RED			0x00FF0000
#define GREEN		0x0000FF00
#define BLUE		0x000000FF

#define MAX_VALUE	50.0
#define MAX_ITER	100

// Need a struct or something to store the window and plane info?

// -1, -1.75, -0.4 + 0.6 * I, -0.2 + 0.7 * I, I
// -0.835 - 0.2321 * I, -0.608 + 0.510 * I, -0.25 + 0.646 * I
// 0.3; Can't see it because no black zones. Only color
// gradients will give me something here.

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
	// ft_printf("bpp: %i, szl: %i, end: %i\n", img_con->bpp, img_con->szl,
		// img_con->end);
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

	i = -1;
	x = -2.0 + ((2.0 - -2.0) / WINDOW_X) * x;
	y = 1.0 - ((1.0 - -1.0) / WINDOW_Y) * y;
	z = 0;
	while (++i < max_iter)
	{
		if (sqrt(z * conj(z)) > MAX_VALUE)
			return (i);
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
	y = 1.0 - ((1.0 - -1.0) / WINDOW_Y) * y;
	z = (x + y * I);
	while (++i < max_iter)
	{
		if (sqrt(z * conj(z)) > MAX_VALUE)
			return (i);
		z = (z * z);
		z += 0.3;//-0.4 + 0.6 * I;
	}
	return (max_iter);
}

// The idea now is to start from base colors and then use the iter_max to
// generate new colors close to the original...
int	colorize_fractal(int iter_max)
{
	if (iter_max == MAX_ITER)
		return BLACK;
	else
		return 0x00011C40 + 8 * iter_max;

	// else if ((iter_max / 10) == 1)
	// 	return 0x00022859;
	// else if ((iter_max / 10) == 2)
	// 	return 0x00033E8C;
	// else if ((iter_max / 10) == 3)
	// 	return 0x00034AA6;


	// else if ((iter_max / 10) == 4)
		// return 0x00FFCC0D; // Yellow
	// else if ((iter_max / 10) == 5)
	// 	return 0x00FF7326;
	// else if ((iter_max / 10) == )
	// 	return 0xBF2669;
	// else if ((iter_max / 10) == 9)
	// 	return 0xFF194D;
	// else
	// 	return WHITE;
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
