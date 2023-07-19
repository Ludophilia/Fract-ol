/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:52:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/19 19:30:27 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORMGR_H

# define COLORMGR_H

#include "fractol_common.h"

int		interpolate_colors(int color1, int color2, double coeff);
int		load_palettes(int colors_per_gradient, t_mlx *mlx_data);
void	free_palettes(int **palettes, int from);

#endif