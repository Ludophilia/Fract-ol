/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_common_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:32:30 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/26 15:46:26 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COMMON_BONUS_H

# define FRACTOL_COMMON_BONUS_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include <X11/X.h>
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

# define MANDELBROT 0
# define JULIA 1

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
	char	*zconsrw[2];
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

#endif