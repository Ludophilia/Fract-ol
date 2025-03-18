/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:38:52 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/18 17:54:04 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <math.h>
# include <complex.h>

# define SCENENAME "Fractol"

# define WINDOW_X 1150
# define WINDOW_Y 1150
# define MANDELBROT 0
# define JULIA 1
# define RADIUS 2
# define MAX_ITER 200.00
# define ZOOM_LEVEL 1.05

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		szl;
	int		end;
}	t_img;

typedef struct s_inp
{
	int32_t	fract;
	double	zcons[2];
}	t_inp;

typedef struct s_pal
{
	int		**palettes;
	int		size;
	int		current;
}	t_pal;

typedef struct s_pln
{
	double	x_lim[2];
	double	y_lim[2];
}	t_pln;

typedef struct s_fra
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img_con;
	t_inp	usr_inp;
	t_pal	pal_con;
	t_pln	com_pln;
}	t_fra;


int		hook_key_events_manage(int keycode, t_fra *fra_data);
int		hook_mouse_events_manage(int button, int x, int y, t_fra *fra_data);
int		hook_loop_events_manage(t_fra *fra_data);

int		cli_args_get(int argc, char **argv, t_fra *fra_data);

int		color_interpolate(int color1, int color2, double coeff);
int		color_palettes_load(int colors_per_gradient, t_fra *fra_data);
void	color_palettes_free(int **palettes, int from);

int		image_init(t_fra *fra_data);
int		image_draw(t_fra *fra_data);

int		plot_colorize_mlx_coords(double x, double y, t_fra *fra_data);
void	plot_set_complex_plane_limits(double min, double max, t_pln *com_pln);
void	plot_change_comp_plane_zoom_level(int zoom_in, t_pln *com_pln);

int		scene_init(t_fra *fra_data);
void	scene_events_register(t_fra *fra_data);
void	scene_events_wait(t_fra *fra_data);
void	scene_destroy(t_fra *fra_data);

#endif
