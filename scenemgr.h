/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenemgr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:47 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/02 18:04:53 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENEMGR_H

# define SCENEMGR_H

# define SCENENAME "Fractol"

# include "fractol_common.h"
# include "hookmgr.h"

int		init_scene(t_mlx *mlx_data);
void	register_events(t_mlx *mlx_data);
void	wait_for_events(t_mlx *mlx_data);
void	destroy_scene(t_mlx *mlx_data);

#endif