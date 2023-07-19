/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/19 18:12:40 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colormgr.h"

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

void	free_palettes(int **palettes)
{
	int	i;

	i = -1;
	while (palettes[++i])
		free(palettes[i]);
	free(palettes);
}

int	*init_palette(int *basecolors, int colors_per_gr)
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

int	*create_palette(int *basecolors, int colors_per_gr)
{
	int	*palette;
	int	ijk[3];
	int	new_color;

	palette = init_palette(basecolors, colors_per_gr);
	if (palette == NULL)
		return (NULL);
	ijk[0] = -1;
	ijk[2] = 0;
	while (basecolors[++ijk[0] + 1])
	{
		ijk[1] = -1; 
		while (++ijk[1] < colors_per_gr)
		{
			new_color = interpolate_colors(basecolors[ijk[0]],
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

int	**load_palettes(void)
{
	int	**palettes;
	int	i;

	i = -1;
	palettes = ft_calloc(2, sizeof(int *));
	if (palettes == NULL)
		return (NULL);
	palettes[0] = create_palette((int [6]){0x120272, 0x44bcfc, 0xffffff,
			0xfaa502, 0xcb2600, 0x000000}, 3);
	palettes[1] = NULL;
	while (++i < 1)
		if (palettes[i] == NULL)
			return (NULL);
	return (palettes);
}
