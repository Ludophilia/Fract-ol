/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/05 10:51:41 by jgermany         ###   ########.fr       */
=======
/*   Updated: 2025/03/18 18:26:55 by jegerman         ###   ########.fr       */
>>>>>>> a0bf469 (V1.5 or 2 development started. Simplified the project by removing extra source header, consolidated them into one.)
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

static int	*color_palette_build(int *basecolors, int colors_per_gr)
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

int	color_palettes_build(int colors_per_gradient, t_core *core)
{
	int	**palettes;

	palettes = ft_calloc(PALETTE_SIZE + 1, sizeof(int *));
	if (palettes == NULL)
		return (-1);
	palettes[0] = color_palette_build((int [6]){0x120272, 0x44bcfc, 0xffffff,
			0xfaa502, 0xcb2600, 0x000000}, colors_per_gradient);
	palettes[1] = color_palette_build((int [7]){0x8C00FF, 0xFFBF00, 0xFF0000,
			0x00F7FF, 0xFF00FF, 0xFBFF00, 0x000000}, colors_per_gradient);
	palettes[2] = color_palette_build((int [8]){0xFFBF00, 0xFBFF00, 0x00F7FF,
			0x8C00FF, 0xFF00FF, 0x95FF00, 0xFF0000, 0x000000},
			colors_per_gradient);
	palettes[3] = color_palette_build((int [6]){0xffffff, 0xc6c6c6, 0x919191,
			0x5e5e5f, 0x303031, 0x000000}, colors_per_gradient);
	palettes[PALETTE_SIZE] = NULL;
	color_palettes_check(palettes, core);
	return (0);
}

void	color_palettes_shift(int straight, t_pal *palette)
{
	uchar	current;

	current = palette->current;
	if (straight)
		current++;
	else
		current--;
	palette->current = current % PALETTE_SIZE;
}
