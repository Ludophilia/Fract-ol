/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:36:03 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/22 19:45:28 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOTTER_H

# define PLOTTER_H

# include "fractol_common.h"
# include "colormgr.h"

int		plot_colorize_mlx_coords(double x, double y, t_fra *fra_data);
void	plot_set_complex_plane_limits(double min, double max, t_pln *com_pln);
void	plot_change_comp_plane_zoom_level(int zoom_in, t_pln *com_pln);

#endif