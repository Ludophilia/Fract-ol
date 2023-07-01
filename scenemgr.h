/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenemgr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:47 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/01 23:04:05 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENEMGR_H

# define SCENEMGR_H

# define WINDOW_X 640
# define WINDOW_Y 480

# define SCENENAME "Fractol"

# include "fractol_common.h"
# include "hookmgr.h"

int		init_scene(t_mlx *mlx_data);
void	register_events(t_mlx *mlx_data);
void	wait_for_events(t_mlx *mlx_data);
void	destroy_scene(t_mlx *mlx_data);

#endif