/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:36:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/13 21:48:55 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOTTER_H

# define PLOTTER_H

# include "fractol_common.h"

# define RADIUS 2
# define MAX_ITER 300.00

# define PAL_LEN 110

# define MANDELBROT 0
# define JULIA 1

int	get_color_for_coordinates(double x, double y, t_inp *uinp);

#endif