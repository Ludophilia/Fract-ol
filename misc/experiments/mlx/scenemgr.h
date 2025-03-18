/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenemgr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:47 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/22 19:35:21 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENEMGR_H

# define SCENEMGR_H

# define WINDOW_X 640
# define WINDOW_Y 480
# define BACK_COLOR 0x000000 //0xf57f03
# define SCENENAME "Not MacPaint"

# include <unistd.h>

# include "mlx_common.h"
# include "hookmgr.h"

int		init_scene(t_mlx *mlx_data);
void	register_events(t_mlx *mlx_data);
void	draw_on_scene(t_mlx *mlx_data);
void	wait_for_events(t_mlx *mlx_data);
void	destroy_scene(t_mlx *mlx_data);

typedef struct s_mtx
{
	int	x;
	int	y;
}	t_mtx;

#endif