/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/03 18:38:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_palettes_free(int from, int **palettes)
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

int	color_interpolate(int basec1, int basec2, double coeff)
{
	t_rgb	color1;
	t_rgb	color2;
	t_rgb	inter;

	color1 = (t_rgb){.r = (basec1 >> 16 & 0xFF), .g = (basec1 >> 8 & 0xFF),
		.b = (basec1 & 0xFF)};
	color2 = (t_rgb){.r = (basec2 >> 16 & 0xFF), .g = (basec2 >> 8 & 0xFF),
		.b = (basec2 & 0xFF)};
	inter.r = color1.r + (color2.r - color1.r) * coeff;
	inter.g = color1.g + (color2.g - color1.g) * coeff;
	inter.b = color1.b + (color2.b - color1.b) * coeff;
	return (inter.r << 16 | inter.g << 8 | inter.b);
}

static int	*color_gradients_build(int *basecol, int size, int cols_per_gr)
{
	int		*gradients;
	t_ijk	ct;
	int		itp_color;

	if (size < 2 || cols_per_gr < 2)
		return (NULL);
	size = cols_per_gr + (size - 2) * (cols_per_gr - 1) + 1;
	gradients = ft_calloc(size, sizeof(int));
	if (gradients == NULL)
		return (NULL);
	ct = (t_ijk){.i = -1, .k = 0};
	while (basecol[++ct.i + 1])
	{
		ct.j = -1;
		while (++ct.j < cols_per_gr)
		{
			itp_color = color_interpolate(basecol[ct.i], basecol[ct.i + 1],
					ct.j / (cols_per_gr - 1.0));
			if (ct.k == 0 || itp_color != gradients[ct.k - 1])
				gradients[ct.k++] = itp_color;
		}
	}
	return (gradients);
}

int	color_palettes_build(int cols_per_gr, t_ui *ui)
{
	int	**palettes;

	palettes = ui->pals;
	palettes[0] = color_gradients_build((int [6]){0x120272, 0x44bcfc, 0xffffff,
			0xfaa502, 0xcb2600, 0}, 5, cols_per_gr);
	if (palettes[0] == NULL)
		return (-1);
	palettes[1] = NULL;
	ui->pal_i = 0;
	ui->pal_nb = 1;
	return (0);
}
