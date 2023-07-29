/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:10:23 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/28 13:46:10 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKMGR_BONUS_H

# define HOOKMGR_BONUS_H

# include <X11/keysym.h>
# include <X11/keysymdef.h>

# include "imgmgr_bonus.h"
# include "viewmgr_bonus.h"
# include "colormgr_bonus.h"
# include "fractol_common_bonus.h"

int	hook_key_events_manage(int keycode, t_fra *fra_data);
int	hook_mouse_events_manage(int button, int x, int y, t_fra *fra_data);
int	hook_loop_events_manage(t_fra *fra_data);

#endif