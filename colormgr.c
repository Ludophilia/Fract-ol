/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/20 12:15:40 by jgermany         ###   ########.fr       */
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

static int	*init_palette(int *basecolors, int colors_per_gr)
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

static int	*create_palette(int *basecolors, int colors_per_gr)
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

int	load_palettes(int colors_per_gradient, t_mlx *mlx_data)
{
	int	**palettes;
	int	i;

	i = -1;
	palettes = ft_calloc(2, sizeof(int *));
	if (palettes == NULL)
		return (-1);
	palettes[0] = create_palette((int [6]){0x120272, 0x44bcfc, 0xffffff,
			0xfaa502, 0xcb2600, 0x000000}, colors_per_gradient);
	palettes[1] = NULL;
	while (++i < 1)
	{
		if (palettes[i] == NULL)
		{
			free_palettes(palettes, i - 1);
			return (-1);
		}
	}
	mlx_data->pal_con.palettes = palettes;
	mlx_data->pal_con.current = 0;
	mlx_data->pal_con.size = 1;
	return (0);
}

void	free_palettes(int **palettes, int from)
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
