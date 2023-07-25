/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenemgr_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:47 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/25 17:53:22 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENEMGR_BONUS_H

# define SCENEMGR_BONUS_H

# include "fractol_common_bonus.h"
# include "hookmgr_bonus.h"
# include "colormgr_bonus.h"

int		scene_init(t_fra *fra_data);
void	scene_events_register(t_fra *fra_data);
void	scene_events_wait(t_fra *fra_data);
void	scene_destroy(t_fra *fra_data);

#endif
