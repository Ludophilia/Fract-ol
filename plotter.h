/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:36:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/21 22:03:01 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOTTER_H

# define PLOTTER_H

# include "fractol_common.h"
# include "colormgr.h"

int	plot_coords_color_get(double x, double y, t_fra *fra_data);

#endif