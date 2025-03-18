/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_common.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:26:36 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/23 14:14:43 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COMMONS_H

# define MLX_COMMONS_H

# include "mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		loopcount;
}	t_mlx;

#endif