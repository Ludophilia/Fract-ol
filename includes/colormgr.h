/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:52:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/23 20:36:52 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORMGR_H

# define COLORMGR_H

# include "fractol_common.h"

int		color_interpolate(int color1, int color2, double coeff);
int		color_palettes_load(int colors_per_gradient, t_fra *fra_data);
void	color_palettes_free(int **palettes, int from);

#endif