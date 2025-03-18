/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:45:30 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/18 16:56:22 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void	print_colors(int *colors, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
		printf("#%i - %#x\n", i + 1, colors[i]);
	printf("\n");
	return ;
}

int	*load_palette(int *colors, int nb)
{
	int	*palette;
	int	i;

	palette = calloc(6, sizeof(int));
	i = -1;
	while (++i < nb)
		palette[i] = colors[i];
	return (palette);
}

int	**load_palettes(void)
{
	int	**palette;

	palette = (int **)calloc(4, sizeof(int *));
	palette[0] = load_palette((int [6]){ 0x120272, 0x44bcfc, 0xffffff,
		0xfaa502, 0xcb2600, 0x000000}, 6);
	palette[1] = load_palette((int [6]){ 0x1, 0x2, 0x3,
		0x4, 0x5, 0x000000}, 6);
	palette[2] = load_palette((int [6]){ 0x1A, 0x2B, 0x3C,
		0x4D, 0x5e, 0x000000}, 6);
	palette[3] = NULL;
	return (palette);
}

void	free_palettes(int **palettes)
{
	int	i;

	i = -1;
	while (palettes[++i])
		free(palettes[i]);
	free(palettes);
}

int	main(void)
{
	int	**palette;

	palette = load_palettes();
	print_colors(palette[0], 6);
	print_colors(palette[1], 6);
	print_colors(palette[2], 6);
	free_palettes(palette);
	return (0);
}
