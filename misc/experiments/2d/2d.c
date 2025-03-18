/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:42:17 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/08 15:46:00 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define X 10
#define Y 5

void	fill_arr(int (*arr)[X])
{
	int	x, y;

	y = -1;
	while (++y < Y)
	{
		x = -1;
		while (++x < X)
			arr[y][x] = x + y;
	}
}

void	print_arr(int arr[Y][X])
{
	int	x, y;

	y = -1;
	while (++y < Y)
	{
		x = -1;
		while (++x < X)
			printf("(%i, %i) = %i\n", x, y, arr[y][x]);
		printf("\n");
	}
}

int	main(void)
{
	int	iteration_counts[Y][X];

	fill_arr(iteration_counts);
	print_arr(iteration_counts);
	return (0);
}
