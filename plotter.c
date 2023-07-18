/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:34:12 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/18 11:13:48 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plotter.h"

static double	get_iter_max(double x, double y, t_inp *uinp)
{
	double complex	z;
	double			conjz_sq;
	int				i;

	x = -2 + ((2.0 - -2.0) / WINDOW_X) * x;
	y = 2 - ((2.0 - -2.0) / WINDOW_Y) * y;
	if (uinp->fract == MANDELBROT)
		z = 0;
	else
		z = x + y * I;
	i = -1;
	while (++i < MAX_ITER)
	{
		conjz_sq = creal(z) * creal(z) + cimag(z) * cimag(z);
		if (conjz_sq > RADIUS * RADIUS)
			return (i + 1 - log2((log10(conjz_sq) / 2) / log10(RADIUS)));
		z = (z * z);
		if (uinp->fract == MANDELBROT)
			z += (x + y * I);
		else
			z += uinp->zcons[0] + uinp->zcons[1] * I;
	}
	return (MAX_ITER);
}

static int	interpolate_colors(int color1, int color2, double coeff)
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


// So... What to do?

int	get_color_for_iter_max(double iter_max)
{
	int color1;
	int	color2;
	int	ic1;
	int	ic2;

	int	palette[110] = { // G dragon
		0x120272, 0x0e0d79, 0x08167f, 0x011e86, 0x00258c, 0x002c92, 0x003398,
		0x003a9e, 0x0040a4, 0x0047aa, 0x004daf, 0x0054b5, 0x005aba, 0x0061bf,
		0x0067c4, 0x006ec9, 0x0074ce, 0x007bd2, 0x0081d7, 0x0088db, 0x008ee0,
		0x0095e4, 0x079be8, 0x1aa2ec, 0x26a8f0, 0x31aff4, 0x3bb5f8,
		0x44bcfc, 0x51befc, 0x5cc1fc, 0x66c3fd, 0x6fc6fd, 0x77c8fd, 0x7fcbfd,
		0x87cdfd, 0x8ecffd, 0x95d2fd, 0x9cd4fe, 0xa2d7fe, 0xa9d9fe, 0xafdcfe,
		0xb5defe, 0xbce1fe, 0xc2e3fe, 0xc7e6fe, 0xcde8fe, 0xd3ebff, 0xd9edff,
		0xdef0ff, 0xe4f2ff, 0xe9f5ff, 0xeff7ff, 0xf4faff, 0xfafcff,
		0xffffff, 0xfffcf7, 0xfff8ee, 0xfff5e6, 0xfff1de, 0xffeed6, 0xffeace,
		0xffe7c5, 0xffe4bd, 0xffe0b5, 0xffddad, 0xffd9a5, 0xffd69d, 0xffd395,
		0xffcf8d, 0xffcc84, 0xffc97c, 0xffc574, 0xffc26c, 0xffbf63, 0xffbc5b,
		0xffb852, 0xffb549, 0xffb23f, 0xfeaf35, 0xfdab29, 0xfba81b,
		0xfaa502, 0xf9a100, 0xf79d00, 0xf69800, 0xf59400, 0xf39000, 0xf28c00,
		0xf08800, 0xef8300, 0xed7f00, 0xec7b00, 0xea7700, 0xe87200, 0xe76e00,
		0xe56900, 0xe36500, 0xe16000, 0xe05c00, 0xde5700, 0xdc5300, 0xda4e00,
		0xd84900, 0xd64400, 0xd43e00, 0xd23900, 0xcf3300, 0xcd2d00,
		0xcb2600, 0x000000
	};
	if (iter_max == MAX_ITER)
		return (palette[(int)(iter_max * (PAL_LEN - 1) / MAX_ITER)]);
	ic1 = (int)(iter_max) % PAL_LEN;
	ic2 = ((int)(iter_max) + 1) % PAL_LEN;
	color1 = palette[ic1];
	color2 = palette[ic2];
	// return (interpolate_colors(color1, color2, 1));
	return (interpolate_colors(color1, color2, iter_max - (int)iter_max));
}


int	get_color_for_coordinates(double x, double y, t_inp *uinp)
{
	double	iter_max;
	int	color;

	iter_max = get_iter_max(x, y, uinp);
	color = get_color_for_iter_max(iter_max);
	// Here should be the code for managing colors... get_color_for_iter_max()
	return (color); // Returns a color (improve this)
}
