/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:38:52 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/29 19:24:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>

# include <stdlib.h>
# include <math.h>
# include <complex.h>

# define WIN_NAME "Fractol"
# define WIN_X 1150
# define WIN_Y 1150

# define ERR_USAGE "usage: fractol (0 | 1 <const_real> <const_imag>)\n"

# define MANDELBROT 0
# define JULIA 1
# define RADIUS 2
# define MAX_ITER 200.00
# define ZOOM_LEVEL 1.05

typedef enum e_tgt
{
	TG_MLX = (1 << 0),
	TG_DIS = (1 << 4),
	TG_PALS = (1 << 1),
	TG_IMG = (1 << 2),
	TG_WIN = (1 << 3),
	TG_ALL = TG_MLX | TG_PALS | TG_IMG | TG_WIN | TG_DIS,
}	t_tgt;

typedef struct s_rgb
{
	unsigned  r;
	unsigned  g;
	unsigned  b;
}	t_rgb;

typedef struct s_fpn
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

typedef struct s_cli
{
	int		ftype;
	double 	creal;
	double	cimag;
}	t_cli;

typedef struct s_pln
{
	double	x_min; //double	x_lim[2];
	double	x_max;
	double	y_min;
	double	y_max;
}	t_pln;

typedef struct s_ui
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_adr;
	int		img_bpp;
	int		img_end;
	int		img_szl;
	int		*pals[2];
	int		pals_size;
	int		pals_curr;
}	t_ui;

typedef struct s_core
{
	t_ui	ui;
	t_pln	pln;
	t_cli	cli;
}	t_core;

int		hook_key_events_manage(int keycode, t_core *core);
int		hook_mouse_events_manage(int button, int x, int y, t_core *core);
int		hook_loop_events_manage(t_core *core);

int		cli_get_args(int argc, char **argv, t_core *core);

int		color_interpolate(int base_c1, int base_c2, double coeff);
int		color_palettes_build(int cols_per_gr, t_core *core);
void	color_palettes_free(int from, int **palettes);

int		image_init(t_core *core);
int		image_draw(t_core *core);

int		plot_colorize_mlx_coords(double x, double y, t_core *core);
void	plot_set_complex_plane_limits(double min, double max, t_pln *com_pln);
void	plot_change_zoom_level(int zoom_in, t_pln *com_pln);

void	ui_events_register(t_core *core);
void	ui_loop(t_core *core);
int		ui_init(t_core *core);
int		ui_destroy(int target, t_core *core);

#endif
