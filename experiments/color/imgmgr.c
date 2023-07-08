/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:38 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/08 23:33:24 by jgermany         ###   ########.fr       */
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

// The idea now is to start from base colors and then use the iter_max to
// generate new colors close to the original...
int	colorize_fractal0(int iter_max)
{
	int color;

	color = 255 - (int)(iter_max * 255 / MAX_ITER); // Pourcent of a hue
	// 255 - (100 * 255/100) // -> 0 (black) when iter_max == 100 == MAX_ITER.
	// 255 - (255/100) -> 255 - 2 // -> 253 (black) when iter_max == 1.
	// 255 - (0.75 * 255) -> 255 - 2 // -> 253 (black) when iter_max == 75.
	return (color << 16 | color << 8 | color); // GREYSCALES SAIKOU
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
	y = 1.5 - ((1.5 - -1.5) / WINDOW_Y) * y;
	z = (x + y * I);
	while (++i < max_iter)
	{
		if ((creal(z) * creal(z) + cimag(z) * cimag(z)) > 4)
			return (i);
		z = (z * z);
		z += -0.2 + 0.7 * I;
	}
	return (max_iter);
}
// -1, -1.75, -0.4 + 0.6 * I (*), -0.2 + 0.7 * I, I (*)
// -0.835 - 0.2321 * I, -0.608 + 0.510 * I, -0.25 + 0.646 * I
// 0.3; 0.285


// int	colorize_fractal(int iter_max)
// {
// 	int	iterations_ppx[WINDOW_Y][WINDOW_X];

// 	// The first pass involves calculating the iteration counts 
// 	// associated with each pixel (but without any pixels being plotted).
// }

int	draw_on_scene(t_mlx *mlx_data, t_img *img_con)
{
	int	x;
	int	y;

	int	iterations_ppx[WINDOW_Y][WINDOW_X]; // IterationCounts
	int	iteration_freq[MAX_ITER]; // NumIterationsPerPixel

	int iter_max;

	ft_bzero(iteration_freq, MAX_ITER * sizeof(int));
	y = -1;
	while (++y < WINDOW_Y)
	{
		x = -1;
		while (++x < WINDOW_X)
		{
			iter_max = test_mandelbrot(x, y, MAX_ITER);
			iterations_ppx[y][x] = iter_max; // first pass
			iteration_freq[iter_max] += 1; // second pass
			// colorize_fractal(iter_max);
			// colorize_pixel(x, y, img_con, color);
		}
	}

//	######################################################################

	// float	hue[WINDOW_Y][WINDOW_X];
	int total;
	// int	i;
	
	iter_max = -1;
	total = 0;
	while (++iter_max < MAX_ITER)
		total += iteration_freq[iter_max]; // third pass

	(void)iterations_ppx;
	// y = -1;
	// while (++y < WINDOW_Y) // fourth pass
	// {
	// 	x = -1;
	// 	while (++x < WINDOW_X)
	// 	{
	// 		iter_max = iterations_ppx[y][x];
	// 		i = -1;
	// 		hue[y][x] = 0;
	// 		while (++i < iter_max)
	// 			hue[y][x] += iteration_freq[i] / total;
	// 	}
	// }

// ######################################################################

	(void)colorize_pixel;

	// int	palette[5] = {
	// 	0xFFFFFF,
	// 	0xFFFFFF,
	// 	0xFFFFFF,
	// 	0xFFFFFF,
	// 	0x0,
	// }; // From low to high iteration. 
	// int	color;

	// y = -1;
	// while (++y < WINDOW_Y)
	// {
	// 	x = -1;
	// 	while (++x < WINDOW_X)
	// 	{
	// 		color = palette[ (int)(hue[y][x] * 5) * 100 ];
	// 		colorize_pixel(x, y, img_con, color);
	// 	}
	// }

//	######################################################################

	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr,
		img_con->img_ptr, 0, 0);
	return (0);
}
