/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_common.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:26:36 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/20 13:32:55 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COMMONS_H

# define MLX_COMMONS_H

# include "mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <unistd.h>

# define WINDOW_X 640
# define WINDOW_Y 480
# define BACK_COLOR 0x000000 //0xf57f03
# define SCENENAME "Not MacPaint"

# define ESC_KEY 65307 
# define FORE_COLOR 0xffffff

typedef struct s_mtx
{
	int	x;
	int	y;
}	t_mtx;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		loopcount;
}	t_mlx;


int		init_scene(t_mlx *mlx_data);
void	register_events(t_mlx *mlx_data);
void	draw_on_scene(t_mlx *mlx_data);
void	wait_for_events(t_mlx *mlx_data);
void	destroy_scene(t_mlx *mlx_data);

int		test_mouse_hook(int button, int x, int y, void *params);
int		test_key_hook(int keycode, void *params);
int		test_loop_hook(t_mlx *mlx_data);
int		test_destroy_hook(void *params);
// int		test_hook(void);
// int		test_hook(int data);
int		test_motion_hook(int x, int y, t_mlx *mlx_data);
int		test_expose_hook(void);

#endif