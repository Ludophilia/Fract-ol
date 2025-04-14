/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/14 18:06:30 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol_bonus.h"

// int	color_palettes_build(int colors_per_gradient, t_core *core)
// {
// 	int	**palettes;

// 	palettes = ft_calloc(PALETTE_SIZE + 1, sizeof(int *));
// 	if (palettes == NULL)
// 		return (-1);
// 	palettes[0] = color_palette_build((int [6]){0x120272, 0x44bcfc, 0xffffff,
// 			0xfaa502, 0xcb2600, 0x000000}, colors_per_gradient);
// 	palettes[1] = color_palette_build((int [7]){0x8C00FF, 0xFFBF00, 0xFF0000,
// 			0x00F7FF, 0xFF00FF, 0xFBFF00, 0x000000}, colors_per_gradient);
// 	palettes[2] = color_palette_build((int [8]){0xFFBF00, 0xFBFF00, 0x00F7FF,
// 			0x8C00FF, 0xFF00FF, 0x95FF00, 0xFF0000, 0x000000},
// 			colors_per_gradient);
// 	palettes[3] = color_palette_build((int [6]){0xffffff, 0xc6c6c6, 0x919191,
// 			0x5e5e5f, 0x303031, 0x000000}, colors_per_gradient);
// 	palettes[PALETTE_SIZE] = NULL;
// 	color_palettes_check(palettes, core);
// 	return (0);
// }

// void	color_palettes_shift(int straight, t_pal *palette)
// {
// 	uchar	current;

// 	current = palette->current;
// 	if (straight)
// 		current++;
// 	else
// 		current--;
// 	palette->current = current % PALETTE_SIZE;
// }
