/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:10:23 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/20 18:20:20 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKMGR_H

# define HOOKMGR_H

# include <X11/keysym.h>
# include <X11/keysymdef.h>

# include "fractol_common.h"

int	hook_key_events_manage(int keycode, t_fra *mlx_data);

#endif