/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:38:52 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/29 14:16:37 by jegerman         ###   ########.fr       */
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

# define ERR_USAGE "usage: fractol (0 | 1 <const_real> <const_imag>)\n"
# define ERR_MLX_INIT "Something went wrong while initializing MiniLibX.\n" 

# define WINDOW_X 1150
# define WINDOW_Y 1150
# define MANDELBROT 0
# define JULIA 1
# define RADIUS 2
# define MAX_ITER 200.00
# define ZOOM_LEVEL 1.05

// typedef struct s_lim
// {
// 	double	min;
// 	double 	max;
// }	t_lim;

// typedef struct s_pal
// {
// 	int		**pals; // palettes
// 	int		size;
// 	int		curr; //  current
// }	t_pal;

typedef struct s_rgb
{
	unsigned  r;
	unsigned  g;
	unsigned  b;
}	t_rgb;

typedef struct s_fpnb
{
	int		sign;
	double	mant;
	double	exp;
}	t_fpn;

typedef struct s_cnt
{
	long	i;
	long	j;
	long	k;
}	t_cnt;

typedef struct s_cli // s_inp
{
	// double	zcons[2];
	int		ftype;
	double 	creal;
	double	cimag;
}	t_cli; // t_inp

typedef struct s_pln
{
	//double	x_lim[2];
	// double	y_lim[2];
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_pln;

typedef struct s_ui // s_img
{
	void	*mlx_api; // mlx_ptr
	void	*win_api; // win_ptr
	void	*img_api; // img_ptr
	char	*img_addr; // addr
	int		img_bpp; // bpp
	int		img_end; // end
	int		img_szl; // szl
	int		*pal_arr[2];
	int		pal_size;
	int		pal_curr;
	// t_pal	pal_con;
}	t_ui; //t_img;


typedef struct s_core //s_fra
{
	t_ui	win;
	t_pln	plan;
	t_cli	cli;
	// void		*mlx_ptr;
	// void		*win_ptr;
	// t_pal	pal_con;
	// t_img	img_con;
	// t_pln	com_pln;
	// t_inp	usr_inp;
}	t_core;


int		hook_key_events_manage(int keycode, t_core *core);
int		hook_mouse_events_manage(int button, int x, int y, t_core *core);
int		hook_loop_events_manage(t_core *core);

int		cli_get_args(int argc, char **argv, t_core *core);

int		color_interpolate(int base_c1, int base_c2, double coeff);
int		color_palettes_build(int cols_per_gr, t_core *core);
void	color_palettes_free(int **palettes, int from);

int		image_init(t_core *core);
int		image_draw(t_core *core);

int		plot_colorize_mlx_coords(double x, double y, t_core *core);
void	plot_set_complex_plane_limits(double min, double max, t_pln *com_pln);
void	plot_change_comp_plane_zoom_level(int zoom_in, t_pln *com_pln);

int		scene_init(t_core *core);
void	scene_events_register(t_core *core);
void	scene_events_wait(t_core *core);
void	scene_destroy(t_core *core);

#endif
