/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewmgr_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:16:25 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/28 15:32:43 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWMGR_BONUS_H

# define VIEWMGR_BONUS_H

# include "fractol_common_bonus.h"

void	view_translate_mlx_coords_to_comp_coords(double *x, double *y,
			t_pln *com_pln);
void	view_set_complex_plane_limits(double min, double max, t_pln *com_pln);
void	view_change_comp_plane_zoom_level(int zoom_in, double x, double y,
			t_pln *com_pln);
void	view_shit_comp_plane(uint8_t shift_direction, t_pln *com_pln);

#endif