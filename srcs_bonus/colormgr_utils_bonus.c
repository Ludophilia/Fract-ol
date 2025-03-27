/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:15:22 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/27 15:35:08 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	color_palettes_free(int **palettes, int from)
{
	int	i;

	i = from;
	while (i < PALETTE_SIZE)
	{
		if (palettes[i] != NULL)
			free(palettes[i]);
		i++;
	}
	free(palettes);
}

int	color_palettes_check(int **palettes, t_core *core)
{
	int	i;

	i = -1;
	while (++i < PALETTE_SIZE)
	{
		if (palettes[i] == NULL)
		{
			color_palettes_free(palettes, 0);
			return (-1);
		}
	}
	core->pal_con.palettes = palettes;
	core->pal_con.current = 0;
	core->pal_con.size = PALETTE_SIZE;
	return (0);
}

int	color_interpolate(int color1, int color2, double coeff)
{
	uchar	rgb[3];

	rgb[0] = (color1 >> 16 & 0xFF) + (int)(((color2 >> 16 & 0xFF)
				- (color1 >> 16 & 0xFF)) * coeff);
	rgb[1] = (color1 >> 8 & 0xFF) + (int)(((color2 >> 8 & 0xFF)
				- (color1 >> 8 & 0xFF)) * coeff);
	rgb[2] = (color1 & 0xFF) + (int)(((color2 & 0xFF)
				- (color1 & 0xFF)) * coeff);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
