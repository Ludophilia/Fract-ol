/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:10:23 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/21 21:42:29 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKMGR_H

# define HOOKMGR_H

# include <X11/keysym.h>
# include <X11/keysymdef.h>

# include "imgmgr.h"
# include "fractol_common.h"

int	hook_key_events_manage(int keycode, t_fra *fra_data);
int	hook_mouse_events_manage(int button, int x, int y, t_fra *fra_data);
int	hook_loop_events_manage(t_fra *fra_data);

#endif