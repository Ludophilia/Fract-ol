/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/05 19:28:45 by jegerman         ###   ########.fr       */
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

int	color_interpolate(int bc1, int bc2, double coeff)
{
	t_rgb	icl;
	t_rgb	c1;
	t_rgb	c2;

	c1 = (t_rgb){(bc1 >> 16) & 0xFF, (bc1 >> 8) & 0xFF, bc1 & 0xFF};
	c2 = (t_rgb){(bc2 >> 16) & 0xFF, (bc2 >> 8) & 0xFF, bc2 & 0xFF};
	icl.r = c1.r + (c2.r - c1.r) * coeff;
	icl.g = c1.g + (c2.g - c1.g) * coeff;
	icl.b = c1.b + (c2.b - c1.b) * coeff;
	return (icl.r << 16 | icl.g << 8 | icl.b);
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

// (int [6]){0x120272, 0x44bcfc, 0xffffff, 0xfaa502, 0xcb2600, 0}
int	color_palettes_build(t_ui *ui)
{
	int	*basecolr;
	
	basecolr = (int [11]){0x120272, 0x2B5FB7, 0x44BCFC, 0xFFFFFF, 0xFAA502,
				0xE36601, 0xCB2600, 0x70182F, 0x1D1266, 0x10074C, 0};
	// basecolr = (int [7]){0x120272, 0x44bcfc, 0xffffff, 0xfaa502, 0xcb2600, 0x1A0744, 0};
	ui->pals[0] = color_gradients_build(basecolr, 10, 30);
	if (ui->pals[0] == NULL)
		return (-1);
	ui->pals[1] = NULL;
	ui->pal_i = 0;
	ui->pal_nb = 1;
	return (0);
}
