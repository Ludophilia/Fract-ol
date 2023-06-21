/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenemgr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:47 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/21 13:50:17 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENEMGR_H

# define SCENEMGR_H

# include <unistd.h>

# include "mlx_common.h"
# include "hooks.h"

int		init_scene(t_mlx *mlx_data);
void	destroy_scene(t_mlx *mlx_data);
void	register_events(t_mlx *mlx_data);
void	wait_for_events(t_mlx *mlx_data);

#endif