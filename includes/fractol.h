/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:38:52 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/18 22:09:36 by jegerman         ###   ########.fr       */
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

# define PI * 3.14159

# define WIN_NAME "fractol"
# define WIN_X 1000
# define WIN_Y 1000

# define ERR_USAGE "usage: fractol (0 | 1 <const_real> <const_imag>)\n"

# define MANDEL 0
# define JULIA 1
# define RADIUS 2

# define MAN_ITMX 125.00
# define JUL_ITMX 150.00

# define ZOOM_LVL 1.05
# define ZOOM_IN 1
# define ZOOM_OUT 0

# define BYTE 8
# define BIG_END 1
# define LIT_END 0

typedef enum e_tgt
{
	TG_MLX = (1 << 0),
	TG_IMG = (1 << 1),
	TG_WIN = (1 << 2),
	TG_DIS = (1 << 3),
	TG_ALL = TG_MLX | TG_IMG | TG_WIN | TG_DIS,
}	t_tgt;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
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

typedef struct s_fra
{
	int		ftype;
	double	creal;
	double	cimag;
	double	max_iter;
	double	off_col;
}	t_fra;

typedef struct s_pnt
{
	double	x;
	double	y;
}	t_pnt;

typedef struct s_pln
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_pln;

typedef struct s_ui
{
	t_fra	fra;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_adr;
	int		img_bpp;
	int		img_end;
	int		img_szl;
	t_pln	pln;
}	t_ui;

int		cli_get_args(int argc, char **argv, t_fra *fra);

void	ui_loop(t_ui *ui);
int		ui_init(t_ui *ui);
int		ui_destroy(int target, t_ui *ui);

int		image_ui_draw(t_ui *ui);
int		image_init(t_ui *ui);

double	plot_does_seq_escape(double complex z, double *iter);
t_pnt	plot_get_cmplx_coords(t_pnt *pt, t_pln *pln);
double	plot_get_max_iter(t_pnt *cpt, t_fra *fra);

void	view_chg_zoom_lvl(int zoom_in, t_pln *pln);
int		view_colorize_coords(t_pnt *pt, t_ui *ui);

int		hook_key_event_manage(int keycode, t_ui *ui);
int		hook_mouse_event_manage(int button, int x, int y, t_pln *pln);
int		hook_loop_event_manage(t_ui *ui);

#endif
