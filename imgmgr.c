/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:38 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/06 16:43:53 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imgmgr.h"
#include <stdio.h>

#define WHITE	0x00FFFFFF
#define BLACK	0x00000000
#define RED		0x00FF0000
#define GREEN	0x0000FF00
#define BLUE	0x000000FF

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

// ############################################################################

// What to do?
// Find a plotting algorithm for the Julia/mandelbrot

// The logic roughly goes like this

// JULIA

// Starting point z(0) = x + yi, matching the point (x, y) on screen.
// Sequence: z = z²+ c, with c being an arbitrary complex

// MANDELBROT

// Starting point z(0) = 0
// Sequence: z = z²+ c, with c being x + yi, matching the point (x, y) on screen.

// The point should be coloured black or white (for now) according to
// if the sequence diverge to infinity or not

// Let's start with the mandelbrot.

// ############################################################################

// Oh, shit, there is like many pitfalls I copmpletely overlooked...

// The mandelbrot set appears between [-2, 1] on Re(z) and [-1.5, 1.5] on Im(z)
// The julia set, between [-1.5, 1.5] on Re(z) and [-1, 1] on Im(z)
// So our complex plane could be [-1.5, 1.5] on Re(z) and [-1.5, 1.5] on Img(z) to start

// Plus, MLX's 0,0 is on the top left when our plan (0, 0) is on the center...
// So we have to find a way to convert the matrix 640x480 (4:3) to somethig close to
// [-2, 2] Re(z) and [1.5, 1.5] Img(z) with 0 in the center.

// So the magic should happen here... It's here that... The x and y coordinates
// on the 640 * 480 WINDOW should be PASSED to test_mandelbrot() and then converted
// to their equivalent on a small 4 * 3 complex plane that starts at -2, -1.5.

// That way... :
// (0,0) 

// (320, 240) should be used to represent (0,0) 

// (640)

int	test_mandelbrot(double x, double y, int max_iter)
{
	double complex 	z;
	int				i;

	i = -1;
	// Need a struct or something to store the window and plane info?
	x = -2 + ((2.0 - -2.0)  / WINDOW_X) * x;
	y = -1 + ((1.0 - -1.0) / WINDOW_Y) * y;
	z = 0;
	while (++i < max_iter) // creal(z) <= 10 && cimg(z) <= 10
	{
		if (creal(z) > 100.0 || cimag(z) > 100.0)
			return (1); // Goes to infinity
		z = (z * z) + (x + y * I);
	}
	// printf("zmax(%i, %i) = %.lf + %.lfi\n", x, y, creal(z), cimag(z));
	return (0); // stable
}

int	test_julia(double x, double y, int max_iter)
{
	double complex 	z;
	int				i;

	i = -1;
	// Need a struct or something to store the window and plane info?
	x = -2 + ((2.0 - -2.0)  / WINDOW_X) * x;
	y = -1 + ((1.0 - -1.0) / WINDOW_Y) * y;
	// printf("x = %lf ; y = %lfi\n", x, y);
	z = (x + y * I);
	// printf("z = %lf + %lfi\n", creal(z), cimag(z));
	while (++i < max_iter) // creal(z) <= 10 && cimg(z) <= 10
	{
		if (creal(z) > 100.0 || cimag(z) > 100.0)
			return (1); // Goes to infinity
		z = (z * z) + 1;
	}
	// printf("zmax(%lf, %lf) = %lf + %lfi\n", x, y, creal(z), cimag(z));
	return (0); // stable
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
			if (test_julia(x, y, 20) == 1)
				color = WHITE;
			else
				color = BLACK;
			colorize_pixel(x, y, img_con, color);
		}
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr,
		img_con->img_ptr, 0, 0);
	return (0);
}