/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_common.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:32:30 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/05 20:47:18 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COMMON_H

# define FRACTOL_COMMON_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <stdlib.h>
# include <stdint.h>
# include <complex.h>

# define WINDOW_X 640
# define WINDOW_Y 480

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		szl;
	int		end;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img_con;
}	t_mlx;

#endif