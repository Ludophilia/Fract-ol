/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpt_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:59:45 by jegerman          #+#    #+#             */
/*   Updated: 2025/03/20 12:47:38 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}	t_vars;

int update(t_vars *vars) {
	int	x;

	mlx_clear_window(vars->mlx, vars->win);
	x = 0;
	while (x <= 800)
		mlx_pixel_put(vars->mlx, vars->win, x++, vars->y, 0xFFFFFF);
	if (vars->y > 600)
		vars->y = 0;
	else
		vars->y += 1;
	printf("[DBG] y -> %i\n", vars->y);
	usleep(10 * 1000);
    return 0;
}

int main() {
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Scanlines");
	vars.y = 0;
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_loop(vars.mlx);
	return 0;
}
