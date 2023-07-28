/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:15:22 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/28 15:16:38 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colormgr_bonus.h"

int	color_palettes_check(int **palettes, t_fra *fra_data)
{
	int	i;

	i = -1;
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
	fra_data->pal_con.size = PALETTE_SIZE;
	return (0);
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
