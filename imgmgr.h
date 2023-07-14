/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:42 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/13 21:47:41 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMGMGR_H

# define IMGMGR_H

# include "fractol_common.h"
# include "plotter.h"

int	init_image(t_mlx *mlx_data);
int	draw_on_image(t_mlx *mlx_data, t_inp *uinp);

#endif
