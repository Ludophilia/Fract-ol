/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/20 18:16:13 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colormgr.h"

static int	*color_palette_init(int *basecolors, int colors_per_gr)
{
	int	*palette;
	int	size;

	size = -1;
	while (basecolors[++size])
		;
	if (size < 2 || colors_per_gr < 2)
		return (NULL);
	size = colors_per_gr + (size - 2) * (colors_per_gr - 1) + 1;
	palette = ft_calloc(size, sizeof(int));
	if (palette == NULL)
		return (NULL);
	return (palette);
}

int	color_interpolate(int color1, int color2, double coeff)
{
	uint8_t	rgb[3];

	rgb[0] = (color1 >> 16 & 0xFF) + (int)(((color2 >> 16 & 0xFF)
				- (color1 >> 16 & 0xFF)) * coeff);
	rgb[1] = (color1 >> 8 & 0xFF) + (int)(((color2 >> 8 & 0xFF)
				- (color1 >> 8 & 0xFF)) * coeff);
	rgb[2] = (color1 & 0xFF) + (int)(((color2 & 0xFF)
				- (color1 & 0xFF)) * coeff);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

static int	*color_palette_create(int *basecolors, int colors_per_gr)
{
	int	*palette;
	int	ijk[3];
	int	new_color;

	palette = color_palette_init(basecolors, colors_per_gr);
	if (palette == NULL)
		return (NULL);
	ijk[0] = -1;
	ijk[2] = 0;
	while (basecolors[++ijk[0] + 1])
	{
		ijk[1] = -1; 
		while (++ijk[1] < colors_per_gr)
		{
			new_color = color_interpolate(basecolors[ijk[0]],
					basecolors[ijk[0] + 1],
					(double)ijk[1] / (colors_per_gr - 1));
			if (ijk[2] == 0)
				palette[ijk[2]++] = new_color;
			else if (new_color != palette[ijk[2] - 1])
				palette[ijk[2]++] = new_color;
		}
	}
	palette[ijk[2]] = 0x000000;
	return (palette);
}

void	color_palettes_free(int **palettes, int from)
{
	int	i;
	int	size;

	if (from < 0)
		return ;
	size = -1;
	while (palettes[++size])
		;
	i = from;
	if (i == 0)
		while (i < size)
			free(palettes[i++]);
	else
		while (i >= 0)
			free(palettes[i--]);
	free(palettes);
}

int	color_palettes_load(int colors_per_gradient, t_fra *fra_data)
{
	int	**palettes;
	int	i;

	i = -1;
	palettes = ft_calloc(2, sizeof(int *));
	if (palettes == NULL)
		return (-1);
	palettes[0] = color_palette_create((int [6]){0x120272, 0x44bcfc, 0xffffff,
			0xfaa502, 0xcb2600, 0x000000}, colors_per_gradient);
	palettes[1] = NULL;
	while (++i < 1)
	{
		if (palettes[i] == NULL)
		{
			color_palettes_free(palettes, i - 1);
			return (-1);
		}
	}
	fra_data->pal_con.palettes = palettes;
	fra_data->pal_con.current = 0;
	fra_data->pal_con.size = 1;
	return (0);
}
