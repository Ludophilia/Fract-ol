/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_common.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:32:30 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/18 17:04:19 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COMMON_H

# define FRACTOL_COMMON_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <math.h>
# include <complex.h>

# define WINDOW_X 1500
# define WINDOW_Y 1500

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

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img_con;
	t_inp	usr_inp;
	int		**palettes;
}	t_mlx;

#endif