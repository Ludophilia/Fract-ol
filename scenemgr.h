/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenemgr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:08:47 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/20 18:27:17 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENEMGR_H

# define SCENEMGR_H

# define SCENENAME "Fractol"

# include "fractol_common.h"
# include "hookmgr.h"
# include "colormgr.h"

int		scene_init(t_fra *fra_data);
void	scene_events_register(t_fra *fra_data);
void	scene_events_wait(t_fra *fra_data);
void	scene_destroy(t_fra *fra_data);

#endif