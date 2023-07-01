/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:10:23 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/01 22:45:56 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKMGR_H

# define HOOKMGR_H

# include <X11/keysym.h>
# include <X11/keysymdef.h>

# include "fractol_common.h"

int	manage_key_events(int keycode, t_mlx *mlx_data);

#endif