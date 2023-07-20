/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:36:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/20 13:51:05 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOTTER_H

# define PLOTTER_H

# include "fractol_common.h"
# include "colormgr.h"

# define RADIUS 2
# define MAX_ITER 300.00

# define MANDELBROT 0
# define JULIA 1

int	get_color_for_coordinates(double x, double y, t_mlx *mlx_data);

#endif