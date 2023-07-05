/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgmgr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:54:42 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/05 20:19:21 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMGMGR_H

# define IMGMGR_H

# include "fractol_common.h"

int	init_image(t_mlx *mlx_data);
int	draw_on_scene(t_mlx *mlx_data, t_img *img_con);

#endif
