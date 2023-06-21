/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_common.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:26:36 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/21 13:13:48 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COMMONS_H

# define MLX_COMMONS_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

#endif