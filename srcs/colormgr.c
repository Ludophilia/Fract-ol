/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/29 14:20:51 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_palettes_free(int **palettes, int from)
{
	int	i;
	int	size;

	size = 0;
	while (palettes[size])
		++size;
	i = from;
	while (i < size)
	{
		if (palettes[i])
			free(palettes[i]);
		++i;
	}
}

int	color_interpolate(int base_c1, int base_c2, double coeff)
{
	t_rgb	c1;
	t_rgb	c2;
	t_rgb	ci;

	c1 = (t_rgb){.r = (base_c1 >> 16 & 0xFF), .g = (base_c1 >> 8 & 0xFF),
		.b = (base_c1 & 0xFF)};
	c2 = (t_rgb){.r = (base_c2 >> 16 & 0xFF), .g = (base_c2 >> 8 & 0xFF),
		.b = (base_c2 & 0xFF)};
	ci.r = c1.r + (c2.r - c1.r) * coeff;
	ci.g = c1.g + (c2.g - c1.g) * coeff;
	ci.b = c1.b + (c2.b - c1.b) * coeff;
	return (ci.r << 16 | ci.g << 8 | ci.b);
}

static int	*color_gradient_build(int *basecol, int size, int cols_per_gr)
{
	int		*gradient;
	t_cnt	ct;
	int		itp_color;

	if (size < 2 || cols_per_gr < 2)
		return (NULL);
	size = cols_per_gr + (size - 2) * (cols_per_gr - 1) + 1;
	gradient = ft_calloc(size, sizeof(int));
	if (gradient == NULL)
		return (NULL);
	ct = (t_cnt){.i = -1, .k = 0};
	while (basecol[++ct.i + 1])
	{
		ct.j = -1;
		while (++ct.j < cols_per_gr)
		{
			itp_color = color_interpolate(basecol[ct.i], basecol[ct.i + 1],
					ct.j / (cols_per_gr - 1.0));
			if (ct.k == 0 || itp_color != gradient[ct.k - 1])
				gradient[ct.k++] = itp_color;
		}
	}
	return (gradient);
}

int	color_palettes_build(int cols_per_gr, t_core *core)
{
	int	**palettes;

	palettes = core->win.pal_arr;
	palettes[0] = color_gradient_build((int [6]){0x120272, 0x44bcfc, 0xffffff,
			0xfaa502, 0xcb2600, 0}, 5, cols_per_gr);
	if (palettes[0] == NULL)
		return (-1);
	palettes[1] = NULL;
	core->win.pal_curr = 0;
	core->win.pal_size = 1;
	return (0);
}
