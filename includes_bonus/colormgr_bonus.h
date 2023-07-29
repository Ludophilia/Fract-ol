/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormgr_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:52:28 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/28 15:33:01 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORMGR_BONUS_H

# define COLORMGR_BONUS_H

# include "fractol_common_bonus.h"

int		color_interpolate(int color1, int color2, double coeff);
int		color_palettes_load(int colors_per_gradient, t_fra *fra_data);
void	color_palettes_free(int **palettes, int from);
int		color_palettes_check(int **palettes, t_fra *fra_data);
void	color_palettes_shift(int straight, t_pal *palette);
#endif