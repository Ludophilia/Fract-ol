/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:38:52 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/28 16:43:47 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H

# define FRACTOL_BONUS_H

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

# define SCENENAME "Fractol bonus"

# define WINDOW_X 1150
# define WINDOW_Y 1150

# define RADIUS 2
# define MAX_ITER 150.00

# define SHIFT_FACTOR 0.05
# define SHIFT_LEFT 0x10
# define SHIFT_RIGHT 0x20
# define SHIFT_UP 0x30
# define SHIFT_DOWN 0x40

# define PALETTE_SIZE 4

# define MANDELBROT 0
# define JULIA 1
# define SHIP 2

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
	int	fract;
	double	zcons[2];
	char	*zconsrw[2];
}	t_inp;

typedef struct s_pal
{
	int		**palettes;
	int		size;
	uchar	current;
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
}	t_core;

int		cli_get_args(int argc, char **argv, t_core *core);

int		color_interpolate(int color1, int color2, double coeff);
int		color_palettes_build(int colors_per_gradient, t_core *core);
void	color_palettes_free(int **palettes, int from);
int		color_palettes_check(int **palettes, t_core *core);
void	color_palettes_shift(int straight, t_pal *palette);

int		hook_key_events_manage(int keycode, t_core *core);
int		hook_mouse_events_manage(int button, int x, int y, t_core *core);
int		hook_loop_events_manage(t_core *core);

int		image_init(t_core *core);
int		image_draw(t_core *core);

int		plot_colorize_mlx_coords(double x, double y, t_core *core);

int		scene_init(t_core *core);
void	scene_events_register(t_core *core);
void	scene_events_wait(t_core *core);
void	scene_destroy(t_core *core);

void	view_translate_mlx_coords_to_comp_coords(double *x, double *y,
		t_pln *com_pln);
void	view_set_complex_plane_limits(double min, double max, t_pln *com_pln);
void	view_change_comp_plane_zoom_level(int zoom_in, double x, double y,
		t_pln *com_pln);
void	view_shit_comp_plane(uchar shift_direction, t_pln *com_pln);

#endif
