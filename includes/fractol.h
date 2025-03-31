/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:38:52 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/31 17:37:03 by jegerman         ###   ########.fr       */
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

# define ZOOM_LVL 1.05
# define ZOOM_IN 1
# define ZOOM_OUT 0

# define BYTE_FROM_BIT 8
# define BIG_ENDIAN 1
# define LIL_ENDIAN 0

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

typedef struct s_ijk
{
	long	i;
	long	j;
	long	k;
}	t_ijk;

typedef struct s_cli
{
	int		ftype;
	double 	creal;
	double	cimag;
}	t_cli;

typedef struct s_pln
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_pln;

typedef struct s_ui
{
	t_cli	cli;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_adr;
	int		img_bpp;
	int		img_end;
	int		img_szl;
	t_pln	pln;
	int		*pals[2];
	int		pals_size;
	int		pals_curr;
}	t_ui;

int		cli_get_args(int argc, char **argv, t_cli *cli);

int		color_palettes_len(int **palettes);
int		color_interpolate(int base_c1, int base_c2, double coeff);
int		color_palettes_build(int cols_per_gr, t_ui *ui);
void	color_palettes_free(int from, int **palettes);

void	ui_events_register(t_ui *ui);
void	ui_loop(t_ui *ui);
int		ui_init(t_ui *ui);
int		ui_destroy(int target, t_ui *ui);

int		image_ui_draw(t_ui *ui);
int		image_init(t_ui *ui);

int		plot_colorize_mlx_coords(double x, double y, t_ui *ui);
void	plot_set_limits(double min, double max, t_pln *pln);
int		plot_set_zoom_lvl(int zoom_in, t_pln *pln);

int		hook_key_event_manage(int keycode, t_ui *ui);
int		hook_mouse_event_manage(int button, int x, int y, t_pln *pln);
int		hook_loop_event_manage(t_ui *ui);

#endif
