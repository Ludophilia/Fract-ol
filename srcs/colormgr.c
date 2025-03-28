/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/28 19:37:28 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 28/03 - What should be freed now that some of those things are on the stack?
void	color_palettes_free(int **palettes, int from)
{
	int	i;
	int	size;

	size = -1;
	while (palettes[++size])
		;
	i = from;
	while (i < size)
	{
		if (palettes[i])
			free(palettes[i]);
		i++;
	}
	// free(palettes);
}

// 28/03 - Make it clearer?
int	color_interpolate(int color1, int color2, double coeff)
{
	char	rgb[3];

	rgb[0] = (color1 >> 16 & 0xFF) + (int)(((color2 >> 16 & 0xFF)
				- (color1 >> 16 & 0xFF)) * coeff);
	rgb[1] = (color1 >> 8 & 0xFF) + (int)(((color2 >> 8 & 0xFF)
				- (color1 >> 8 & 0xFF)) * coeff);
	rgb[2] = (color1 & 0xFF) + (int)(((color2 & 0xFF)
				- (color1 & 0xFF)) * coeff);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

static int	*color_palette_build(int *basecolors, int size, int colors_per_gr)
{
	int		*palette;
	t_cnt	count;
	int		itp_color;

	if (size < 2 || colors_per_gr < 2)
		return (NULL);
	size = colors_per_gr + (size - 2) * (colors_per_gr - 1) + 1;
	// e.g - 2 Basecolors, 6 Colors_per_gradient
	// BCC CCB N

	// e.g - 3 Basecolors, 6 Colors_per_gradient
	// BCC CCB
	//  CC CCB N

	palette = ft_calloc(size, sizeof(int));
	if (palette == NULL)
		return (NULL);
	count = (t_cnt){.i = -1, .k = 0};
	while (basecolors[++count.i + 1])
	{
		count.j = -1;
		while (++count.j < colors_per_gr)
		{
			itp_color = color_interpolate(basecolors[count.i],
					basecolors[count.i + 1],
					(double)count.j / (colors_per_gr - 1));
			if (count.k == 0 || itp_color != palette[count.k - 1])
				palette[count.k++] = itp_color;
		}
	}

	palette[count.k] = 0;
	return (palette);
}

int	color_palettes_build(int colors_per_gradient, t_core *core)
{
	int	**palettes;

	palettes = core->win.pal_arr;
	palettes[0] = color_palette_build((int [6]){0x120272, 0x44bcfc, 0xffffff,
		0xfaa502, 0xcb2600, 0}, 5, colors_per_gradient);
	if (palettes[0] == NULL)
		return (-1);
	palettes[1] = NULL;
	core->win.pal_curr = 0;
	core->win.pal_size = 1;
	return (0);
}
