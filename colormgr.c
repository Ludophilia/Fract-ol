/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/19 15:29:13 by jgermany         ###   ########.fr       */
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
	if (size < 2)
		return (NULL);
	size = colors_per_gr + (size - 2) * (colors_per_gr - 1) + 1;
	palette = ft_calloc(size, sizeof(int));
	if (palette == NULL)
		return (NULL);
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
	ijk[2] = -1;
	while (basecolors[++ijk[0] + 1])
	{
		ijk[1] = -1; 
		while (++ijk[1] <= colors_per_gr)
		{
			new_color = interpolate_colors(basecolors[ijk[0]],
					basecolors[ijk[0] + 1], ijk[1] / colors_per_gr);
			if (new_color != palette[ijk[2]])
				palette[++ijk[2]] = new_color;
		}
	}
	palette[++ijk[2]] = 0x000000;
	return (palette);
}

int	**load_palettes(void)
{
	int	**palette;

	palette = ft_calloc(4, sizeof(int *));
	palette[0] = create_palette((int [6]){0x120272, 0x44bcfc, 0xffffff,
			0xfaa502, 0xcb2600, 0x000000}, 6);
	palette[1] = create_palette((int [6]){0x1, 0x2, 0x3,
			0x4, 0x5, 0x000000}, 6);
	palette[2] = create_palette((int [6]){0x1A, 0x2B, 0x3C,
			0x4D, 0x5e, 0x000000}, 6);
	palette[3] = NULL;
	return (palette);
}

// What should I do?

// [*] Create the complete palette from int * basecolors.
// How?
// 		- Calculate the size of a giant arr that would fit every gradients 
// 		from basecolors + 0x000000
// 		- Init this giant array
// 		- Fill the array via iteration on basecolors and increments of .
//		- 
// 		- return the array

// On what should I iterate?
// 		- basecolors: basecolors[i] basecolors[i + 1] until basecolors[i + 1] == 0
//			- coefficient of interpolation between those two colors...
//			if 3 colors_per_gr, coeff goes 0/(3 - 1), 1/2, 2/2
//			if 5 colors_per_gr, coeff goes 0/(5 - 1), 1/4, 2/4, 3/4, 4/4
//			- if the color has been already added, skip it...
//			- never add the coeff == 1 case, except if basecolors[i + 2] == 0
//		- 
// 		- palette newly created (just increment tracker each time you add something...)
//